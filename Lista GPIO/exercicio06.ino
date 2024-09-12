#define LED1 (1<<PD6)
#define LED2 (1<<PD7)
#define LEDS 0b11000000

int main(void) {

  // PD6 e PD7 como saídas
  DDRD |= LEDS;

  //Liga ambos os leds
  PORTD |= LEDS;

  _delay_ms(500);

  // apagar apenas o pino D6
  PORTD &= ~LED1;

  return 0;
}
