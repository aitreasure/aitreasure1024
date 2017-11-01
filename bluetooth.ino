/*
 蓝牙遥控Arduino小车程序
 功能：小车接收到蓝牙模块发送过来的字符“ONA”前进，字符“ONB”后退，字符“ONC”左转，字符“OND”右转，字符“ONE”停止, 字符“ONF”停止。

 */
const int L298nIn1 = 8;//L298N模块信号输入
const int L298nIn2 = 9;
const int L298nIn3 = 10;
const int L298nIn4 = 11;
const String GO = "ONA";//蓝牙遥控器发送信息代码定义
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
void goForward() {//小车前进
  digitalWrite(L298nIn1, HIGH);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, HIGH);
}
void goBack() {//小车后退
  digitalWrite(L298nIn1, LOW);
  digitalWrite(L298nIn2, HIGH);
  digitalWrite(L298nIn3, HIGH);
  digitalWrite(L298nIn4, LOW);
}
void goStop() {//小车停止
  digitalWrite(L298nIn1, LOW);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, LOW);
}
void turnRight() {//小车右转
  digitalWrite(L298nIn1, HIGH);
  digitalWrite(L298nIn2, LOW);
  digitalWrite(L298nIn3, LOW);
  digitalWrite(L298nIn4, LOW);
}
void turnLeft() {//小车左转
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
void loop()//主循环函数
{
  String s = readTtl();
  if (s == GO ) goForward();//如果按GO键，小车前进，直到按STOP键停止
  if (s == LEFT ) turnLeft();
  if (s == STOP ) goStop();
  if (s == RIGHT ) turnRight();
  if (s == BACK ) goBack();
  if (s == STOPP ) goStop();
}
