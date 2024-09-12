#define CH (1<<PD2)
#define LED (1<<PD3)

int main(void) {

  // Configura PD2 como entrada
  DDRD &= ~CH;

  // Configura PD3 como saída
  DDRD |= LED;

  for(;;){
    // Verificar o PD2
    if (PIND & CH) {
      // Acender o LED
      PORTD |= LED;
    } else {
      // Apagar o LED
      PORTD &= ~LED;
    }
  }

  return 0;
}