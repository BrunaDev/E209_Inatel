#define BOTAO (1<<PD2)
#define LED1 (1<<PD3)
#define LED2 (1<<PD4)

int main(void) {
  // Configura PD2 como entrada (botão)
  DDRD &= ~BOTAO;

  // Ativa o pull-up interno para o botão
  PORTD |= BOTAO;

  // Configura PD3 e PD4 como saídas (LEDs)
  DDRD |= LED1 | LED2;

  // Estado inicial dos LEDs
  PORTD &= ~(LED1);
  PORTD |= (LED2);

  for (;;) {
    // Verifica se o botão foi pressionado (nível lógico baixo)
    if (!(PIND & BOTAO)) {
      // Alterna os LEDs
      PORTD ^= (LED1 | LED2);

      // Espera o botão ser solto para evitar múltiplas alternâncias
      while (!(PIND & BOTAO));
    }
  }

  return 0;
}