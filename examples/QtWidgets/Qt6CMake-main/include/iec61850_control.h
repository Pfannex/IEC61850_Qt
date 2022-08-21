#pragma once
#include <string>
using namespace std;

#include "iec61850_client.h"
#include "hal_thread.h"

#include <stdlib.h>
#include <stdio.h>

#include <functional>
typedef std::function<void(string&)> String_CallbackFunction;
String_CallbackFunction on_wifi_scan_result;


class IEC61850_Client {
public:

	IedClientError error;
	IedConnection con;

	int connect_to_server(string ip, int port);
	bool is_connected = false;
	void close();
	bool control_switch(string path, bool cmd, int wait);
	static void commandTerminationHandler(void* parameter, ControlObjectClient connection);
	string read_state(string state);
};

void cmd_ter_callback(string addCause);
