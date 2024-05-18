
SITIPE_prot = Proto("SITIPE",  "SITIPE Master-Slave communication")

-- header fields
local sitipe_fields = {
  type           = ProtoField.string        ("sitipe.type"             , "Type                " ),
  message_type   = ProtoField.string        ("sitipe.message_type"     , "Message Type        " , base.Unicode),
  message_len    = ProtoField.uint64        ("sitipe.message_len"      , "Message Length      " , base.Unicode),
  time_stamp     = ProtoField.absolute_time ("sitipe.time_stamp"       , "TimeStamp           " , base.UTC),

  ts_seconds     = ProtoField.uint64        ("sitipe.ts_seconds"       , "TimeStamp seconds   " ),
  ts_days        = ProtoField.double        ("sitipe.ts_days"          , "TimeStamp days      " ),
  ts_fractInt    = ProtoField.uint64        ("sitipe.ts_fractInt"      , "TimeStamp fractInt  " ),
  ts_fraction    = ProtoField.double        ("sitipe.ts_fraction"      , "TimeStamp fraction  " ),
  ts_days        = ProtoField.double        ("sitipe.ts_days"          , "TimeStamp days      " ),

-- payload fields
  ptm_count      = ProtoField.uint64        ("sitipe.ptm_count"        , "PTMs requested      " ),
  ptm_str_len    = ProtoField.uint64        ("sitipe.ptm_str_len"      , "PTM String Length   " ),
  module_number  = ProtoField.string        ("sitipe.module_number"    , "PTM:                " ),
  response       = ProtoField.string        ("sitipe.response"         , "Slave response      " ),
  ptm_io         = ProtoField.string        ("sitipe.ptm_io"           , "Set Output          " ),
  ptm_io_01_10   = ProtoField.string        ("sitipe.ptm_io_01_10"     , "BO 01 - 10          " ),
  ptm_io_11_20   = ProtoField.string        ("sitipe.ptm_io_11_20"     , "BO 11 - 20          " ),
  ptm_io_21_30   = ProtoField.string        ("sitipe.ptm_io_21_30"     , "BO 21 - 30          " ),
  ptm_io_31_40   = ProtoField.string        ("sitipe.ptm_io_31_40"     , "BO 31 - 40          " ),
  ptm_io_41_48   = ProtoField.string        ("sitipe.ptm_io_41_48"     , "BO 41 - 48          " ),

  master_quit    = ProtoField.string        ("sitipe.master_quit"      , "Master quit reason  " ),
  slave_quit     = ProtoField.string        ("sitipe.slave_quit"       , "Slave quit reason   " ),

  int_time_stamp = ProtoField.int64         ("sitipe.int_time_stamp"   , "Integer TimeStamp   " ), 
  ptm_index      = ProtoField.uint16        ("sitipe.ptm_index"        , "Connectet PTM Index " ), 
  channel_id     = ProtoField.uint64        ("sitipe.channel_id"       , "Channel ID          " ), 
  output_cot     = ProtoField.string        ("sitipe.outputCOT"        , "COT: triggered by   " ), 
  output_value   = ProtoField.string        ("sitipe.output_value"     , "Output value        " ), 
 



  io             = ProtoField.uint8         ("sitipe.io"               , "I/O:          " , base.DEC),
  state          = ProtoField.uint8         ("sitipe.state"            , "state:        " , base.DEC),
  payload        = ProtoField.none          ("sitipe.payload"          , "payload       " , base.HEX)
}

SITIPE_prot.fields =  sitipe_fields

function SITIPE_prot.dissector(buffer, pinfo, tree)
  length = buffer:len()
  if length == 0 then return end

  pinfo.cols.protocol = SITIPE_prot.name
  local subtree = tree:add(SITIPE_prot, buffer(), "SITIPE Master/Slave")
  --local io_tree = subtree:add_le(SITIPE_prot, buffer(20,6) , "change")

  local type_number = buffer(0,2):uint()
  local type = string.format("[%04d]", type_number)
  local type_str = get_type_name(type_number)
  local type_name = type .. " " .. type_str

