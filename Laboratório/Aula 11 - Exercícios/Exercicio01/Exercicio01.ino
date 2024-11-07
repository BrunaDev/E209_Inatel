#define BTN_LIGA_PIN PD2
#define BTN_DESLIGA_PIN PD3
#define LED1_PIN PB0
#define LED2_PIN PB1
#define MOTOR_PWM_PIN PB3  // PWM para motor (OC0A)

volatile uint8_t motor_speed = 0;  // Velocidade do motor
volatile uint8_t system_active = 0;  // Status do sistema (ligado ou desligado)

// Função de inicialização do PWM
void pwm_init() {
    DDRB |= (1 << MOTOR_PWM_PIN);  // PB3 como saída (PWM)
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);  // Fast PWM
    TCCR0B |= (1 << CS00);  // Sem prescaler
    OCR0A = 0;  // Inicia com o motor desligado (PWM 0%)
}

// Função de configuração dos pinos
void setup_pins() {
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN);  // Configura LEDs como saída
    DDRD &= ~((1 << BTN_LIGA_PIN) | (1 << BTN_DESLIGA_PIN));  // Botões como entrada
    PORTD |= (1 << BTN_LIGA_PIN) | (1 << BTN_DESLIGA_PIN);  // Ativa pull-up nos botões
}

// Função de interrupções externas
void interrupt_init() {
    EICRA |= (1 << ISC01) | (1 << ISC00);  // Interrupção por borda de subida no BTN_LIGA
    EIMSK |= (1 << INT0);  // Ativa INT0 (BTN_LIGA)
    EICRA |= (1 << ISC11) | (1 << ISC10);  // Interrupção por borda de subida no BTN_DESLIGA
    EIMSK |= (1 << INT1);  // Ativa INT1 (BTN_DESLIGA)
}

// Função de inicialização do Timer1 para controle de tempo
void timer1_init() {
    TCCR1B |= (1 << WGM12);  // Modo CTC
    OCR1A = 15624;
    TCCR1B |= (1 << CS12) | (1 << CS10);  // Prescaler de 1024
    TIMSK1 |= (1 << OCIE1A);  // Habilita interrupção do Timer1
}

// Interrupção quando o botão LIGA é pressionado
ISR(INT0_vect) {
    if (!system_active) {
        system_active = 1;  // Ativa o sistema
        motor_speed = 0;  // Reseta a velocidade do motor
        OCR0A = motor_speed;  // PWM para 0%
        timer1_init();  // Inicia o Timer1 para controle da velocidade
        PORTB |= (1 << LED1_PIN);  // Liga o LED1
    }
}

// Interrupção quando o botão DESLIGA é pressionado
ISR(INT1_vect) {
    system_active = 0;  // Desativa o sistema
    motor_speed = 0;    // Reseta a velocidade do motor
    OCR0A = 0;          // Desativa o PWM (motor desligado)
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN));  // Desliga os LEDs
    TCCR1B &= ~(1 << CS12);  // Para o Timer1
}

// Interrupção do Timer1 para controle do tempo e velocidade do motor
ISR(TIMER1_COMPA_vect) {
    if (system_active) {
        // Incrementa a velocidade do motor
        if (motor_speed < 255) {
            motor_speed += 25;  // Aumenta 25 a cada ciclo (10 segundos para atingir 100%)
            OCR0A = motor_speed;  // Atualiza o PWM
        }

        // Controle dos LEDs
        if (motor_speed >= 128 && motor_speed < 255) {  // Entre 50% e 100% da velocidade
            PORTB |= (1 << LED1_PIN);   // Liga o LED1
            PORTB &= ~(1 << LED2_PIN);  // Desliga o LED2
        } else if (motor_speed >= 255) {  // Quando atingir 100%
            PORTB &= ~(1 << LED1_PIN);   // Desliga o LED1
            PORTB |= (1 << LED2_PIN);    // Liga o LED2
            TCCR1B &= ~(1 << CS12);      // Para o Timer1 após atingir 100%
        }
    }
}

int main() {
    setup_pins();
    pwm_init();
    interrupt_init();

    sei();
    
    while (1) {
    }
}