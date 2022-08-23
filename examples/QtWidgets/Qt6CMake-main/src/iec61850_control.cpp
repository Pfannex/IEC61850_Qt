#include <iec61850_control.h>


void Callback::set_callback(String_CallbackFunction cmd_ter_callback) {
    on_cmd_ter_callback = cmd_ter_callback;
}
void Callback::newLine(string line) {
    if (on_cmd_ter_callback != nullptr)
        on_cmd_ter_callback(line);
}

//---------------------------------------------------------------

int IEC61850_Client::connect_to_server(string ip, int port) {

 
    con = IedConnection_create();
    IedConnection_connect(con, &error, ip.c_str(), port);

    if (error == IED_ERROR_OK) is_connected = true;
	return error;
}

void IEC61850_Client::close() {
    IedConnection_close(con);
    IedConnection_destroy(con);
    is_connected = false;
}


void IEC61850_Client::commandTerminationHandler(void* parameter, ControlObjectClient connection){
    //if (parameter != nullptr)
    Callback* log = (Callback*)parameter;
    log->newLine("CommandTermination");

    LastApplError lastApplError = ControlObjectClient_getLastApplError(connection);
    /* if lastApplError.error != 0 this indicates a CommandTermination- */
    if (lastApplError.error != 0) {
        log->newLine("BF--");
        log->newLine("Error");
        log->newLine("addCause");
        //printf("Received CommandTermination-.\n");
        //printf(" LastApplError: %i\n", lastApplError.error);
        //printf("      addCause: %i\n", lastApplError.addCause);
    }
    else
        log->newLine("BF++");
        //printf("Received CommandTermination+.\n");
}

bool IEC61850_Client::control_switch(string path, bool cmd, int wait) {
    bool ret = false;
    if (is_connected) {

        control = ControlObjectClient_create(path.c_str(), con);

        ControlObjectClient_setCommandTerminationHandler(control, commandTerminationHandler, &cb);

        MmsValue* ctlVal = MmsValue_newBoolean(cmd);

        ControlObjectClient_setOrigin(control, NULL, 3);

        if (ControlObjectClient_operate(control, ctlVal, 0 /* operate now */)) {
            ret = true;
        }
        MmsValue_delete(ctlVal);
        /* Wait for command termination message */
        Thread_sleep(wait);

        ControlObjectClient_destroy(control);
    }
    return ret;
}

string IEC61850_Client::read_state(string path) {
    if (is_connected) {
        string retState[5] = { "intermediate-state", "on", "off", "bad-state", "Reading status failed!" };
        int state = 4;

        MmsValue* stVal = IedConnection_readObject(con, &error, path.c_str(), IEC61850_FC_ST);

        if (error == IED_ERROR_OK) {
            state = MmsValue_getBitStringAsInteger(stVal);
            MmsValue_delete(stVal);
        }
        return retState[state];
    }
    else {
        return "not connected to server";
    }
}
