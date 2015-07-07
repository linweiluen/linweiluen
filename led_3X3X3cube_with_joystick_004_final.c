// (z) control
int ledz0 = 9;  //z=0
int ledz1 = 10;  //z=1
int ledz2 = 11;  //z=2

// (x,y) control
int ledxy00 = A5; //(x,y)=(0,0);
int ledxy10 = 12; //(x,y)=(1,0);
int ledxy20 = 2; //(x,y)=(2,0);

int ledxy01 = 3; //(x,y)=(0,1);
int ledxy11 = 4; //(x,y)=(1,1);
int ledxy21 = 5; //(x,y)=(2,1);

int ledxy02 = 6; //(x,y)=(0,2);
int ledxy12 = 7; //(x,y)=(1,2);
int ledxy22 = 8; //(x,y)=(2,2);

// the setup routine runs once when you press reset:
const unsigned int JoyStick_X = A0; //　搖桿x 
const unsigned int JoyStick_Y = A1; //  搖桿y 
const unsigned int JoyStick_Z = A2; //  搖捍z

int min_X, min_Y, min_Z; // xyz最大值
int max_X, max_Y, max_Z; // xyz最小值

const unsigned int NUM_AXES = 3; 
const unsigned int pins[NUM_AXES] = { JoyStick_X, JoyStick_Y, JoyStick_Z };
const unsigned int BUFFER_SIZE = 16;
int buffer[NUM_AXES][BUFFER_SIZE];
int buffer_pos[NUM_AXES] = {0};

void setup() {
//3 rows
  pinMode(ledz0, OUTPUT);
  pinMode(ledz1, OUTPUT);
  pinMode(ledz2, OUTPUT);
  
  //9 Columns
  pinMode(ledxy00, OUTPUT);
  pinMode(ledxy10, OUTPUT);
  pinMode(ledxy20, OUTPUT);
  pinMode(ledxy01, OUTPUT);
  pinMode(ledxy11, OUTPUT);
  pinMode(ledxy21, OUTPUT);
  pinMode(ledxy02, OUTPUT);
  pinMode(ledxy12, OUTPUT);
  pinMode(ledxy22, OUTPUT);
  /*
  xyz搖桿不需要設定input!
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(JoyStick_Z, INPUT);
  */

  Serial.begin(9600); // 9600 bps  
  
  min_X = min_Y = min_Z = -1000;
  max_X = max_Y = max_Z = 1000;
  
}
/*
  int get_axis(const int axis) {
    delay(1);
    buffer[axis][buffer_pos[axis]] = analogRead(pins[NUM_AXES]);
    buffer_pos[axis] = (buffer_pos[axis]+1)% BUFFER_SIZE;
    
    long sum = 0;
    for (int i=0; i<BUFFER_SIZE; i++)
    sum += buffer[axis][i];
    return round(sum / BUFFER_SIZE);
  }
  
  int get_x() {return get_axis(0);}
  int get_y() {return get_axis(1);}
  int get_z() {return get_axis(2);}
  
  */
  
  void JoyStickVal(){
  const int valX = analogRead(JoyStick_X);
  const int valY = analogRead(JoyStick_Y);
  const int valZ = analogRead(JoyStick_Z);
  
  /*
  //當xyz都旋過後，最大最小值會更正為0/1023
  min_X = min(valX, min_X); max_X = max(valX, max_X);
  min_Y = min(valY, min_Y); max_Y = max(valY, max_Y);
  min_Z = min(valZ, min_Z); max_Z = max(valZ, max_Z);
  
  Serial.print("X(");
  Serial.print(min_X);
  Serial.print("/");
  Serial.print(max_X);
  Serial.print("),Y(");
  Serial.print(min_Y);
  Serial.print("/");
  Serial.print(max_Y);
  Serial.print("),Z(");
  Serial.print(min_Z);
  Serial.print("/");
  Serial.print(max_Z);
  Serial.print(")");
  Serial.println("_");
  */
  Serial.print("X(");
  Serial.print(valX);
  Serial.print("),Y(");
  Serial.print(valY);
  Serial.print("),Z(");
  Serial.print(valZ);
  Serial.print(")");
  Serial.println(" ");
  /*
  Serial.print(get_x());
  Serial.print(" ");
  Serial.print(get_y());
  Serial.print(" ");
  Serial.println(get_z());
  */
  
  delay(750);
  }
  
  //原狀態全亮函式
  void ledallligh(){
    digitalWrite(ledz0, HIGH);
    digitalWrite(ledz1, HIGH);
    digitalWrite(ledz2, HIGH);

    digitalWrite(ledxy00, HIGH);
    digitalWrite(ledxy10, HIGH);
    digitalWrite(ledxy20, HIGH);

    digitalWrite(ledxy01, HIGH);
    digitalWrite(ledxy11, HIGH);
    digitalWrite(ledxy21, HIGH);

    digitalWrite(ledxy02, HIGH);
    digitalWrite(ledxy12, HIGH);
    digitalWrite(ledxy22, HIGH);
  }


