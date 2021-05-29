// Projek Robot Car Control WiFi
// By mirzaam_
// With Module L298N

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "r6OxEolMa5TH1oarrGr5TXBeaC3TsaFi";

char ssid[] = "MariAtun";
char pass[] = "29031999";

// Make Variable From Module L298N
const int enA = 27, enB = 14;
const int in1 = 16, in2 = 17, in3 = 25, in4 = 26;

const int freq = 500;
const int channel1 = 0;
const int channel2 = 1;
const int resolution = 10;

int speedRobot  = 300;

const int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  ledcSetup(  channel1 , freq , resolution );
  ledcSetup(  channel2 , freq , resolution );
  ledcAttachPin( enA , channel1 );
  ledcAttachPin( enB , channel2 );
}

void loop() {
  Blynk.run();
}


//----------------------------
BLYNK_WRITE(V1) {
   int x = param[0].asInt(); 
   int y = param[1].asInt();

   // Maju
     if(x==0 && y==1){
          forward();
     }
          
  // Mundur
     else if(x==0 && y==-1){
          backward();
     }
     
  // Ke Kanan
     else if(x==1 && y==0){
          right();
     }
     
  // Ke Kiri
     else if(x==-1 && y==0){
          left();
     }

  // Stop
     else if(x==0 && y==0){
          stop();
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
}

//----------------------------



  //Maju
void forward() {
  Serial.println("Jalan");
    
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Mundur
void backward() {
  Serial.println("Mundur");
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


  //Berhenti
void stop() {
  Serial.println("Berhenti");

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kanan
void right() {
  Serial.println("Belok Ke Kanan");

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kiri
void left() {
  Serial.println("Belok Ke Kiri");

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Putar Balik
void turn() {
  Serial.println("Putar Balik");

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
