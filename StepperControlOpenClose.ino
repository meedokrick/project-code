//stepper motor control for opening and closing mechanism
#include <SoftwareSerial.h>
#include <HX711.h>

HX711 scale;  // Create an instance of the HX711 library

//Declare stepper motor step and direction pins
const int StepX = 2;
const int DirX = 3;
const int StepY = 4;
const int DirY = 5;
const int StepZ = 6;
const int DirZ = 7;
const int DirA = 8;
const int StepA = 9;

const int Buzzer = 10;
const int DOUT_PIN = 11;
const int CLK_PIN = 12;

const int FORCE_THRESHOLD = 800; // Define the weight threshold in grams

SoftwareSerial Serial1 (A3, A2); //Rx, Tx

void setup() {
  Serial1.begin(9600);

  scale.begin(DOUT_PIN, CLK_PIN);
  scale.set_scale();
  scale.tare();

  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode(DirZ,OUTPUT);
  pinMode(StepA, OUTPUT);
  pinMode(DirA, OUTPUT);

  pinMode(Buzzer, OUTPUT);

}
void loop() {
 ReadSerialCommunication();
 LoadForce();
}

void ReadSerialCommunication(){
  if(Serial1.available() > 0){
    switch(Serial1.read()){
      case '1':
        openDrawer1();
        break;
      case '2':
        openDrawer2();
        break;
      case '3':
        openDrawer3();
        break;
      case '4':
        openDrawer4();
        break;
      case '11':
        closeDrawer1();
        break;
      case '12':
        closeDrawer2();
        break;
      case '13':
        closeDrawer3();
        break;
      case '14':
        closeDrawer4();
        break;
    }
  }
}


void openDrawer1() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirX, HIGH);
    digitalWrite(StepX,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepX,LOW); 
  }
}
void openDrawer2() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirY, HIGH);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepY,LOW); 
  }
}
void openDrawer3() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirZ, HIGH);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepZ,LOW); 
  }
}
void openDrawer4() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirA, HIGH);
    digitalWrite(StepA,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepA,LOW); 
  }
}
void closeDrawer1() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirX, LOW);
    digitalWrite(StepX,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepX,LOW); 
  }
}
void closeDrawer2() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirY, LOW);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepY,LOW); 
  }
}
void closeDrawer3() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirZ, LOW);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepZ,LOW); 
  }
}
void closeDrawer4() {
  for(int x = 0; x<1000; x++) {
    digitalWrite(DirA, LOW);
    digitalWrite(StepA,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepA,LOW); 
  }
}

void LoadForce() {
  if (scale.is_ready()) {
    float force = scale.get_units();  // Get reading in units (after calibration)
    Serial.print("Force: ");
    Serial.print(force);
    Serial.println("g");
    if (force > FORCE_THRESHOLD){
      digitalWrite(Buzzer, HIGH);
    }
  } else {
    Serial.println("Error reading from scale");
  }
}

