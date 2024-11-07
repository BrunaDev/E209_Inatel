#define BTN_PIN PD // Botão de leitura
#define LED_PIN PB0
#define ADC_PIN PA0 // Entrada analógica

volatile uint16_t last_adc_value = 0; // Última leitura do ADC
volatile uint8_t counter = 0; // Contador de leituras que atendem a condição
volatile uint8_t led_on = 0; // Flag para controle do LED piscando

// Função de inicialização do ADC
void adc_init() {
    // Configura o ADC para ler o pino PA0 (entrada analógica)
    ADMUX = (1 << MUX0) | (1 << REFS0);  // Seleciona PA0 e referência AVCC
    ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);  // Habilita o ADC e define o prescaler para 64
}

// Função para iniciar uma conversão ADC e esperar o resultado
uint16_t read_adc() {
    ADCSRA |= (1 << ADSC);  // Inicia a conversão
    while (ADCSRA & (1 << ADSC));  // Espera a conversão terminar
    return ADC;
}

// Função - Configuração dos pinos
void setup_pins() {
    DDRB |= (1 << LED_PIN);    // Configura o LED como saída
    DDRD &= ~(1 << BTN_PIN);   // Configura o botão de leitura como entrada
    PORTD |= (1 << BTN_PIN);   // Habilita o pull-up no pino do botão
}

// Função de inicialização do Timer para controle do piscar do LED
void timer_init() {
    TCCR0A = (1 << WGM01) | (1 << WGM00);  // Modo de CTC (Clear Timer on Compare Match)
    TCCR0B = (1 << CS01) | (1 << CS00);    // Prescaler de 64
    OCR0A = 249;  // Valor para gerar interrupção a cada 250ms (2Hz)
    TIMSK0 |= (1 << OCIE0A);  // Habilita a interrupção do Timer0
}

// Interrupção do botão de leitura
ISR(INT0_vect) {
    uint16_t adc_value = read_adc();  // Lê o valor do ADC
    if (last_adc_value == 0) {
        // Para a primeira leitura, considera 0 e não faz contagem
        last_adc_value = adc_value;
        return;
    }

    // Verifica se a leitura atual é 20% menor que a anterior
    if (adc_value < (last_adc_value - last_adc_value / 5)) {
        counter++;  // Incrementa o contador
    }

    // Atualiza a última leitura
    last_adc_value = adc_value;

    // Quando o contador atingir 5, aciona o LED
    if (counter >= 5) {
        PORTB |= (1 << LED_PIN);  // Aciona o LED
    }

    // Quando o contador atingir 10 ou mais, começa a piscar o LED
    if (counter >= 10) {
        led_on = 1;  // Marca para piscar o LED
    }
}

// Interrupção do Timer para controle do piscar do LED
ISR(TIMER0_COMPA_vect) {
    if (led_on) {
        static uint8_t led_state = 0;
        if (led_state == 0) {
            PORTB |= (1 << LED_PIN);  // Liga o LED
            led_state = 1;
        } else {
            PORTB &= ~(1 << LED_PIN);  // Desliga o LED
            led_state = 0;
        }
    }
}

int main() {
    setup_pins();
    adc_init();
    timer_init();
    sei();

    // Configuração da interrupção externa para o botão de leitura
    EICRA |= (1 << ISC01) | (1 << ISC00);  // Interrupção por borda de subida no BTN_PIN
    EIMSK |= (1 << INT0);  // Habilita a interrupção externa INT0

    while (1) {
    }

    return 0;
}