#include <iec61850_control.h>

int IEC61850_Client::connect_to_server(string ip, int port) {

    con = IedConnection_create();
    IedConnection_connect(con, &error, ip.c_str(), port);

    IedConnection_destroy(con);
	return error;
}

void IEC61850_Client::close() {
    IedConnection_close(con);
    IedConnection_destroy(con);
}

bool IEC61850_Client::control_switch(string path, bool cmd) {
    /****************************************
     * Direct control with enhanced security
     ****************************************/
    ControlObjectClient control = ControlObjectClient_create("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos", con);
    //ControlObjectClient_setOrigin(control, NULL, 3);

    //ControlObjectClient_setCommandTerminationHandler(control, commandTerminationHandler, NULL);

    //MmsValue* ctlVal = MmsValue_newBoolean(cmd);

    //bool ret = false;
    //if (ControlObjectClient_operate(control, ctlVal, 0 /* operate now */)) {
    //    ret = true;
    //}
 
    //MmsValue_delete(ctlVal);

    /* Wait for command termination message */
    //Thread_sleep(1000);

    //ControlObjectClient_destroy(control);

	return true;
}

string IEC61850_Client::read_state(string path) {

    string state[4] = { "10", "2", "30", "44"};

    MmsValue* stVal = IedConnection_readObject(con, &error, path.c_str(), IEC61850_FC_ST);

    if (error == IED_ERROR_OK) {
        int status = MmsValue_getBitStringAsInteger(stVal);

        return state[status];

        MmsValue_delete(stVal);
    }
    else {
        return "faliled";
    }
    
    return "banane";
}
