/* rawSend.ino Example sketch for IRLib2
 *  Illustrates how to send a code Using raw timings which were captured
 *  from the "rawRecv.ino" sample sketch.  Load that sketch and
 *  capture the values. They will print in the serial monitor. Then you
 *  cut and paste that output into the appropriate section below.
 */
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender
#include <dht.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9);  // bluetooth serial connections


#define dht_apin A0 // Analog Pin sensor is connected to
 
//dht DHT;

IRsendRaw mySender;
#define button 7
#define bLED 12
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(200); 

  Serial.println("remote is reday");
  
  while (!Serial); //delay for Leonardo
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
}
/* Cut and paste the output from "rawRecv.ino" below here. It will 
 * consist of a #define RAW_DATA_LEN statement and an array definition
 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes
 * with "…,1000};"
 */
#define RAW_DATA_LEN 34
uint16_t rawDataOff[RAW_DATA_LEN]={
  10450, 3134, 3969, 454, 7500, 417, 1578, 733, 
  2844, 533, 1546, 748, 1495, 774, 1491, 777, 
  2843, 532, 4072, 461, 1563, 732, 6344, 411, 
  1589, 723, 4054, 453, 1570, 726, 1510, 772, 
  1498, 1000};

#define RAW_DATA_LEN 34
uint16_t rawDataOn[RAW_DATA_LEN]={
  10450, 3134, 3969, 454, 7500, 417, 1578, 733, 
  2844, 533, 1546, 748, 1495, 774, 1491, 777, 
  2843, 532, 4072, 461, 1563, 732, 6344, 411, 
  1589, 723, 4054, 453, 1570, 726, 1510, 772, 
  1498, 1000};


/*
 * Cut-and-paste into the area above.
 */ 
void loop() {

//  delay(10);
//  DHT.read11(dht_apin);
//  int temp = DHT.temperature;
//  Serial.print("temperature = ");
//  Serial.print(temp); 
//  Serial.println(" C");

  if(mySerial.available()>0){

    int data = mySerial.read();
    if(data == 79){ // O asci
      
    Serial.println("ON"); 
    mySender.send(rawDataOn,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC Switched On"));
    delay(100);
      }
     else if(data == 70){ // F asci
        
    Serial.println("OFF"); 
     mySender.send(rawDataOff,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
     Serial.println(F("AC Switched Off"));
     delay(100);
        
      
    }
    else{
      Serial.print("heh: ");
      Serial.println(data);
    }
  }
}
