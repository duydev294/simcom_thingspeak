#ifndef THINGSPEAK_H
#define THINGSPEAK_h
#include<Arduino.h>
#include"AT_Command.h"
#include<string.h>
#include<Stream.h>

class Thingspeak: public ATcommands{
    public:
    Thingspeak(char *APIkey,char * field,Stream *port);
    bool Begin();
    bool send_Data(const char *data, int retry);
    bool connect_server();
    private:
    char * API_key;
    char* Field;
};
#endif