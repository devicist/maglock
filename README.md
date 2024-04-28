# maglock

Control a maglock or other dual state (on/off) actuator.  
(eg. https://www.amazon.ca/gp/product/B00JERC00S/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)

### USAGE

Send 0 to unlock/disable the maglock. Send 1 to lock/enable it.  
Send values as ASCII characters.  
CR and NL are ignored.  
Errant values are ignored.

Tested on an Arduino Uno.

Attach to maglock via amplifier.  
(eg. https://www.amazon.ca/gp/product/B07F7SV84V/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)  
Other electronics may be required, such as a flyback diode.

contact: Nicholas Stedman - nick@devicist.com
