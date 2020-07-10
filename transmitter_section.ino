int xPin=0;
int yPin=1;


int ledPin=13;


#include <VirtualWire.h>


void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  pinMode(ledPin,OUTPUT);
}

void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  
  
  if ((xval>315 && xval<345) && (yval>315 && yval<345))
  {
    digitalWrite(ledPin,LOW);
    send("s");
  } 
  else 
  { 
    if ((xval>315 && xval<335) && (yval>265 && yval<320)) 
    {
      digitalWrite(ledPin,HIGH);
      send("f");
      
    }
    if ((xval>325 && xval<340) && (yval>365 && yval<405)) 
    {
      digitalWrite(ledPin,HIGH);
      send("a");
      
    }
    if ((xval>260 && xval<300) && (yval>315 && yval<340)) 
    {
      digitalWrite(ledPin,HIGH);
      send("l");
     }
    if ((xval>370 && xval<400 ) && (yval>325 && yval<350))
    {
      digitalWrite(ledPin,HIGH);
      send("r");
      
    }
 
}  
}


void send(char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
