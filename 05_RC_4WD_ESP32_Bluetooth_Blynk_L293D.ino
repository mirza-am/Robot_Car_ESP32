// Projek Robot Car 4WD Control Bluetooth Blynk
// By mirzaam_
// With Module L293D


#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BT.h>

char auth[] = "1vM3cbKsmcelo_uDcmxXCeEzT4qgGUWg";


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
  Serial.begin(115200);
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("BTESP32");
  Blynk.begin(auth);
  
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
   Blynk.run();
}


//----------------------------
BLYNK_WRITE(V1) {
   int x = param[0].asInt(); 
   int y = param[1].asInt();

   // Stop
     if(x==0 && y==0){
          stop();
     }
   // Maju
     else if(x==0 && y==1){
          forward();
     }
          
  // Mundur
     else if(x==0 && y==-1){
          backward();
     }
     
  // Ke Kanan
     else if(x==1 && y==0){
          left();
     }
     
  // Ke Kiri
     else if(x==-1 && y==0){
          right();
     }

  // Maju Dan Ke Kanan
     else if(x==1 && y==1){
          forwardRight();
     }

  // Maju Dan Ke Kiri
     else if(x==-1 && y==1){
          forwardLeft();
     }

  // Mundur Dan Ke Kanan
     else if(x==1 && y==-1){
          backwardRight();
     }

  // Maju Dan Ke Kiri
     else if(x==-1 && y==-1){
          backwardLeft();
     }
}
//----------------------------


//----------------------------
BLYNK_WRITE(V2)
{
   int speedRobot = param.asInt();
     // speed = 300 - 900;
     Serial.print("Speed Motor: ");
     Serial.println(speedRobot);
     ledcWrite(channel1 , speedRobot);
     ledcWrite(channel2 , speedRobot);
     ledcWrite(channel3 , speedRobot);
     ledcWrite(channel4 , speedRobot);
}
//----------------------------

  


void forward() {
  //Maju
  Serial.println("Jalan");
  
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

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
