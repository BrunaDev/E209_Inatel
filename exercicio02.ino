#define PINO (1<<PD2)

int main(void) {

  DDRD |= PINO; // PD2 como saída

  PORTD |= PINO; // Acende

  _delay_ms(500);

  PORTD &= ~PINO; // Apaga

  return 0;
}
