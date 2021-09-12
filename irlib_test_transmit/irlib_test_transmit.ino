/* rawSend.ino Example sketch for IRLib2
 *  Illustrates how to send a code Using raw timings which were captured
 *  from the "rawRecv.ino" sample sketch.  Load that sketch and
 *  capture the values. They will print in the serial monitor. Then you
 *  cut and paste that output into the appropriate section below.
 */
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender
#include <dht.h>

#define dht_apin A0 // Analog Pin sensor is connected to
 
//dht DHT;

IRsendRaw mySender;
#define button 7
#define bLED 12
void setup() {
  Serial.begin(9600);
  delay(200); 

  pinMode(button,INPUT);
  pinMode(bLED,OUTPUT);
  
  while (!Serial); //delay for Leonardo
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
}
/* Cut and paste the output from "rawRecv.ino" below here. It will 
 * consist of a #define RAW_DATA_LEN statement and an array definition
 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes
 * with "…,1000};"
 */
#define RAW_DATA_LEN 200
uint16_t rawDataOff[RAW_DATA_LEN]={
  4430, 4426, 534, 1642, 526, 558, 522, 1654, 
  514, 1658, 518, 570, 514, 570, 518, 1654, 
  514, 574, 514, 574, 510, 1662, 510, 578, 
  510, 574, 510, 1666, 506, 1666, 506, 582, 
  502, 1670, 502, 582, 506, 1670, 502, 1670, 
  498, 1690, 482, 1694, 478, 610, 478, 1694, 
  474, 1698, 474, 1702, 470, 614, 470, 618, 
  470, 618, 466, 618, 470, 1706, 462, 622, 
  466, 622, 462, 1710, 462, 1710, 462, 1714, 
  462, 622, 462, 626, 462, 626, 458, 626, 
  462, 626, 462, 622, 462, 626, 462, 622, 
  462, 1714, 462, 1710, 462, 1710, 462, 1710, 
  466, 1706, 466, 5446, 4330, 4502, 474, 1698, 
  474, 614, 474, 1698, 478, 1694, 482, 606, 
  482, 602, 486, 1670, 506, 582, 506, 578, 
  510, 1662, 518, 570, 518, 566, 526, 1646, 
  534, 1638, 538, 550, 538, 1634, 542, 546, 
  542, 1626, 546, 1630, 542, 1630, 546, 1626, 
  550, 538, 550, 1622, 550, 1622, 554, 1618, 
  558, 530, 558, 526, 558, 530, 558, 526, 
  562, 1614, 562, 522, 566, 522, 562, 1610, 
  566, 1610, 566, 1606, 566, 522, 566, 522, 
  562, 522, 566, 522, 566, 518, 566, 522, 
  566, 522, 562, 522, 566, 1610, 562, 1610, 
  566, 1606, 566, 1610, 562, 1610, 566, 1000};

//#define RAW_DATA_LEN 68
//uint16_t rawDataOff[RAW_DATA_LEN]={
//  4530, 4514, 562, 1690, 558, 1690, 558, 1690, 
//  558, 566, 558, 566, 558, 566, 558, 566, 
//  558, 566, 558, 1690, 558, 1690, 558, 1690, 
//  558, 566, 558, 566, 558, 566, 558, 570, 
//  554, 566, 558, 570, 558, 1690, 558, 566, 
//  558, 566, 558, 566, 558, 566, 558, 566, 
//  558, 566, 558, 1690, 558, 566, 558, 1690, 
//  558, 1690, 558, 1690, 558, 1690, 558, 1694, 
//  554, 1694, 554, 1000};

#define RAW_DATA_LEN 200
uint16_t rawDataOn[RAW_DATA_LEN]={
  4434, 4422, 542, 1630, 542, 542, 546, 1630, 
  538, 1634, 538, 546, 538, 550, 538, 1634, 
  534, 554, 534, 550, 534, 1638, 534, 554, 
  534, 550, 534, 1638, 534, 1642, 530, 558, 
  526, 1646, 526, 1646, 526, 558, 526, 562, 
  526, 1646, 522, 1650, 522, 1654, 518, 1654, 
  518, 1654, 518, 566, 522, 1650, 522, 1650, 
  526, 562, 522, 562, 526, 562, 522, 562, 
  526, 562, 526, 1646, 526, 1646, 526, 558, 
  530, 1642, 530, 558, 526, 562, 526, 558, 
  530, 558, 526, 558, 534, 554, 526, 1646, 
  530, 554, 530, 1642, 534, 1638, 534, 1642, 
  530, 1642, 534, 5374, 4398, 4438, 526, 1646, 
  522, 566, 522, 1650, 518, 1658, 510, 578, 
  502, 586, 498, 1690, 474, 614, 470, 618, 
  466, 1710, 462, 622, 462, 626, 458, 1714, 
  458, 1718, 454, 630, 454, 1722, 450, 1722, 
  450, 658, 430, 658, 426, 1746, 426, 1750, 
  422, 1750, 422, 1750, 422, 1754, 418, 666, 
  422, 1754, 418, 1754, 418, 670, 414, 674, 
  414, 670, 418, 670, 414, 674, 418, 1754, 
  418, 1754, 418, 670, 414, 1758, 418, 670, 
  414, 670, 418, 670, 414, 674, 414, 670, 
  418, 670, 418, 1750, 430, 638, 450, 1722, 
  454, 1714, 462, 1710, 470, 1702, 474, 1000};

//#define RAW_DATA_LEN 68
//uint16_t rawDataOn[RAW_DATA_LEN]={
//4538, 4510, 566, 1682, 566, 1682, 566, 1682, 
//  566, 558, 566, 558, 566, 558, 566, 558, 
//  570, 554, 570, 1678, 570, 1678, 570, 1678, 
//  570, 554, 570, 554, 570, 554, 570, 554, 
//  570, 554, 570, 554, 570, 1678, 570, 554, 
//  570, 554, 570, 554, 570, 558, 566, 558, 
//  566, 558, 566, 1682, 566, 558, 566, 1682, 
//  566, 1682, 566, 1682, 566, 1682, 566, 1682, 
//  566, 1678, 570, 1000};




/*
 * Cut-and-paste into the area above.
 */
int buttonState = 0;
 
 int togglepin = 0;   
void loop() {

//  delay(10);
//  DHT.read11(dht_apin);
//  int temp = DHT.temperature;
  Serial.print("temperature = ");
//  Serial.print(temp); 
  Serial.println(" C");

  buttonState = digitalRead(button);
  Serial.println(buttonState);
  if (buttonState == HIGH){
    if( togglepin == 0){
      togglepin = 2;
    }else if(togglepin == -1){
      togglepin = 1;
    }
  }
  if (togglepin == 2) {
    mySender.send(rawDataOn,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC Switched On"));
    togglepin = -1;
    digitalWrite(bLED,HIGH);
    delay(5);
  }
  else if (togglepin == 1) {
    mySender.send(rawDataOff,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC Switched Off"));
    togglepin = 0;
    digitalWrite(bLED,LOW);
    delay(5);
  }
  
}
