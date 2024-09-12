#define CH (1<<PD2)
#define LED (1<<PD3)

int main(void) {

  // PD2 como entrada
  DDRD &= ~CH;

  // PD3 como saída
  DDRD |= LED;

  for(;;){
    // Verificar o PD2
    if (PIND & CH) {
      // Apagar o LED
      PORTD &= ~LED;
    } else {
      // Acender o LED
      PORTD |= LED;
    }
  }

  return 0;
}