void loop(){
  JoyStickVal();
  const int valX = analogRead(JoyStick_X);
  const int valY = analogRead(JoyStick_Y);
  const int valZ = analogRead(JoyStick_Z);
  
  if(valY <= 3){//上
  col08();colplan04();dualcolplan02();}
  
  else if(valY >= 1022){//下
  col02();colplan02();dualcolplan01();}
  
  else if(valX <= 3){//左
  col04();colplan01();dualcolplan03();}

  else if(valX >= 1022){//右
  col06();colplan03();dualcolplan04();}
  
  else if(valZ == 1023){//下按閃中層菱形
  led15();led23();led13();led05();FerrisWheel();ShakeX();
  col01();col02();col03();col04();col05();col06();col07();col08();col09();}
  
  else
  {ledallligh();}
  }

void ledsingle(){
    led01();led02();led03();led04();led05();led06();led07();led08();led09();
    led10();led11();led12();led13();led14();led15();led16();led17();led18();
    led19();led20();led21();led22();led23();led24();led25();led26();led27();}
    
void colplan01(){//col1,4,7
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void colplan02(){//col1,2,3
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, HIGH); digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);} 
    
void colplan03(){//col3,6,9
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);}
void colplan04(){//col7,8,9
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, HIGH);
    delay(500);}
    
void colplan05(){//col2,5,8
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, HIGH); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}  

void colplan06(){//col4,5,6
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);} 
//-----------------------------------------------------------------------------------     
void dualcolplan01(){//col1,2,3,4,5,6
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, HIGH); digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
 void dualcolplan02(){//col4,5,6,7,8,9
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, HIGH);
    delay(500);}
 void dualcolplan03(){//col1,2,4,5,7,8
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, HIGH); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}   
 void dualcolplan04(){//col2,3,5,6,8,9
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW); digitalWrite(ledxy10, HIGH); digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, HIGH);
    delay(500);}     
//-----------------------------------------------------------------------------------    
void col01(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col02(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col03(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col04(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col05(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col06(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col07(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col08(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void col09(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);}
    
//-----------------------------------------------------------------------------------
void led01(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, HIGH); digitalWrite(ledxy10, LOW); digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}

void led02(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led03(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led04(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led05(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led06(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led07(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led08(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led09(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);}
    
void led10(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, HIGH);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led11(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led12(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led13(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led14(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led15(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led16(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led17(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led18(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);}
    
void led19(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led20(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led21(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led22(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led23(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led24(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led25(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led26(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}
    
void led27(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);}

//------------------------------------------------------------------------------------
void FerrisWheel(){
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, HIGH);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(500);
    
    digitalWrite(ledz0, LOW);digitalWrite(ledz1, LOW);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);

    digitalWrite(ledz0, LOW);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, HIGH);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, HIGH);digitalWrite(ledxy11, LOW);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(500);

    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, LOW);digitalWrite(ledz2, LOW);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, HIGH);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, HIGH);digitalWrite(ledxy22, LOW);
    delay(500);}
    
//------------------------------------------------------------------------------------
    void ShakeX(){
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, HIGH);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, LOW);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, LOW);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, HIGH);
    delay(250);
    digitalWrite(ledz0, HIGH);digitalWrite(ledz1, HIGH);digitalWrite(ledz2, HIGH);
    digitalWrite(ledxy00, LOW);digitalWrite(ledxy10, LOW);digitalWrite(ledxy20, HIGH);
    digitalWrite(ledxy01, LOW);digitalWrite(ledxy11, HIGH);digitalWrite(ledxy21, LOW);
    digitalWrite(ledxy02, HIGH);digitalWrite(ledxy12, LOW);digitalWrite(ledxy22, LOW);
    delay(250);
    }
    