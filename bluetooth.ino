//AITREASURE smart car stem learning kit base on arduino UNO R3, pin 8, 9, 10, 11 connect to L298N IN1~4

const int L298nIn1 = 8;//define L298N motor drive board input
const int L298nIn2 = 9;//define MCU pin8,9 as left wheel’s command
const int L298nIn3 = 10;// define MCU pin10,11 as right wheel’s command
const int L298nIn4 = 11;
const String GO = "ONA";//define the remote app code value
const String BACK = "ONB";
const String RIGHT = "OND";
const String LEFT = "ONC";
const String STOP = "ONE";
const String STOPP = "ONF";
void setup()
{
  pinMode(L298nIn1, OUTPUT);
  pinMode(L298nIn2, OUTPUT);
  pinMode(L298nIn3, OUTPUT);
  pinMode(L298nIn4, OUTPUT);
  Serial.begin(9600);
}
void goForward() {// car go forward function
  digitalWrite(L298nIn1, HIGH);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, HIGH);
}
void goBack() {// car go backward function
  digitalWrite(L298nIn1, LOW);
  digitalWrite(L298nIn2, HIGH);
  digitalWrite(L298nIn3, HIGH);
  digitalWrite(L298nIn4, LOW);
}
void goStop() {// car stop function
  digitalWrite(L298nIn1, LOW);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, LOW);
}
void turnRight() {// car turn right function
  digitalWrite(L298nIn1, HIGH);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, LOW);
}
void turnLeft() {// car turn left function
  digitalWrite(L298nIn1, LOW);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, HIGH);
}
String readTtl() {
  String comdata = "";
  while (Serial.available())
  {
    comdata += char(Serial.read());
    delay(2);
  }
  return comdata;
}
void loop()//main loop function,  MCU will always execute this function
{
  String s = readTtl();
  if (s == GO ) goForward();//if got the GO code from app, than execute go //forward function
  if (s == LEFT ) turnLeft(); //if got the left code from app, than execute 
                        //turn left function
  if (s == STOP ) goStop();  
  if (s == RIGHT ) turnRight();
  if (s == BACK ) goBack();
  if (s == STOPP ) goStop();
}
