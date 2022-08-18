#include <iec61850_control.h>

int IEC61850_Client::connect_to_server(string ip, int port) {
	return 0;
}

void IEC61850_Client::close() {
	
}

bool IEC61850_Client::control_switch(string path, bool cmd) {
	return true;
}

string IEC61850_Client::read_state(string state) {
	return "banane";
}
