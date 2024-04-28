/*
 * 
 * Controls a maglock or other dual state (on/off) effector.
 * (eg. https://www.amazon.ca/gp/product/B00JERC00S/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
 * 
 * USAGE
 * 
 * Send 1 to disable the maglock. Send 2 to enable it.
 * Send values as ASCII characters. 
 * CR and NL are ignored.
 * 
 * Attach to maglock via amplifier.
 * (eg. https://www.amazon.ca/gp/product/B07F7SV84V/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
 * Other electronics may be required, such as a flyback diode.
 * 
 * contact: Nicholas Stedman - nick@devicist.com
*/

// #define DEBUG                                 // uncomment to debug to console

const int maglockControlPin = 14;
int maglockControlVal = 0;                    // assign default state
const int buttonPin = 12;                     // unused button on board

void setup() {
  pinMode(maglockControlPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String maglockSetterString = Serial.readString();
    maglockSetterString.trim();
    int maglockSetter = maglockSetterString.toInt();
    if((maglockSetter == 1) || (maglockSetter == 2)) {
#ifdef DEBUG
      Serial.println(maglockSetter, DEC);     // debug the output state
#endif
      maglockSetter--;                        // adjust for output
      maglockControlVal = maglockSetter;      // ignore errant values
    }
    else {
#ifdef DEBUG      
      Serial.println("invalid input");        // debug the output state
#endif      
    }
  }
  digitalWrite(maglockControlPin, maglockControlVal);
  delay(100);                                 // rate limit state change
}