#include "Lights.h"
#include "arduino.h"

using namespace std;

const int DELAY = 300;

void Lights::LightON(int port){
  digitalWrite(port, HIGH);  
}

void Lights::LightOFF(int port){
  digitalWrite(port, LOW);  
}

void Lights::OrderON(int lights[], int size, int delaytime = DELAY){
    for(int i=0; i< size; i++){
        LightON(lights[i]);

        delay(delaytime);
        // cout << lights[i] << " ";
    }
    
}

void Lights::OrderOFF(int lights[], int size, int delaytime = DELAY){
    for(int i=size-1; i>=0; i--){
        LightOFF(lights[i]);

        delay(delaytime);
        // cout << lights[i] << " ";
    }
    
}



