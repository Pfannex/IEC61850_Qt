#pragma once
#include <string>
using namespace std;



class IEC61850_Client {

public:
	int connect_to_server(string ip, int port);
	void close();
	bool control_switch(string path, bool cmd);
	string read_state(string state);
};