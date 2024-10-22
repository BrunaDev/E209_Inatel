#include <avr/io.h>
#include <util/delay.h>

#define LED_VERMELHO (1 << PC1)  // LED vermelho
#define LED_AMARELO (1 << PC2)   // LED amarelo
#define LED_AZUL (1 << PC3)      // LED azul
#define BOTAO (1 << PC4)         // Botão para ativação

int main(void) {
    // Saídas
    DDRC |= LED_VERMELHO;
    DDRC |= LED_AMARELO;
    DDRC |= LED_AZUL;

    // Entrada
    DDRC &= ~BOTAO;
    // Habilitar pull-up para o botão
    PORTC |= BOTAO;

    // Inicialmente, apenas o LED vermelho ligado
    PORTC |= LED_VERMELHO;
    PORTC &= ~LED_AMARELO;
    PORTC &= ~LED_AZUL;

    int estado = 0;  // 0: Vermelho, 1: Amarelo piscando, 2: Azul aceso

    while (1) {
        if (!(PINC & BOTAO)) {
            _delay_ms(50);
            while (!(PINC & BOTAO));

            if (estado == 0) {
                PORTC &= ~LED_VERMELHO;
                
                // Piscar o LED amarelo por 3 segundos (0,5s ligado, 0,5s desligado)
                for (int i = 0; i < 3; i++) {
                    PORTC |= LED_AMARELO;
                    _delay_ms(500);
                    PORTC &= ~LED_AMARELO;
                    _delay_ms(500);
                }
                
                PORTC |= LED_AZUL;
                estado = 1;
            } else if (estado == 1) {
                PORTC &= ~LED_AZUL;
                PORTC |= LED_VERMELHO;
                estado = 0;
            }
        }
    }

    return 0;
}