-- HEADER -----------------------------------------------------------------------------
  -- subtree:add_le(sitipe_fields.message_type,   buffer(0,2)):append_text(" (" .. type_name .. ")")
  subtree:add_le(sitipe_fields.type,         buffer(0,2), type)
  subtree:add_le(sitipe_fields.message_type, buffer(0,2), type_str)
  subtree:add_le(sitipe_fields.message_len,  buffer(2,4), buffer(2,4):uint64())
  ------
  local ts_s = buffer(6,8):uint64()                                  --seconds
  local ts_d = (ts_s:tonumber() /60/60/24)                           --days
  local ts_fractInt = buffer(14,8):uint64()                          --fration of seconds as uint64
  local ts_fract = (ts_fractInt:tonumber() * 2^(-64) * 1000000000 )  --fration in nano seconds  
  local nstime = NSTime.new(ts_s:tonumber() - 2082844800, ts_fract)  -- minus difference from 1970 - 1904
  subtree:add_le(sitipe_fields.time_stamp, buffer(6, 16), nstime)

-- TYPE 0000 --------------------------------------------------------------------------
  if type_name == "[0000] MasterInitRequest" then
    local ptm_count = buffer(22,4):uint64()
    local ptm_tree = subtree:add_le(sitipe_fields.ptm_count, buffer(22, 4), ptm_count)
    
     for i = 0, ptm_count:tonumber()-1 do
        local strLen = buffer(26, 4):uint64()
        ptm_tree:add_le(sitipe_fields.module_number, buffer(30 + i*(4+strLen:tonumber()), 5)):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))   
    end   
  end

-- TYPE 0001 -------------------------------------------------------------------------- set
  if type_name == "[0001] MasterTransmit" then
    local strLen = buffer(36, 4):uint64()
    local ptm_tree = subtree:add_le(sitipe_fields.module_number, buffer(40, 5)):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))

    local integer_time_stamp = (buffer(26, 8):int64())
    ptm_tree:add_le(sitipe_fields.int_time_stamp, buffer(26, 8), integer_time_stamp)
    ptm_tree:add_le(sitipe_fields.ptm_index, buffer(22, 2), buffer(22, 2):uint())
    ptm_tree:add_le(sitipe_fields.channel_id, buffer(24, 2), buffer(24, 2):uint64())
    ptm_tree:add_le(sitipe_fields.output_value, buffer(35, 1), get_value(buffer(35, 1):uint()))

    ptm_tree:add_le(sitipe_fields.output_cot, buffer(34, 1), get_update_status(buffer(34, 1):uint()))
  end

-- TYPE 0002 --------------------------------------------------------------------------
  if type_name == "[0002] MasterKeepAlive" then
  end

-- TYPE 0003 --------------------------------------------------------------------------
  if type_name == "[0003] MasterQuit" then
    subtree:add_le(sitipe_fields.master_quit, buffer(22,2), get_quit_reason("master", buffer(22,2):uint()))
  end

-- TYPE 0004 --------------------------------------------------------------------------
  if type_name == "[0004] SlaveInitResponse" then
    local strResponse = "connection accepted"
    subtree:add_le(sitipe_fields.response, buffer(22,2)):append_text(strResponse)
    if buffer(22,2):uint() > 0 then
      strResponse = "connection refused"
    else
      local ptm_count = buffer(24,4):uint64()
      local ptm_tree = subtree:add_le(sitipe_fields.ptm_count, buffer(24, 4), ptm_count)
      
       for i = 0, ptm_count:tonumber()-1 do
          local strLen = buffer(28, 4):uint64()
          ptm_tree:add_le(sitipe_fields.module_number, buffer(32 + i*(4+strLen:tonumber()), 5)):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))   
      end   
    end  
  end

-- TYPE 0005 --------------------------------------------------------------------------
  if type_name == "[0005] SlaveKeepAlive" then
  end

-- TYPE 0006 --------------------------------------------------------------------------
  if type_name == "[0006] SlavePTMstatus" then
  end

-- TYPE 0007 -------------------------------------------------------------------------- response
  if type_name == "[0007] SlaveTransmit" then
    local strLen = buffer(36, 4):uint64()
    local ptm_tree = subtree:add_le(sitipe_fields.module_number, buffer(40, 5)):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))

    local integer_time_stamp = (buffer(26, 8):int64())
    ptm_tree:add_le(sitipe_fields.int_time_stamp, buffer(26, 8), integer_time_stamp)
     ptm_tree:add_le(sitipe_fields.ptm_index, buffer(22, 2), buffer(22, 2):uint())
    ptm_tree:add_le(sitipe_fields.channel_id, buffer(24, 2), buffer(24, 2):uint64())
    ptm_tree:add_le(sitipe_fields.output_value, buffer(35, 1), get_value(buffer(35, 1):uint()))

    ptm_tree:add_le(sitipe_fields.output_cot, buffer(34, 1), get_update_status(buffer(34, 1):uint()))
  end

