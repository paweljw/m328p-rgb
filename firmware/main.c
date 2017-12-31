#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

void pwm(int which, int cycles, int intensity)
{
  int i = 0;

  for(i = 0; i < cycles; i++) {
    if(i % intensity == 0) PORTD = (which << 0);
    else PORTD = 0;

    _delay_ms(1);
  }
}

int main ()
{
  DDRD |= 0xFF;

  DDRC = 0b1111111110;
  PORTC |= 0b00000001;

  while(1)
  {
    PORTD = 0;
    if((PINC & 0b00000001) == 0) {
      pwm(0b00001100, 10, 2);
    }
  }
}
