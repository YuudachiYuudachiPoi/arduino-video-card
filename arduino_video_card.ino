/*
 * @Author: Howie Hong(希理)
 * @Date: 2021-01-01 04:45:11
 * @LastEditors: Howie Hong(希理)
 * @LastEditTime: 2021-01-01 23:10:42
 * @Description: 
 */
#include <avr/sleep.h>
volatile int line = 0;
ISR (TIMER1_OVF_vect) {
  line++;
  if (line==4) {
    digitalWrite(3,LOW);
  }else if (line==628) {
    digitalWrite(3,HIGH);
    line = 0;
  }
}

void setup() {
  pinMode(3,OUTPUT);
  pinMode(10, OUTPUT);
  TCCR1A = _BV(COM1A0) | _BV(COM1B1) | _BV(WGM10) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(CS10);
  OCR1A = 211;
  OCR1B = 26;
  TIFR1 = _BV(TOV1);
  TIMSK1 = _BV(TOIE1);
  set_sleep_mode (SLEEP_MODE_IDLE); 

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  int timing = 2080;
  sleep_mode();
  digitalWrite(6,LOW);
  delayMicroseconds(timing);
  sleep_mode();
  digitalWrite(5,HIGH);
  delayMicroseconds(timing);
  sleep_mode();
  digitalWrite(4,LOW);
  delayMicroseconds(timing);
  sleep_mode();
  digitalWrite(6,HIGH);
  delayMicroseconds(timing);
  sleep_mode();
  digitalWrite(5,LOW);
  delayMicroseconds(timing);
  sleep_mode();
  digitalWrite(4,HIGH);
  delayMicroseconds(timing);
}