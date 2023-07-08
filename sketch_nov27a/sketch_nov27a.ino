int relay = 4;
int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;
int Buzzer = 8;
String command = "";
#include <Wire.h>                     // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27,20,4);     // 접근주소: 0x3F or 0x27
#include<Servo.h> //Servo 라이브러리를 추가
Servo servo;      //Servo 클래스로 servo객체 생성
Servo servo2;

char Ard1[5] = {0};
char check[1];
char check2[1];
int value_1 = 0;
String ill = "";
int value = 0;    // 각도를 조절할 변수 value
int value2 = 0;

void setup()
{
  Serial.begin(115200);
  lcd.init(); 
  lcd.backlight();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  servo.attach(7);
  servo2.attach(6);
}

 String read_serial()
{
  String str = "";

while(Serial.available())   
{
    char ch = Serial.read();   
    str.concat(ch);   
    delay(10);  
} 

  return str;
}

void loop()
{ 
  // lcd 출력 데이터 입력 받기
  String str = read_serial();
  str.substring(1,2).toCharArray(check2, 2);
  
    if (check2[0] == 'p') { lcd.backlight();  }
    if (check2[0] == 'q') { lcd.noBacklight(); }
   
  str.substring(0,1).toCharArray(check, 2);
  
    if (check[0] == 'k')
    {
      command = "CH 1 MAC";
      lcd.setCursor(0, 0);
      lcd.print(command);

      if (str.length() >= 2)
      {
        str.substring(2, 5).toCharArray(Ard1, 5);
        value_1 = atoi(Ard1);
        ill = String(value_1);
        lcd.setCursor(13, 3);
        lcd.print("VOL");
        lcd.setCursor(17, 3);
        lcd.print(ill);
 
        if (value_1 > 0)
            tone(Buzzer, 200 + value_1 , 6);
        }
    }

    
    else if (check[0] == 'l')
    {
      command = "CH 2 SBS";
 //     lcd.init();
      lcd.setCursor(0, 0);
      lcd.print(command);

      if (str.length() >= 2)
      {
        str.substring(2, 5).toCharArray(Ard1, 5);
        value_1 = atoi(Ard1);
        ill = String(value_1);
        lcd.setCursor(13, 3);
        lcd.print("VOL");
        lcd.setCursor(17, 3);
        lcd.print(ill);
        if (value_1 > 0)
          tone(Buzzer, 200 + value_1 , 6);
    }
    }
  
    else if (check[0] == 'm')
    {
      command = "CH 3 EBS";
 //     lcd.init();
      lcd.setCursor(0, 0);
      lcd.print(command);

      if (str.length() >= 2)
      {
        str.substring(2, 5).toCharArray(Ard1, 5);
        value_1 = atoi(Ard1);
        ill = String(value_1);
        lcd.setCursor(13, 3);
        lcd.print("VOL");
        lcd.setCursor(17, 3);
        lcd.print(ill);
        if (value_1 > 0)
          tone(Buzzer, 200 + value_1 , 6);
    }
    }
  
    else if (check[0] == 'n')
    {
      command = "CH 4 KBS";
 //     lcd.init();
      lcd.setCursor(0, 0);
      lcd.print(command);

      if (str.length() >= 2)
      {
        str.substring(2, 5).toCharArray(Ard1, 5);
        value_1 = atoi(Ard1);
        ill = String(value_1);
        lcd.setCursor(13, 3);
        lcd.print("VOL");
        lcd.setCursor(17, 3);
        lcd.print(ill);
        if (value_1 > 0)
          tone(Buzzer, 200 + value_1 , 6);
    }
    }
    else if (check[0] == 'o')
    {
      command = "CH 5 TVN";
 //     lcd.init();
      lcd.setCursor(0, 0);
      lcd.print(command);

      if (str.length() >= 2)
      {
        str.substring(2, 5).toCharArray(Ard1, 5);
        value_1 = atoi(Ard1);
        ill = String(value_1);
        lcd.setCursor(13, 3);
        lcd.print("VOL");
        lcd.setCursor(17, 3);
        lcd.print(ill);
        if (value_1 > 0)
          tone(Buzzer, 200 + value_1 , 6);
    }
    }

    else if (str == "a") { digitalWrite(LED1, HIGH); }
    else if (str == "b") { digitalWrite(LED1, LOW); }
    else if (str == "c") { digitalWrite(LED2, HIGH); }
    else if (str == "d") { digitalWrite(LED2, LOW); }
    else if (str == "e") { digitalWrite(LED3, HIGH); }
    else if (str == "f") { digitalWrite(LED3, LOW); }
    else if (str == "g") { digitalWrite(LED4, HIGH); }
    else if (str == "h") { digitalWrite(LED4, LOW); }
    else if (str == "i") { digitalWrite(relay, HIGH); }
    else if (str == "j") { digitalWrite(relay, LOW); }
    else if (str == "t")  // 닫힘 
    { 
      value = 0;
      servo.write(value);
    }
    else if (str == "s")  // 열림
    {
      value = 100;
      servo.write(value);
    }
    else if (str == "v")  // 닫힘 
    { 
      value2 = 0;
      servo2.write(value2);
    }
    else if (str == "u")  // 열림
    {
      value2 = 100;
      servo2.write(value2);
    }
    
}


    


 /* digitalWrite(relay, HIGH);
  8delay(5000);
  digitalWrite(relay, LOW);
  delay(3000);
 */
 
