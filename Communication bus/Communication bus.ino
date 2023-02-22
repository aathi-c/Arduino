
int blink_speed = 0;
// Setup Loop

void setup() {         
  Serial.begin(9600);                                                      // Start Setup Loop
  // pins 2 and 3 are input (1st UNO)
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  // pins 5 and 6 are send pins
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  // pins 7 and 8 as receive pins
  pinMode(7, INPUT);
  pinMode(8, INPUT);


// Setup the Arudino's on board LED pin so it can be used to indicate when 
// the system is ready to process a signal
  pinMode(LED_BUILTIN, OUTPUT);                                               
}                                                                             

void loop() {          
bool value_1 = digitalRead(2);
bool value_2 = digitalRead(3);
digitalWrite(5, value_1);
digitalWrite(6, value_2);

// if 5 and 6 are low blink speed => 0 , 1, 2, 3
if (digitalRead(7) == HIGH && digitalRead(8) == HIGH){
  blink_speed = 0;
}
else if (digitalRead(7) == HIGH && digitalRead(8) == LOW){
  blink_speed = 1;
}
else if (digitalRead(7) == LOW && digitalRead(8) == HIGH){
  blink_speed = 2;
}
else{
  blink_speed = 3;
}

switch (blink_speed) {
  case 0:
    Serial.print("Case 0");
    digitalWrite(13, HIGH);
    break;
  case 1:
    Serial.print("Case 1");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    break;
  case 2:
    Serial.print("Case 2");
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    break;
  case 3:
    Serial.print("Case 3");
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(250);
    break;
}
                                                                           
}                                                                             // End Main Loop
