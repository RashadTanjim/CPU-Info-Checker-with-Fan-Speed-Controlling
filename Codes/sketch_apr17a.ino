#include <Wire.h>                 //This library allows you to communicate with I2C / TWI devices.
#include <LiquidCrystal_I2C.h>    //include header file for the display to work


LiquidCrystal_I2C lcd(0x27,16,2); //Change address if this is not applicable. 
                                  //Here we used 0x27 address for our display. 
                                  //Because our display supports it. To check the display address, 
                                  //arduino library code can be do that.


void setup(){
  lcd.init();                   // initialize the lcd 
  lcd.backlight();              // to turn on the display backlit
  Serial.begin(9600);           // opens serial port, sets data rate to 9600 bps
}

void loop(){                    //run loop
  
  if (Serial.available()) {     //check if the Seral port is available  
    delay(100);                 // set delay 100 millisecond  
    lcd.clear();                //Clears the LCD screen and positions the cursor in the upper-left corner
    
    while (Serial.available() > 0) { // read all the available characters
                                      
      lcd.write(Serial.read());     //To Display Message On LCD
    }
  }
} 
