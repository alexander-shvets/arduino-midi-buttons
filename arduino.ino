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
  int multiTouch = 0;
  for(int i=0; i < BUTTONS_COUNT; i++){
    int state = digitalRead(BUTTON_PINS[i]);
    if( prevStates[i] != state ){
      if( state == HIGH ){
        for(int j=0; j < BUTTONS_COUNT; j++){
          if( prevStates[j] == HIGH && j != i ) multiTouch++;
        }
        if( multiTouch ){
          Serial.print( multiTouch + BUTTONS_COUNT -1 );
        }else{
          Serial.print( i );
        }
      }
      digitalWrite(LED_BUILTIN, state);
      prevStates[i] = state;
    }
  }
  delay(100);
}