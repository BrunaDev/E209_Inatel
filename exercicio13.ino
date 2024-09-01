#define ENTRADAS (0b00011111)  // PB0 a PB4
#define LED1 (1<<PD0)  // Saída no Portal D
#define LED2 (1<<PC0)  // Saída no Portal C

int main(void) {
  // Configura PB0 a PB4 como entradas
  DDRB &= ~ENTRADAS;

  // Configura PD0 e PC0 como saídas
  DDRD |= LED1;
  DDRC |= LED2;

  for (;;) {
    // Lê o estado das entradas
    uint8_t estado = PINB & ENTRADAS;

    // Verifica o padrão intercalado
    if (estado == 0b00010101 || estado == 0b00001010) {
      // LED1 aceso, LED2 apagado
      PORTD |= LED1;
      PORTC &= ~LED2;
    } else if (estado == 0b00011111 || estado == 0b00000000) {
      // LED2 aceso, LED1 apagado
      PORTC |= LED2;
      PORTD &= ~LED1;
    } else {
      // Ambos os LEDs apagados
      PORTD &= ~LED1;
      PORTC &= ~LED2;
    }
  }

  return 0;
}