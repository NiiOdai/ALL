// Initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2); 

//LED to arduino digital pin 8;
int redled = 8;
//buzzer to arduino pin 6
int buzzer = 6;
//Gas Sensor to arduino analog pin A1
int sensor = A1;
// Threshold value for sensor
int sensorThresh = 700;
//initialize 
int timElapsed=0;

void setup(){
  pinMode(redled, OUTPUT);//Set LED -pin 8 as an output
  pinMode(buzzer,OUTPUT);//Set LED - pin 6 as an output
  pinMode(sensor,INPUT);//Set Gas sensor - pin A1 as an input
  Serial.begin(9600);
  //Set the characters and column numbers.
  lcd.begin(16,2);
}

void loop()
{
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  //checks if it has reached the threshold value
  if(analogValue>sensorThresh)
  {
    digitalWrite(redled,HIGH);//turn LED on
    delay(50);// small delay
    digitalWrite(redled,LOW);
    delay(50);//small delay 
    //if  threshold is exceeded for less than or equal to 10 sec
       if(timElapsed <= 10){
        tone(buzzer,1000,200);
        lcd.clear();
        lcd.setCursor(4,0); //Set the Row 4, Col 0 position.
          lcd.print("ALERT!");
        delay(1000);// delays for 1 sec
        lcd.clear();//clears the LCD screen
      }
      //if  threshold is exceeded for more than 10 sec
      if(timElapsed >10){
        lcd.setCursor(4,1); //Set the Row 4, Col 1 position.
        lcd.print("EVACUATE");//Displays "EVACUATE" on the LCD screen
            tone(buzzer,1000,10000);//Send 1KHz sound signal..
        
      }
   timElapsed++;//Increases timElapsed counter by 1.
  }
  //no tone,LED off & LCD screen displays
    else{
      digitalWrite(redled,LOW);
      noTone(buzzer);
      lcd.clear();
      lcd.setCursor(4,0); //Set the Row 4, Col 0 position.
      lcd.print("SAFE");//Displays "SAFE" on LCD screen.
      delay(1000);//delay for 1 sec
      lcd.clear();//clear the LCD screen
      lcd.setCursor(4,1); //Set the Row 4, Col 1 position.
      lcd.print("ALL CLEAR");//Displays "All CLEAR" on LCD Screen.
      delay(1000);//delay for 1 sec
      timElapsed=0;//initialize time elapsed to 0 
  }    
}
