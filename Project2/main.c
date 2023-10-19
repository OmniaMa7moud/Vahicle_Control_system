#include <stdio.h>
#include <stdlib.h>

#define ON 1
#define OFF 0

int option = 0;
int option1 = 0;

char trafficLightColor = 0;
int roomTemp;
int enginTemp;

struct vcl{

    int speed;
    int AC;
    int enginTempController;
}vehicle;


void stateChanges()
{
    vehicle.AC = OFF;
    roomTemp *= ((5/4)+1);

    vehicle.enginTempController = ON;
    enginTemp *= ((5/4)+1);

    return;
}

void setTrafficLightColor()
{
    printf("Please Enter Traffic Light Color:%d",trafficLightColor);
    scanf("%d",&trafficLightColor);
    if(trafficLightColor == 'G') {vehicle.speed = 100;}
    else if(trafficLightColor == 'O') {vehicle.speed = 30; stateChanges();}
    else if(trafficLightColor == 'R') {vehicle.speed = 0;}
    return;
}


void setRoomTemp()
{
    printf("Please Enter Room Temp:%d",roomTemp);
    scanf("%d",&roomTemp);
    if(roomTemp < 10) {vehicle.AC = ON; roomTemp = 20;}
    else if(roomTemp > 30) {vehicle.AC = ON; roomTemp = 20;}
    else {vehicle.AC = OFF;}
    return;
}


void setEnginTemp()
{
    printf("Please Enter Engine Temp:%d",enginTemp);
    scanf("%d",&enginTemp);
    if(enginTemp < 100) {vehicle.enginTempController = ON; enginTemp = 125;}
    else if(enginTemp > 150) {vehicle.enginTempController = ON; enginTemp = 125;}
    else {vehicle.enginTempController = OFF;}
    return;
}

void turnOnVehicleEngine()
{
     while(option1 != 1)
    {
    displaySystemState();
    printf("\n\nChoose Your Option:\n1-Turn off the engine.\n2-Set the traffic light color.\n3-Set the room temperature.\n4- Set the engine temperature.\n");
    fflush(stdin);
    scanf("%d", &option1);
    fflush(stdin);
        if(option1 == 1) {option1 = 0; return;}
        else if(option1 == 2) {option1 = 0; setTrafficLightColor();}
        else if(option1 == 3) {option1 = 0; setRoomTemp();}
        else if(option1 == 4) {option1 = 0; setEnginTemp();}
        else {printf("Not A correct Option.\n"); option1=0;}
        }

}


void  displaySystemState()
{
    printf("\n\nVehicle State:\n");
    if(trafficLightColor == 'G') {printf("Traffic Light Color is Green.\n");}
    else if(trafficLightColor == 'O') {printf("Traffic Light Color is Orange.\n");}
    else if(trafficLightColor == 'R') {printf("Traffic Light Color is Red.\n");}
    if(vehicle.AC == 1) {printf("AC is ON.\n");}
    else if(vehicle.AC == 0) {printf("AC is OFF.\n");}
    printf("Vehicle Speed is %d.\n", vehicle.speed);
    printf("Room Temp is %d.\n", roomTemp);
    printf("Engine Temp Controller State is %d.\n", vehicle.enginTempController);
    printf("Engine Temp is %d.\n", enginTemp);
}


int main()
{

    while(option != 3)
    {
    printf("\n\nChoose Your Option:\n1-Turn on the vehicle engine.\n2-Turn off the vehicle engine.\n3-Quit the system.\n");
    scanf("%d", &option);
        if(option == 1) {turnOnVehicleEngine();}
        else if(option == 2) {option = 0; continue;}
        else if(option == 3) {option = 0; break;}
        else {printf("Not A correct Option.\n"); option=0;}
        }
    return 0;
}
