#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN; 

const int datain = 11;

int const trigPin = 5;
int const echoPin = 6;
int const buzzPin = 2;

int lm=4;
int lmr=8;
int rm=12;
int rmr=7;
int ledPin=13;

void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzPin, OUTPUT); 
  

pinMode(ledPin,OUTPUT);
pinMode(lm,OUTPUT);
pinMode(lmr,OUTPUT);
pinMode(rm,OUTPUT);
pinMode(rmr,OUTPUT);

vw_set_rx_pin(datain);
vw_setup(2000);
vw_rx_start(); 
}



void loop()
{
int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance <= 20 && distance >= 0)
 {

  digitalWrite(buzzPin, HIGH);

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
            //delay(2000);
            digitalWrite(ledPin,LOW);

  if (vw_get_message(buf, &buflen))
    {
      int i;
   for (i = 0; i < buflen; i++)
       {
          if (buf[i]==0x73)//Stationary
          {
            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
            
            digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[i]==0x66)//Forward
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x61)//Backward
            {
              digitalWrite(lm,HIGH);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,HIGH);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x6C)//Left 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x72)//Right 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
           }   
          }
        }

} 


else {
  
digitalWrite(buzzPin, LOW);

 uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen))
    {
   int i;
   for (i = 0; i < buflen; i++)
   {
          if (buf[i]==0x73)//Stationary
          {
            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
            
            digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[i]==0x66)//Forward
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x61)//Backward
            {
              digitalWrite(lm,HIGH);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,HIGH);
              
              digitalWrite(ledPin,HIGH);
          }
          
            if (buf[i]==0x6C)//Left 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==0x72)//Right 
            {
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
           }   
     }
     
    }

  

}
delay(60);
}
  
