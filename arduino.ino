const int BUTTON_PINS[] = {2, 4, 7, 8};
const int BUTTONS_COUNT = 4;
 
void setup() {
  Serial.begin(9600);
  
  for(int i=0; i < BUTTONS_COUNT; i++){
    pinMode(BUTTON_PINS[i], INPUT);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  
  //Serial.println("start");
}


int prevStates[BUTTONS_COUNT];

void loop() {
  for(int i=0; i < BUTTONS_COUNT; i++){
    int state = digitalRead(BUTTON_PINS[i]);
    if( prevStates[i] != state ){
      if( state == HIGH ){
        Serial.print( i );
        //Serial.flush();
      } else {
         // Не подаём напряжение
      }
      digitalWrite(LED_BUILTIN, state);
      prevStates[i] = state;
    }
  }
  delay(100);
}