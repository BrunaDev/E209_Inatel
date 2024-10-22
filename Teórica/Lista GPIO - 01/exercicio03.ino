#define LED1 (1 << PD3)  // Bit 3 do PORTD
#define LED2 (1 << PB4)  // Bit 4 do PORTB

int main(void) {
  // Configura PD3 e PB4 como saídas
  DDRD |= LED1;  // PD3 como saída
  DDRB |= LED2;  // PB4 como saída

  for (;;) {
    // Alterna o estado de PD3 e PB4
    PORTD ^= LED1;  // Alterna o estado de PD3
    PORTB ^= LED2;  // Alterna o estado de PB4

    // para visualizar melhor
    _delay_ms(1000);
  }

  return 0;
}