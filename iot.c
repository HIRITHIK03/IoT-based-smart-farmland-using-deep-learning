#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define rxPin A2
#define txPin A3
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
LiquidCrystal lcd(8,9,10,11,12,13);
int Ir=3;
int buzzer=2;
int Ir1=4;
int c=0;
int Switch=7;
int Switch1=A4;
int M1=6;
int M2=A5;
//int count_value1=0;
int a,b,d,e;
int led = 13; // pin connected to LED
int sensor = 5; // pin for the ultrasonic sensor
int state = LOW; // default, no motion
int val = 0; // variable for sensor status 
void setup() {
    // Pin 13 is set as OUTPUT
    pinMode(led, OUTPUT);
      pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    pinMode(buzzer,OUTPUT);
    // Pin 2 is set as INPUT
    lcd.begin(16,2);
     pinMode(Ir,INPUT);
    pinMode(sensor, INPUT);
    pinMode(Switch,INPUT);
        pinMode(Switch1,INPUT);
    pinMode(M1,OUTPUT);
    //pinMode(M1,OUTPUT);
   pinMode(M2,OUTPUT);
    lcd.setCursor(0,0);
        lcd.print("WELCOME");
        delay(2000);
        lcd.clear();
    // initialize serial communication
    Serial.begin(9600); 
        mySerial.begin(9600); 
}
void loop() {
  int a=digitalRead(Ir);
    int b=digitalRead(Ir1);
  int d=digitalRead(Switch);
  int e=digitalRead(Switch1);
    val = digitalRead(sensor); 
     if (Serial.available() > 0)
     {
       char red1=Serial.read();
       delay(100);
       if(red1=='G')
       {
         lcd.setCursor(0,1);
        lcd.print("GOAT DETECT");
        digitalWrite(buzzer,HIGH);
        delay(3000);
        digitalWrite(buzzer,LOW);
         sendsms1();
         lcd.clear();
       }
       if(red1=='P')
       {
        lcd.setCursor(0,1);
        lcd.print("PIG DETECT");
        digitalWrite(buzzer,HIGH);
        delay(3000);
        digitalWrite(buzzer,LOW);
          sendsms2();
          lcd.clear();
       }
       if(red1=='C')
       {
          lcd.setCursor(0,1);
        lcd.print("COW DETECT");
        digitalWrite(buzzer,HIGH);
        delay(3000);
        digitalWrite(buzzer,LOW);
          sendsms3();
          lcd.clear();
       }
       if(red1=='E')
       {
          lcd.setCursor(0,1);
        lcd.print("ELEPHENT DETECT");
        digitalWrite(buzzer,HIGH);
        delay(3000);
        digitalWrite(buzzer,LOW);
          sendsms4();
          lcd.clear();
       }
     }
       // read sensor value
  /PIR FUNCTION*/     
    if (val == HIGH) { // check if the sensor is HIGH
    digitalWrite(led, HIGH); // turn LED ON
    delay(100); // delay 100 milliseconds
    if (state == LOW) {
       //Serial.println("M");
        //delay(100);
        Serial.println(1);
       //lcd.clear();
        //lcd.setCursor(0,0);
        //lcd.print("motion detected");
        delay(1000);
        //lcd.clear();
        state = HIGH; // update variable state to HIGH
 }
 }
    else {
        digitalWrite(led, LOW); // turn LED OFF
        delay(200); // delay 200 milliseconds
        if (state == HIGH) {
            Serial.println(0);
            state = LOW; // update variable state to LOW
        }
    }
    /IR FUNCTION*/
    if(a==0)
  {
    c=c+1;
      
  }
   if(b==0)
  {
    c=c-1;
     }
    lcd.clear();
    lcd.setCursor(1,0);
 lcd.println("animalCount= ");
    lcd.setCursor(13,0);
    lcd.println(c); 
/SWITCH/
    if(d==1)
    {
      digitalWrite(M1,HIGH);
      delay(5000);
    digitalWrite(M1,LOW);
    }
   
    if(e==1)
    {
      digitalWrite(M2,HIGH);
     delay(5000);
    digitalWrite(M2,LOW);
    }
    
    
   
}
    /**************
    ****************GSM*/
    void sendsms1()
    
{
  
    
  mySerial.println("AT\r");
  delay(1000);
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"9345755117\"\r");
  delay(1000);
  mySerial.println("GOAT DETECT");
  delay(1000);
  mySerial.println((char)26);
  delay(100);
}
void sendsms2()
{
  /*if (mySerial.available() > 0) 
    {
        mySerial.read();
    }*/
  mySerial.println("AT\r");
  delay(1000);
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"9345755117\"\r");
  delay(1000);
  mySerial.println("PIG DETECT");
  delay(1000);
  mySerial.println((char)26);
  delay(100);
}
void sendsms3()
{
  
  mySerial.println("AT\r");
  delay(1000);
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"9345755117\"\r");
  delay(1000);
  mySerial.println("COW DETECT");
  delay(1000);
  mySerial.println((char)26);
  delay(100);
}
void sendsms4()
{
  
  mySerial.println("AT\r");
  delay(1000);
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
 mySerial.println("AT+CMGS=\"9345755117\"\r");
  delay(1000);
  mySerial.println("ELEPHENT DETECT");
  delay(1000);
  mySerial.println((char)26);
  delay(100);
}
