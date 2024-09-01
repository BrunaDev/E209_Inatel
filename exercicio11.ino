#define BOTAO (1<<PD2)
#define LED (1<<PD3)

int main(void) {
  // Configura PD2 como entrada (botão)
  DDRD &= ~BOTAO;

  // Ativa o pull-up interno para o botão
  PORTD |= BOTAO;

  // Configura PD3 como saída (LED)
  DDRD |= LED;

  for (;;) {
    // Verifica se o botão foi pressionado (nível lógico baixo)
    if (!(PIND & BOTAO)) {
      // Alterna o estado do LED
      PORTD ^= LED;

      // Espera o botão ser solto para evitar múltiplas alternâncias
      while (!(PIND & BOTAO));
    }
  }

  return 0;
}