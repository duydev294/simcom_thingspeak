#include"AT_Command.h"
ATcommands::ATcommands(Stream *port){
     mySerial = port;
}
bool compare(const char *receidata, const char *reply){
    for(int i = 0; i< sizeof(receidata)/sizeof(char)-sizeof(reply)/sizeof(char)+1; i ++){
        for(int j = 0; j < sizeof(reply)/sizeof(char); j ++){
            if(receidata[i+j] != reply[j]) break;
            if(j == sizeof(reply)/sizeof(reply)-1) return true;
        }
        return false;
    } 
}
bool ATcommands::sendATCommand(char *commands, uint16_t timeout = default_timeout){
    while(mySerial->available()) mySerial->read();
    mySerial->print(commands);
    unsigned long timer = millis();
    bool got_reply = false;
    while(!got_reply&&millis() -timer < timeout){
        if(mySerial->available()) got_reply = true;
    }
    if(got_reply) return true;
    else return false;
}


bool ATcommands::sendATCommand(char *commands,char *reply,uint16_t timeout = default_timeout){
    while(mySerial->available()) mySerial->read();
    mySerial->print(commands);
    uint8_t idx = 0;
    bool replyMatch = false;

    unsigned long timer = millis();
    
    
    while(!replyMatch && millis() -timer < timeout){
        if(mySerial->available()) {
            replyBuffer[idx] = mySerial->read();
            Serial.println(replyBuffer[idx]);
            idx++;
           
        }
         if(compare(replyBuffer,reply) == 0) replyMatch = true;
    }
    if(replyMatch) return true;
    else return false;
}
