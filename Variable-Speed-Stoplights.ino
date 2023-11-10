/*
 * 10/21/2023 - Arduino workshop at 4:00 PM.
 * Traffic lights simulation with variable speed using a potentiometer.
 * 
 * Default times:
 * Traffic light one - 6s Red, 2s Green, 2s Yellow.
 * Traffic light two - 2s Green, 2s Yellow, 6s Red.
 */

// Traffic light one LEDs.
#define RED_ONE 9
#define YELLOW_ONE 8
#define GREEN_ONE 7

// Traffic light two LEDs.
#define RED_TWO 6
#define YELLOW_TWO 5
#define GREEN_TWO 4

// The analog pin that reads the potentiometer.
#define POT_READ_APIN 0

// Used to determine how much time has passed by comparing to millis().
unsigned long timerMillis;

void setup(){
  // Traffic light one.
  pinMode(RED_ONE, OUTPUT);
  pinMode(YELLOW_ONE, OUTPUT);
  pinMode(GREEN_ONE, OUTPUT);

  // Traffic light two.
  pinMode(RED_TWO, OUTPUT);
  pinMode(YELLOW_TWO, OUTPUT);
  pinMode(GREEN_TWO, OUTPUT);
}

void loop(){

  allOff();
  digitalWrite(RED_ONE, HIGH);
  digitalWrite(GREEN_TWO, HIGH);

  timerDelay(2000);

  digitalWrite(GREEN_TWO, LOW);
  digitalWrite(YELLOW_TWO, HIGH);

  timerDelay(2000);

  digitalWrite(YELLOW_TWO, LOW);
  digitalWrite(RED_TWO, HIGH);

  timerDelay(2000);

  allOff();
  digitalWrite(GREEN_ONE, HIGH);
  digitalWrite(RED_TWO, HIGH);

  timerDelay(2000);

  digitalWrite(GREEN_ONE, LOW);
  digitalWrite(YELLOW_ONE, HIGH);

  timerDelay(2000);

  digitalWrite(YELLOW_ONE, LOW);
  digitalWrite(RED_ONE, HIGH);

  timerDelay(2000);

}

// Every LED turns off.
void allOff(){
  digitalWrite(RED_ONE, LOW);
  digitalWrite(YELLOW_ONE, LOW);
  digitalWrite(GREEN_ONE, LOW);
  digitalWrite(RED_TWO, LOW);
  digitalWrite(YELLOW_TWO, LOW);
  digitalWrite(GREEN_TWO, LOW);
}

// Reset the variabl holding millis() for comparison.
inline void timerReset(){
  timerMillis = millis();
}

// TimerDelay still stops code execution, but the use of millis()
//allows me to dynamically adjust the length of the time to wait.
void timerDelay(unsigned long delayLength){
  timerReset();
  while(true){               // delayLength is multiplied by a percent, one gained from reading the analog voltage.
    if(millis() - timerMillis > delayLength * analogRead(POT_READ_APIN) / 1023) break;
  }
}
