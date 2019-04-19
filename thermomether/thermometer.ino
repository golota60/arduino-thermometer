#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//the libraries used are not native to arduino software! If I don't forget ill add the links in the README file, but If i forget don't worry, they are easy to find

float temp;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.backlight(); // power on the display
//lcd.backlight(); // the second backlight is used to power off the display

pinMode(A0,INPUT); // our LM35 sensor pin

}

void loop() {
lcd.setCursor(0,0); //setting the cursor in the first line of the first row

//LM35 sensor doesn't give us temperature in Celcius or something, thats why we need to convert it into Celcius and it looks like this
//We power our LM35 with 5volts of power, and we get readings from 0 to 1023 so we divide 5/1024=0.0048828125
//then we multiply by 100 to get the correct reading which leaves us at 0.4828125 multiplied by the reading
temp = analogRead(A0);
temp = temp * 0.48828125;

//print temperatury
lcd.print("Temp:");
lcd.print(temp);

lcd.print((char)223);
lcd.print("C");

//im setting up a delay so the number on the LCD doesn't rapidly change and annoy me
delay(2000);




}
