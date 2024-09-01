#define SAIDAS 0b01110000  // Definir os pinos PD4, PD5 e PD6 como saídas

int main(void) {
  // Configura os pinos PD4, PD5 e PD6 como saídas de forma simultânea
  DDRD |= SAIDAS;

  return 0;
}
