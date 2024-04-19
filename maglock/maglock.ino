/*
 * USAGE
 * 
 * Send 1 to enable the maglock, send 0 to disable it.
 * Send values as ASCII characters. 
 * CR and NL are ignored.
 * 
 * Attach to maglock via amplifier.
 * (eg. https://www.amazon.ca/gp/product/B07F7SV84V/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
 * 
 * contact: info@devicist.com
*/


const int maglockControlPin = 14;
int maglockSetter = 1;
const int buttonPin = 12;

void setup() {
  pinMode(maglockControlPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String maglockSetterString = Serial.readString();
    maglockSetterString.trim();
    maglockSetter = maglockSetterString.toInt();
    if(maglockSetter != 0) maglockSetter = 1;
    Serial.println(maglockSetter, DEC);
  }
  digitalWrite(maglockControlPin, maglockSetter);
  delay(5);
}