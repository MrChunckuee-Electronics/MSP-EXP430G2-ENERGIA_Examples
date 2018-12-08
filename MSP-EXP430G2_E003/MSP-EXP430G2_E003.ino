
/*******************************************************************************
 *
 *                  Control basico de LEDs RGB
 *
 *******************************************************************************
 * FileName:        MSP-EXP430G2_E003
 * Processor:       MSP430G2231
 * Complier:        Energia 1.6.10E18
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo enciende los LEDs RGB por colores, haciendo un 
 *                  total de 8 combinaciones posibles.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.0.0     07/12/2018      Creación del firmware
 ******************************************************************************/
 
#define pinButton     PUSH2    
#define pinRedLED     P1_5
#define pinGreenLED   P1_4
#define pinBlueLED    P1_6

//unsigned char count;
unsigned int buttonState, buttonTicks, currentButtonState, lastButtonState, buttonFlag;

void setup() {
  pinMode(pinRedLED, OUTPUT);     
  pinMode(pinGreenLED, OUTPUT); 
  pinMode(pinBlueLED, OUTPUT);  
  digitalWrite(pinRedLED, LOW); 
  digitalWrite(pinGreenLED, LOW); 
  digitalWrite(pinBlueLED, LOW); 
  //Clear all variable
  buttonState=0;
  buttonTicks=0;
  currentButtonState=0;
  lastButtonState=0;
  buttonFlag = 0;
}

void loop() {
  GetInput();
  SetOption(buttonFlag);
}

void GetInput(void){
  // Push Button debounce
  if (buttonState != digitalRead(pinButton)){
    if (buttonTicks > 20){
      buttonState = digitalRead(pinButton);
      buttonTicks = 0;
      }
      else buttonTicks++;
  }
  else buttonTicks = 0;
  // Process the push button
  currentButtonState = buttonState;
  if (currentButtonState == 0 && lastButtonState == 1){
    buttonFlag+=1;
    if (buttonFlag > 8) buttonFlag = 1;
  }
  lastButtonState = currentButtonState;   
}

void SetOption(unsigned int option){
    switch (option){
    case 1: //Red
      digitalWrite(pinRedLED, HIGH); 
      digitalWrite(pinGreenLED, LOW); 
      digitalWrite(pinBlueLED, LOW);
      break;
    case 2: //Green
      digitalWrite(pinRedLED, LOW); 
      digitalWrite(pinGreenLED, HIGH); 
      digitalWrite(pinBlueLED, LOW);
    break;
    case 3: //Yellow
      digitalWrite(pinRedLED, HIGH); 
      digitalWrite(pinGreenLED, HIGH); 
      digitalWrite(pinBlueLED, LOW);
      break;
    case 4: //Blue
      digitalWrite(pinRedLED, LOW); 
      digitalWrite(pinGreenLED, LOW); 
      digitalWrite(pinBlueLED, HIGH);
    break;
    case 5: //Purple
      digitalWrite(pinRedLED, HIGH); 
      digitalWrite(pinGreenLED, LOW); 
      digitalWrite(pinBlueLED, HIGH);
      break;
    case 6: //Cyan
      digitalWrite(pinRedLED, LOW); 
      digitalWrite(pinGreenLED, HIGH); 
      digitalWrite(pinBlueLED, HIGH);
    break;
    case 7: //White
      digitalWrite(pinRedLED, HIGH); 
      digitalWrite(pinGreenLED, HIGH); 
      digitalWrite(pinBlueLED, HIGH);
    break;
    case 8: //All OFF
      digitalWrite(pinRedLED, LOW); 
      digitalWrite(pinGreenLED, LOW); 
      digitalWrite(pinBlueLED, LOW);
    break;
    default: //All OFF
      digitalWrite(pinRedLED, LOW); 
      digitalWrite(pinGreenLED, LOW); 
      digitalWrite(pinBlueLED, LOW); 
    break;
  }
}


