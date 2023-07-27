int buz_pin = 6;  // initializing the pin 6 as the buzzer pin (internal connection)
// 5 relay (internal connection)
int flame_sensor_pin = 12;  // initializing pin 12 as the sensor output pin
int flame_pin = HIGH;       // state of sensor

void setup() {
  pinMode(buz_pin, OUTPUT);          // declaring buzzzer pin as output pin
  pinMode(LED_BUILTIN, OUTPUT);      //declaring led pin as output pin
  pinMode(flame_sensor_pin, INPUT);  // declaring sensor pin as input pin for Arduino
  Serial.begin(9600);                // setting baud rate at 9600
  //baud rate is the  unit we use to describe the "speed" of communication between the two electronic devices.
}

void loop() {
  flame_pin = digitalRead(flame_sensor_pin);  // reading from the sensor
  if (flame_pin == LOW)                       // applying condition
  {
    Serial.println(" FLAME , FLAME , FLAME ");
    digitalWrite(buz_pin, HIGH);      // if state is high, then turn high the buzzer
    digitalWrite(LED_BUILTIN, HIGH);  //and led
  }

  else {
    Serial.println(" no flame ");
    digitalWrite(buz_pin, LOW);  // otherwise turn it low
    digitalWrite(LED_BUILTIN, LOW);
  }
}