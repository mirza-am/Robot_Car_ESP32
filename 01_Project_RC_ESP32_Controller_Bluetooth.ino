// Projek Robot Car Control Bluetooth
// By mirzaam_
// With Module L298N


#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char receivedChar;// received value will be stored as CHAR in this variable


const int enA = 27, enB = 14;
const int in1 = 16, in2 = 17, in3 = 25, in4 = 26;

const int freq = 500;
const int channel1 = 0;
const int channel2 = 1;
const int resolution = 10;

int speedRobot  = 400;

const int LED_BUILTIN = 2;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  ledcSetup(  channel1 , freq , resolution );
  ledcSetup(  channel2 , freq , resolution );
  ledcAttachPin( enA , channel1 );
  ledcAttachPin( enB , channel2 );
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



//Maju
void forward() {
  Serial.println("Jalan");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Mundur
void backward() {
  Serial.println("Mundur");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


  //Berhenti
void stop() {
  Serial.println("Berhenti");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kanan
void right() {
  Serial.println("Belok Ke Kanan");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kiri
void left() {
  Serial.println("Belok Ke Kiri");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Putar Balik
void turn() {
  Serial.println("Putar Balik");
  
  ledcWrite(channel1 , speedRobot);
  ledcWrite(channel2 , speedRobot);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
