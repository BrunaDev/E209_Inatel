## E209 - Lista de Exercícios GPIO
Realizar os exercícios abaixo considerando o microcontrolador ATMega328, e alinguagem C para microcontroladores. Deve ser utilizado o conceito de máscaradebits para preservar os estados lógicos dos pinos durante as operações.

### Exercícios - Lista 01
<p/>
1. Escreva um programa que configure o pino PD2 como saída e, emseguida, useaoperação de OR (|) para acender apenas o bit correspondente a esse pino noregistro PORTD, mantendo os outros bits inalterados.
<p/>
2. Modifique o programa anterior para apagar o bit correspondente ao pino PD2usando a operação de AND (&) com o complemento de 1 (~) no bit desejado.
<p/>
3. Crie um programa que configure os pinos PD3 e PB4 como saídas. Emseguida, use a operação de XOR (^) para alternar o estado dos dois pinos simultaneamente.
<p/>
4. Escreva um programa que configure o pino PD5 como entrada e ative o resistor de pull-up interno. Use a operação de AND (&) no registro PIN para verificar oestado do pino.
<p/>
5. Modifique o programa anterior para usar a operação de AND (&) como complemento de 1 no bit correspondente ao pino desejado no registro PORTpara inverter o estado do pino.
<p/>
6. Crie um programa que configure os pinos PD6 e PD7 como saídas. Emseguida, use a operação de AND com NÃO (&~) para apagar apenas o bit correspondenteao pino D6 no registro DDRD.
<p/>
7. Escreva um programa que configure o pino PD2 como entrada. Use a operaçãode AND (&) para verificar se o bit correspondente a esse pino está setado noregistro PIN e, caso positivo, acenda o LED no pino PD3 usando a operação deOR (|).
<p/>
8. Modifique o programa anterior para apagar o LED no pino PD3 usando a operação de AND com NÃO (&~) se o pino PD2 estiver setado.
<p/>
9. Crie um programa que configure os pinos PD4, PD5 e PD6 como saídas. Use aoperação de OR (|) para definir esses pinos como saídas de forma simultânea.
<p/>
10. Escreva um programa que configure os pinos PD0, PD1 e PD2 como entradas. Use a operação de AND (&) para verificar se todos esses pinos estão definidos como entradas no registro DDRD.
<p/>
11. Utilizando a estrutura dos programas para ATMega328, crie umprograma quealterne o estado de um pino de saída (de sua escolha) sempre que umbotãoemum pino de entrada (de sua escolha) for pressionado.
<p/>
12. Modifique o programa anterior para que sejam utilizados 2 LEDs em2 pinos desaída, e os mesmos devem alternar a cada clique do botão no pino de entrada.
<p/>
13. Crie um programa que possua 5 pinos de entrada no Portal B, 1 LED1 comosaídano Portal D, e um LED2 como saída no Portal C. O programa deve funcionar como um identificador de padrões, onde o LED1 deve permanecer aceso e oLED2 apagado, enquanto as entradas possuírem bits intercalados. Se todos as entradas estiverem com nível lógico alto ou baixo, o LED2 deve permanecer aceso, e o LED1 apagado. Exemplo:
<p/>
ENTRADAS = 10101, LED1 ACESO
<p/>
ENTRADAS = 10010, NENHUM LED ACESO
<p/>
ENTRADAS = 01010, LED1 ACESO
<p/>
ENTRADAS = 00000, LED2 ACESO
<p/>
ENTRADAS = 11111, LED2 ACESO
<p/>
14. Crie um programa em C que funcione como uma fechadura eletrônica. Oprograma deve possuir 4 botões de entrada, com resistor de pull-up interno. Os 4 botões devem ser conectados aos pinos PB1, PB2, PB3 e PB4. O comandoquelibera a trava do sistema deve ser conectado ao pino PD3.
16. O sistema só será liberado se os botões forem pressionados em uma determinadaordem: PB2 -> PB3 -> PB4 -> PB1. Sendo que, nenhum pino pode ser pressionadoesolto, ou seja, ao final da sequência todos pinos devem estar pressionados para validar o acionamento, que será indicado pelo nível lógico alto no pino PD3.
