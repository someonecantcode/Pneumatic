#include "Retracter.h"
#include "arduino.h"
const int DELAY = 300;

void Retracter::InOutTIME(int port, int delaytime = DELAY){
  digitalWrite(port, HIGH);
  delay(delaytime);
  digitalWrite(port, LOW);
  
}

/*  Pneumatic Cylinders can't expand to specific points
    and only can be extended fully or retracted fully.

void Retracter::InOutPercentage(int port, int percentage){
  analogWrite(port, (percentage/100) * 255);
  delay(delaytime);
  digitalWrite(port, LOW);
}
*/

void Retracter::Insert(int port){
  digitalWrite(port, HIGH);
}

void Retracter::Retract(int port){
  digitalWrite(port, LOW);
}



