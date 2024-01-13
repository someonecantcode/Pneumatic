#include "Retracter.h"
#include "Lights.h"


const int STOCK = 7;
const int CLAMP = 6;
const int STOPPERS[] = {4,5};
const int EXTENDER = 3;

int ProgressLights[] = {A0,A1,A2};
int TotalLights = sizeof(ProgressLights)/sizeof(ProgressLights[0]);

//---------------------



Retracter retractcontrol;
Lights lightcontrol;
void setup() {
  for (int i = 1; i <= 13; i++) { //init all pins
    pinMode(i, OUTPUT);
  }
  
  
    lightcontrol.OrderON(ProgressLights, TotalLights, 5);
  

//-----------Start-------
  retractcontrol.Insert(STOPPERS[0]); 
  retractcontrol.Insert(STOPPERS[1]); 
  retractcontrol.Retract(CLAMP); 
  retractcontrol.Retract(STOCK);  
  
  lightcontrol.OrderOFF(ProgressLights, TotalLights, 1000);
}


void loop() {


  for(int i = 0; i<2; i++){
    retractcontrol.Insert(STOCK);
    retractcontrol.Insert(CLAMP);

    retractcontrol.InOutTIME(EXTENDER, 6500); //cutting board will move
    

    retractcontrol.Retract(CLAMP);
    retractcontrol.Retract(STOPPERS[i]);
    lightcontrol.LightON(ProgressLights[i]);
  }
    lightcontrol.LightON(ProgressLights[3]);


  
}
