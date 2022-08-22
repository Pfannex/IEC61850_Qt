#pragma once
#include <string>
using namespace std;

#include "iec61850_client.h"
#include "hal_thread.h"

#include <stdlib.h>
#include <stdio.h>

#include <functional>
typedef std::function<void(string&)> String_CallbackFunction;

class Callback {
public:
	void set_callback(String_CallbackFunction cmd_ter_callback);
	String_CallbackFunction on_cmd_ter_callback;
	void newLine(string line);
};

class IEC61850_Client {
public:

	IedClientError error;
	IedConnection con;
	ControlObjectClient control;
	Callback cb;

	int connect_to_server(string ip, int port);
	bool is_connected = false;
	void close();
	bool control_switch(string path, bool cmd, int wait);
	static void commandTerminationHandler(void* parameter, ControlObjectClient connection);
	string read_state(string state);
};


