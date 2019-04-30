#include <Keypad.h>
#include <Servo.h>


Servo myservo; 
const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 11, 10, 9, 8 };
const byte columnPins[columsCount] = { 7, 6, 5, 4 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
void setup() {
  Serial.begin(9600);
   myservo.attach(3);  // vincula el servo al pin digital 9

}

 
void loop() {
   char key = keypad.getKey();
 
   if (key == 1) {
      Serial.println(key);
      myservo.write(180);
      delay(15);
      myservo.write(0);
      delay(15);
      
   }
}
