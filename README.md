## E209 - Lista de Exercícios GPIO
Realizar os exercícios abaixo considerando o microcontrolador ATMega328, e alinguagem C para microcontroladores. Deve ser utilizado o conceito de máscaradebits para preservar os estados lógicos dos pinos durante as operações.

### Exercícios - Lista 01

1. Escreva um programa que configure o pino **PD2 como saída** e, em seguida, use a operação de **OR (|)** para acender apenas o bit correspondente a esse pino no registro PORTD, mantendo os outros bits inalterados.
2. Modifique o programa anterior para apagar o bit correspondente ao pino PD2 usando a operação de **AND (&)** com o complemento de 1 (~) no bit desejado.
3. Crie um programa que configure os pinos **PD3 e PB4 como saídas**. Em seguida, use a operação de **XOR (^)** para alternar o estado dos dois pinos simultaneamente.
4. Escreva um programa que configure o pino **PD5 como entrada e ative o resistor de pull-up interno**. Use a operação de **AND (&)** no registro PIN para verificar o estado do pino.
5. Modifique o programa anterior para usar a operação de **AND (&)** como complemento de 1 no bit correspondente ao pino desejado no registro PORT para inverter o estado do pino.
6. Crie um programa que configure os pinos **PD6 e PD7 como saídas**. Em seguida, use a operação de **AND com NÃO (&~)** para apagar apenas o bit correspondenteao pino D6 no registro DDRD.
7. Escreva um programa que configure o pino **PD2 como entrada**. Use a operação de **AND (&)** para verificar se o bit correspondente a esse pino está setado no registro PIN e, caso positivo, acenda o LED no pino PD3 usando a operação de **OR (|)**.
8. Modifique o programa anterior para apagar o LED no pino PD3 usando a operação de **AND com NÃO (&~)** se o pino PD2 estiver setado.
9. Crie um programa que configure os pinos **PD4, PD5 e PD6 como saídas**. Use a operação de **OR (|)** para definir esses pinos como saídas de forma simultânea.
10. Escreva um programa que configure os pinos **PD0, PD1 e PD2 como entradas**. Use a operação de **AND (&)** para verificar se todos esses pinos estão definidos como entradas no registro DDRD.
11. Utilizando a estrutura dos programas para ATMega328, crie um programa que **alterne o estado de um pino de saída** (de sua escolha) sempre que um botão em um pino de entrada (de sua escolha) for pressionado.
12. Modifique o programa anterior para que sejam utilizados 2 LEDs em 2 pinos de saída, e os mesmos devem **alternar a cada clique do botão** no pino de entrada.
13. Crie um programa que possua 5 pinos de entrada no Portal B, 1 LED1 como saída no Portal D, e um LED2 como saída no Portal C. O programa deve funcionar como um identificador de padrões, onde o **LED1 deve permanecer aceso e o LED2 apagado, enquanto as entradas possuírem bits intercalados**. Se todos as entradas estiverem com nível lógico alto ou baixo, o LED2 deve permanecer aceso, e o LED1 apagado. Exemplo:

| Entradas  | Saídas |
| ------------- | ------------- |
| 10101  | LED1 ACESO  |
| 10010  | NENHUM LED ACESO  |
| 01010  | LED1 ACESO  |
| 00000  | LED2 ACESO  |
| 11111  | LED2 ACESO  |

14. Crie um programa em C que funcione como uma fechadura eletrônica. O programa deve possuir 4 botões de entrada, com resistor de pull-up interno. Os 4 botões devem ser conectados aos pinos PB1, PB2, PB3 e PB4. O comando que libera a trava do sistema deve ser conectado ao pino PD3. O sistema só será liberado se os botões forem pressionados em uma determinada ordem: **PB2 -> PB3 -> PB4 -> PB1**. Sendo que, nenhum pino pode ser pressionado e solto, ou seja, **ao final da sequência todos pinos devem estar pressionados para validar o acionamento**, que será indicado pelo nível lógico alto no pino PD3.
