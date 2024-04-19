/*
 * USAGE
 * 
 * Send 0 to disable maglock.
 * Maglock will automatically reset after timeout.
 * Send values as ASCII characters. 
 * CR and NL are ignored.
 *
 * Button is onboard but not used.
 * 
 * Attach to maglock via amplifier.
 * (eg. https://www.amazon.ca/gp/product/B07F7SV84V/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
 * 
 * contact: info@devicist.com
*/


const int maglockControlPin = 14;
int maglockSetter = 1;
const int buttonPin = 12;
long timeStamp = 0;
const long timeout = 60000;

void setup() {
  pinMode(maglockControlPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(maglockControlPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String maglockSetterString = Serial.readString();
    maglockSetterString.trim();
    maglockSetter = maglockSetterString.toInt();
    Serial.println(maglockSetter, DEC);
    if(maglockSetter == 0) {
      digitalWrite(maglockControlPin, LOW);
      timeStamp = millis();
    }
  }
  if(millis() > timeStamp + timeout){
    digitalWrite(maglockControlPin, HIGH);
  }
  delay(5);
}