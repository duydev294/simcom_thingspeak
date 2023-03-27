#ifndef AT_COMMAND_H
#define AT_COMMAND_H
#include<Arduino.h>
#include <SoftwareSerial.h>
#include<Stream.h>
#define default_timeout 1500

class ATcommands{
    public:
    ATcommands(Stream *port);
    bool sendATCommand(char *command, uint16_t timeout = default_timeout);
    bool sendATCommand(char *command, char * reply,uint16_t timeout = default_timeout);
    private:
    char replyBuffer[225];
    Stream * mySerial;
    
};

#endif