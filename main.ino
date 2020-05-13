#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_CS4 277
#define NOTE_DS4 311
#define NOTE_FS4 370
#define NOTE_GS4 415
#define NOTE_AS4 466
#define NOTE_CS5 554
#define NOTE_DS5 622
#define NOTE_FS5 740
#define NOTE_GS5 831
#define NOTE_AS5 932
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_C4  262  
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440

#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698

#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

int songspeed = 2;
//Mario 
int notes_mario[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario 
int duration_mario[] = {
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
 
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
 
  111, 111, 111,
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
 
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
 
  111, 111, 111,
  83, 83, 83, 83,
  83, 83, 83, 83,
  83, 83, 83, 83,
};

 

RTC_DS1307 rtc;
Servo servo;

int buzzer = 3;
int ledPin = 8;
int ledPin2 = 10;
int ledPin3 = 12;
int button = 2;
int counter = 0;
int ServingSize = 500;

long buttonTimer = 0;
long longPressTime = 500;

boolean buttonActive = false;
boolean longPressActive = false;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};



void setup() 

{
    pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  if (! rtc.begin()) 
  {
    Serial.print("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) 
  {
    Serial.print("RTC is NOT running!");
  }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
}

void loop() {

  Serial.begin(9600);
  DateTime now = rtc.now();
  
  if (digitalRead(button) == HIGH) {

    if (buttonActive == false) {
      buttonActive = true;
            buttonTimer = millis();
    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) 
        
        {
      longPressActive = true;
            digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            delay(500);
            digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            delay(500);
            digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            delay(500);
            digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            delay(500);
            digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            delay(500);
         
          for (int i=0; i < 16 ;i++)
              {              
                int wait = duration_mario[i] * 2;
        tone(buzzer,notes_mario[i],wait);          
        delay(wait);
        }                       
            
      servo.attach(6);
      servo.write(0);
      delay(ServingSize);
      Serial.print(" Feeding ");
      Serial.println(ServingSize);
      servo.write(90);
      delay(2000);
      servo.detach();
      delay (2000);
      counter--;

    }

  } else {

    if (buttonActive == true) {

      if (longPressActive == true) 
      
      {
        longPressActive = false;

      } else {
              
               
              if (counter % 4 == 0)
              { 
                digitalWrite(ledPin, HIGH);
                digitalWrite(ledPin2, LOW);
                digitalWrite(ledPin3, LOW);
                ServingSize = 800;
                Serial.println(ServingSize);
                Serial.print("");
                Serial.println(now.month());
                Serial.print("");
                Serial.println(now.hour());
                
               }
        
              if (counter % 4 == 1)
               {
              
        digitalWrite(ledPin, LOW);
                digitalWrite(ledPin2, HIGH);
                digitalWrite(ledPin3, LOW);
                ServingSize = 1000;
                Serial.print(ServingSize);
                Serial.print("");
                }
              
              else if (counter % 4 == 2)
              {
                digitalWrite(ledPin, LOW);
                digitalWrite(ledPin2, LOW);
                digitalWrite(ledPin3, HIGH);
                ServingSize = 1500;
                Serial.print(ServingSize);
                Serial.print("");
               } 
              
              else if (counter % 4 == 3) {
                digitalWrite(ledPin, LOW);
                digitalWrite(ledPin2, LOW);
                digitalWrite(ledPin3, LOW); 
                ServingSize = 0;
        Serial.print("Feeder In Idle mode");
        Serial.print(""); 
              }

      counter++;

      buttonActive = false;

    }

  }

}    
        if((((now.hour() == 21 && now.minute() == 42)) or ((now.hour() == 21 && now.minute() == 44)))&& (ServingSize!=0))
    
               {
    
    
    int size_mario = sizeof(notes_mario)/sizeof(int);   
        for (int i=0; i < size_mario ;i++)
         
         {              
                int wait = duration_mario[i] * 2;
        tone(buzzer,notes_mario[i],wait);          
        delay(wait);
         } 
                 
      servo.attach(6);
      servo.write(0);
      delay(ServingSize);
      Serial.print(" Feeding ");
      Serial.println(ServingSize);
      servo.write(90);
      delay(2000);
      servo.detach();
      delay (60000);
                  
        }  

     
  
