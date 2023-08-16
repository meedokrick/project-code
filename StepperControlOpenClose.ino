//stepper motor control for opening and closing mechanism

const int StepX = 2;
const int DirX = 6;
const int StepY = 3;
const int DirY = 7;
const int StepZ = 4;
const int DirZ = 8;
const int DirA = 5;
const int StepA = 9;


void setup() {
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode(DirZ,OUTPUT);
  pinMode(StepA, OUTPUT);
  pinMode(DirA, OUTPUT);

}

void loop() {
 
}
void openDrawer1() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirX, HIGH);
    digitalWrite(StepX,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepX,LOW); 
  }
}
void openDrawer2() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirY, HIGH);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepY,LOW); 
  }
}
void openDrawer3() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirZ, HIGH);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepZ,LOW); 
  }
}
void openDrawer4() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirA, HIGH);
    digitalWrite(StepA,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepA,LOW); 
  }
}
void closeDrawer1() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirX, LOW);
    digitalWrite(StepX,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepX,LOW); 
  }
}
void closeDrawer2() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirY, LOW);
    digitalWrite(StepY,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepY,LOW); 
  }
}
void closeDrawer3() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirZ, LOW);
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepZ,LOW); 
  }
}
void closeDrawer4() {
  for(int x = 0; x<1000; x++) {
    DigitalWrite(DirA, LOW);
    digitalWrite(StepA,HIGH);
    delayMicroseconds(3000);
    digitalWrite(StepA,LOW); 
  }
}

