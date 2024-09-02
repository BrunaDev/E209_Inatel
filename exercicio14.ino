#include <avr/io.h>

#define BOTAO1 (1 << PB1)
#define BOTAO2 (1 << PB2)
#define BOTAO3 (1 << PB3)
#define BOTAO4 (1 << PB4)
#define TRAVA (1 << PD3)

int main(void) {
    // Configura PB1 a PB4 como entradas com pull-up interno
    DDRB &= ~(BOTAO1 | BOTAO2 | BOTAO3 | BOTAO4);
    PORTB |= (BOTAO1 | BOTAO2 | BOTAO3 | BOTAO4);

    // Configura PD3 como saída
    DDRD |= TRAVA;
    // Inicialmente desligado
    PORTD &= ~TRAVA;

    while (1) {
      // Se PBX estiver pressionado
      if (!(PINB & BOTAO2)) {
          if (!(PINB & BOTAO3)) {
              if (!(PINB & BOTAO4)) {
                  if (!(PINB & BOTAO1)) {
                      // Todos os botões estão pressionados na ordem correta
                      PORTD |= TRAVA;  // Libera a trava
                  } else {
                      PORTD &= ~TRAVA;  // Mantém a trava fechada
                  }
              } else {
                  PORTD &= ~TRAVA;
              }
          } else {
              PORTD &= ~TRAVA;
          }
      } else {
          PORTD &= ~TRAVA;
      }
    }
    return 0;
}
