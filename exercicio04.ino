#include <avr/io.h>

#define PINO_PD5 (1<<PD5)

int main(void) {

  // PD5 como entrada
  DDRD &= ~PINO_PD5;

  // Ativar pull-up interno
  PORTD |= PINO_PD5;

  // Loop infinito para verificar continuamente o estado do pino
  for (;;) {
    // Verificar o estado do pino
    if (PIND & PINO_PD5) {
      Serial.println("Nível lógico alto (puxado pelo pull-up)\n");
    } else {
      Serial.println("Nível lógico baixo\n");
    }
  }

  return 0;
}