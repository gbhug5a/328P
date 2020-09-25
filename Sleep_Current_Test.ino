//Arduino IDE

#include <avr/sleep.h>
#include <avr/wdt.h>
int i;

void setup(){

  for (i = 0; i < 20; i++) {          // all pins to one rail or the other
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  ADCSRA = 0;                         // disable ADC for power saving
  wdt_disable();                      // disable WDT for power saving
  set_sleep_mode (SLEEP_MODE_PWR_DOWN); // Deep sleep
  sleep_enable();
  sleep_bod_disable();                // disable brownout detector during sleep
  sleep_cpu();                        // now go to sleep

}

void loop(){
}