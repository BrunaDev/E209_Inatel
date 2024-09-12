#include <avr/io.h>

#define PINOS (1<<PD0) | (1<<PD1) | (1<<PD2)

int main(void) {
  // Configura PD0, PD1 e PD2 como entradas
  DDRD &= ~PINOS;

  // Verifica se os pinos estão configurados como entrada
  if ((DDRD & PINOS) == 0) {
    Serial.println("Pinos definidos como entrada\n");
  }

  return 0;
}
