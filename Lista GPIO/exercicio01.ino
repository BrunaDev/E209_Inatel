#define PINO (1<<PD2)

int main(void){

  //PD2 como saída
  DDRD |= PINO;

  // Liga o PD2
  PORTD |= PINO;

  return 0;
}
