#include"thingspeak.h"
Thingspeak::Thingspeak(char *APIkey,char* field,Stream *port):ATcommands(port){
    API_key = (char *)malloc(sizeof(40 *sizeof(char)));
    Field = (char *)malloc(sizeof(40 *sizeof(char)));
    strcpy(API_key,APIkey);
    strcpy(Field,field);
}

bool Thingspeak::connect_server(){
    
    if(sendATCommand("AT\r\n","OK")){
        Serial.print("Connectede SIM900A");
    }else {
        Serial.println("Error on connect SIM 900A");
        return false;
    }
    if(sendATCommand("AT+CIPSHUT\r\n","OK")){
        Serial.print("Disconected server");
    }else {
        Serial.println("Error on disconected sevrer");
        return false;
    }
    if(sendATCommand("+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"","CONNECT OK",2000)){
        Serial.println("Connected to ThingSpeak");
    }else{
        Serial.println("Error on connect to server");
        return false ;
    }
    return false;
}
bool Thingspeak::Begin(){
     if(sendATCommand("AT\r\n","OK")){
        Serial.print("Connectede SIM900A");
    }else {
        Serial.println("Error on connect SIM 900A");
        return false;
    }
    
}
bool Thingspeak::send_Data(const char *data,int retry = 1){

    char  CMD[] = "GET /update?api_key=CO49DGYWAXVM16OA&";
    strcat(CMD,Field);
    strcat(CMD, "=" );
    strcat(CMD,data);
    strcat(CMD, "HTTP/1.1\r\nHost: api.thingspeak.com\r\n\r\n\x1A");
    while(retry >0){
        if(connect_server()){
            char send_ok[] = "SEND OK";
            if(sendATCommand(CMD,send_ok,2000))
            break;
        }
        retry --;
    }
   
} 
