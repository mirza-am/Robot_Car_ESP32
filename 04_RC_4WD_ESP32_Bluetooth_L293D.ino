// Projek Robot Car 4WD Control Bluetooth
// By mirzaam_
// With Module L293D


#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char receivedChar;// received value will be stored as CHAR in this variable


const int enA = 25, enB = 27, enC = 13, enD = 23;
const int in1 = 26, in2 = 17, in3 = 16, in4 = 14;
const int in5 = 12, in6 = 5, in7 = 19, in8 = 18;

const int freq = 500;
const int channel1 = 0;
const int channel2 = 2;
const int channel3 = 3;
const int channel4 = 4;
const int resolution = 10;

int speedRobot  = 450;

const int LED_BUILTIN = 2;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  
  ledcSetup(  channel1 , freq , resolution );
  ledcSetup(  channel2 , freq , resolution );
  ledcSetup(  channel3 , freq , resolution );
  ledcSetup(  channel4 , freq , resolution );
  
  ledcAttachPin( enA , channel1 );
  ledcAttachPin( enB , channel2 );
  ledcAttachPin( enC , channel3 );
  ledcAttachPin( enD , channel4 );
}

void loop() {
receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    if(receivedChar == 'W')
    {
     Serial.println("LED ON");//write on serial monitor
     digitalWrite(LED_BUILTIN, HIGH);// turn the LED ON      
    }
    
    if(receivedChar == 'w')
    {
     Serial.println("LED OFF");//write on serial monitor
     digitalWrite(LED_BUILTIN, LOW);// turn the LED off 
    }  

    if(receivedChar == 'S'){stop();}      
    if(receivedChar == 'F'){forward();}
    if(receivedChar == 'B'){backward();}
    if(receivedChar == 'L'){left();}
    if(receivedChar == 'R'){right();}
    if(receivedChar == 'G'){forwardLeft();}
    if(receivedChar == 'I'){forwardRight();}
    if(receivedChar == 'H'){backwardLeft();}
    if(receivedChar == 'J'){backwardRight();}
    
    if(receivedChar == '0'){speedRobot = 0;}
    if(receivedChar == '1'){speedRobot = 350;}
    if(receivedChar == '2'){speedRobot = 450;}
    if(receivedChar == '3'){speedRobot = 550;}
    if(receivedChar == '4'){speedRobot = 650;}
    if(receivedChar == '5'){speedRobot = 700;}
    if(receivedChar == '6'){speedRobot = 750;}
    if(receivedChar == '7'){speedRobot = 800;}
    if(receivedChar == '8'){speedRobot = 850;}
    if(receivedChar == '9'){speedRobot = 900;}
    if(receivedChar == 'q'){speedRobot = 1023;}
  }
  delay(20);
}


void forward() {
  //Maju
  Serial.println("Jalan");
  
  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}


void backward() {
  //Mundur
  Serial.println("Mundur");

  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}


void stop() {
  //Stop
  Serial.println("Stop");

  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}


void left() {
  //Ke Kiri
  Serial.println("Kiri");

  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);  
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}


void right() {
  //Ke Kanan
  Serial.println("Kanan");

  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}


void forwardRight() {
  //Maju Dan Ke Kiri
  Serial.println("Jalan Dan Kiri");
  
  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}


void forwardLeft() {
  //Maju Dan Ke Kanan
  Serial.println("Jalan Dan Kanan");
  
  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}


void backwardRight() {
  //Mundur Dan Ke Kanan
  Serial.println("Mundur Dan Kanan");
  
  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}


void backwardLeft() {
  //Maju Dan Ke Kanan
  Serial.println("Jalan Dan Kanan");
  
  ledcWrite(channel1, speedRobot);
  ledcWrite(channel2, speedRobot);
  ledcWrite(channel3, speedRobot);
  ledcWrite(channel4, speedRobot);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
