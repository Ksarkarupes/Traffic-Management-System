const int ldr_pin1 = 7;
const int ldr_pin2 = 6;
const int ldr_pin3 = 5;
const int ldr_pin4 = 4;
const int led_pin0 = 10;
const int led_pin1 = 13;
const int led_pin2 = 12;
const long onDuration = 5000;
const long offDuration = 5000;
int LEDState1 = HIGH;
int LEDState2 = LOW;
long rememberTime = 0;
int time_1;

void setup() {
  //   put your setup code here, to run once:
  pinMode(ldr_pin1, INPUT);
  pinMode(ldr_pin2, INPUT);
  pinMode(ldr_pin3, INPUT);
  pinMode(ldr_pin4, INPUT);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin0, OUTPUT);
  digitalWrite(led_pin1, LEDState1);
  digitalWrite(led_pin2, LEDState2);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    String txt = Serial.readString();
    time_1 = txt.toInt();
    Serial.println(time_1);
    if(time_1 >= 18 || time_1 <=5){
      digitalWrite( led_pin0, HIGH);
    }else{
      digitalWrite( led_pin0, LOW);
    }
    if (time_1 >= 22 || time_1 <=7) {
      if ( (digitalRead( ldr_pin1 ) == 1 || digitalRead( ldr_pin2 ) == 1) && (digitalRead( ldr_pin3 ) == 0 || digitalRead( ldr_pin4 ) == 0)) {
        digitalWrite( led_pin1, HIGH);
        digitalWrite( led_pin2, LOW);
      }
      else if((digitalRead( ldr_pin1 ) == 0 || digitalRead( ldr_pin2 ) == 0) && (digitalRead( ldr_pin3 ) == 1) || digitalRead( ldr_pin4 ) == 1){
        digitalWrite( led_pin1 , LOW);
        digitalWrite( led_pin2, HIGH);
      }
    } else {
      if (LEDState1 == HIGH) {
        if (millis() - rememberTime >= onDuration) {
          LEDState1 = LOW;
          LEDState2 = HIGH;
          digitalWrite(led_pin1, LOW);
          digitalWrite(led_pin2, HIGH);
          rememberTime = millis();
        }
      } else {
        if (millis() - rememberTime >= offDuration) {
          LEDState1 = HIGH;
          LEDState2 = LOW;
          digitalWrite(led_pin1, HIGH);
          digitalWrite(led_pin2, LOW);
          rememberTime = millis();
        }
      }
    }
  }


}
