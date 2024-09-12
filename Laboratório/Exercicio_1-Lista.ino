#include <avr/io.h>

#define NA (1 << PD1)      // Botão LIGA
#define NF (1 << PD2)      // Botão DESLIGA
#define S1 (1 << PD3)      // Sensor de amontoamento
#define MOTOR (1 << PD4)   // Controle do motor
#define ALARME (1 << PD5)  // Controle do alarme

int main(void) {
    // Configurando as portas como saídas
    DDRD |= MOTOR;
    DDRD |= ALARME;

    // Configurando as portas como entradas
    DDRD &= ~S1;
    DDRD &= ~NA;
    DDRD &= ~NF;

    // Inicialmente, motor e alarme desligados
    PORTD &= ~MOTOR;
    PORTD &= ~ALARME;

    while (1) {
        // Verificar se o botão LIGA foi pressionado e o sensor S1 está LOW (sem amontoamento)
        if ((PIND & NA) && !(PIND & S1)) {
            // Liga motor
            PORTD |= MOTOR;
            // Desliga alarme, se estiver ligado
            PORTD &= ~ALARME;
        }

        // Verificar se o botão DESLIGA foi pressionado
        if (PIND & NF) {
            // Desliga motor
            PORTD &= ~MOTOR;
        }

        // Verificar se o sensor S1 detectou amontoamento
        if (PIND & S1) {
            // Desliga motor e liga alarme
            PORTD &= ~MOTOR;
            PORTD |= ALARME;
        }
    }

    return 0;
}