-- TYPE 0008 --------------------------------------------------------------------------
  if type_name == "[0008] SlaveQuit" then
    subtree:add_le(sitipe_fields.slave_quit, buffer(22,2), get_quit_reason("slave", buffer(22,2):uint()))
  end

-- TYPE 0009 --------------------------------------------------------------------------
  if type_name == "[0009] SlaveAcceptedPTMUpdate" then
  end

-- TYPE 0010 --------------------------------------------------------------------------
  if type_name == "[0010] MasterOutputs" then
    local strLen = buffer(22, 4):uint64()
    local ptm_tree = subtree:add_le(sitipe_fields.module_number, buffer(26, 5)):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))
    
    strLen = buffer(31, 4):uint64()
    ptm_tree:add_le(sitipe_fields.ptm_io, buffer(35, 48), "set binary output"):append_text(string.format("   (strLen:  %d)", strLen:tonumber()))

    ptm_tree:add_le(sitipe_fields.ptm_io_01_10, buffer(35, 10), str_io(buffer(35, 10)))
    ptm_tree:add_le(sitipe_fields.ptm_io_11_20, buffer(45, 10), str_io(buffer(45, 10)))
    ptm_tree:add_le(sitipe_fields.ptm_io_21_30, buffer(55, 10), str_io(buffer(55, 10)))
    ptm_tree:add_le(sitipe_fields.ptm_io_31_40, buffer(65, 10), str_io(buffer(65, 10)))
    ptm_tree:add_le(sitipe_fields.ptm_io_41_48, buffer(75, 8),  str_io(buffer(75, 8)))


  end

-- FOOTER -----------------------------------------------------------------------------
  --subtree:add_le(sitipe_fields.payload,          buffer(2,length-2))
 

end

local tcp_port = DissectorTable.get("tcp.port")
tcp_port:add(23000, SITIPE_prot)

-- get type of communication frame ----------------------------------------------------
function get_type_name(type_number)
  local type_name = "Unknown"

      if type_number ==  0 then type_name = "MasterInitRequest"
  elseif type_number ==  1 then type_name = "MasterTransmit"
  elseif type_number ==  2 then type_name = "MasterKeepAlive"
  elseif type_number ==  3 then type_name = "MasterQuit"
  elseif type_number ==  4 then type_name = "SlaveInitResponse"
  elseif type_number ==  5 then type_name = "SlaveKeepAlive"
  elseif type_number ==  6 then type_name = "SlavePTMstatus"
  elseif type_number ==  7 then type_name = "SlaveTransmit"
  elseif type_number ==  8 then type_name = "SlaveQuit"
  elseif type_number ==  9 then type_name = "laveAcceptedPTMUpdate" 
  elseif type_number == 10 then type_name = "MasterOutputs" 
  end

  return type_name
end

-- get quit reason ----------------------------------------------------
function get_quit_reason(master_slave, byte_reason)
  local reason = "Unknown"

  if master_slave == "master" then
    if byte_reason == 0 then reason = "Master Stopped"
    elseif byte_reason == 1 then reason = "Master Restart" 
    end  

  elseif master_slave == "slave" then
    if byte_reason == 0 then reason = "No Response"
    elseif byte_reason == 1 then reason = "Slave Stopped" 
    elseif byte_reason == 2 then reason = "Master Refused" 
    elseif byte_reason == 3 then reason = "Master Timeout" 
    elseif byte_reason == 4 then reason = "Master Quit" 
    elseif byte_reason == 5 then reason = "Generic TCP Error"  
    end       
  end

  return reason
end

-- get update status ----------------------------------------------------
function get_update_status(byte_status)
  local status = "Unknown"

  if byte_status == 0 then status = "input" end
  if byte_status == 1 then status = "output" end

  return status
end
-- get value setting ----------------------------------------------------
function get_value(byte_value)
  local value = "Unknown"

  if byte_value == 0 then value = "OFF" end
  if byte_value == 1 then value = "ON" end

  return value
end

-- number to binary string ------------------------------------------------------------
function numberToBinStr(byte_number)
  ret = ""
  for i = 0,7,1 do
    ret = tostring(byte_number:bitfield(i,1))..ret
  end
  ret = " - "..ret
  return ret  
end  

-- set binary output string ------------------------------------------------------------
function str_io(io_bytes)
  local count = io_bytes:len()
  ret = ""

  for i = 0, count-1, 1 do
    if io_bytes(i, 1):uint() == 0 then
      ret = ret.."-"
    else
      ret = ret.."X"
    end
    if i == 4 then ret = ret.." " end
  end
  return ret  
end  



--------------------
