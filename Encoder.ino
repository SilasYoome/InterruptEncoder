const byte encoderPinA = 2;//outputA digital pin2
const byte encoderPinB = 3;//outoutB digital pin3
volatile int count = 0;
int protectedCount = 0;
int previousCount = 0;

int flagA = 0;
int flagB = 0;

#define readA digitalRead(2)
#define readB digitalRead(3)


void setup() {
  Serial.begin (115200);

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(encoderPinA), isrA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), isrB, CHANGE);
}

void loop() {
  noInterrupts();
  protectedCount = count;
  interrupts();
 
  if(protectedCount != previousCount) {
    Serial.println(protectedCount);
  }
  previousCount = protectedCount;
}

void isrA() {
  if(flagA == 0 && flagB == 0){
    flagA = 1;
  }
  if(flagA == 1){
    count++;
  }else if(flagB == 1){
    count--;
  }
  if(readA == 0 && readB == 0){
    flagA = 0;
    flagB = 0;
  }
}
void isrB() {
  if(flagA == 0 && flagB == 0){
    flagB = 1;
  }
  if(flagA == 1){
    count++;
  }else if(flagB == 1){
    count--;
  }
  if(readA == 0 && readB == 0){
    flagA = 0;
    flagB = 0;
  }
}
