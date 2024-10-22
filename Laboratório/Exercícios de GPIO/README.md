### E209 - Exercicio_1-Lista
01 - Em uma esteira de transporte, foi instalado um sistema de verificação de peças posicionadas de forma errada. Elabore um firmware para controlar o sistema, seguindo os passos apresentados abaixo.
- Ao pressionar o botão LIGA (NA) a esteira entra em movimento (MOTOR = HIGH);
- Ao pressionar o botão DESLIGA (NF) a esteira para seu movimento (MOTOR = LOW);
- Caso aconteça o amontoamento de peças (S1 = HIGH), a esteira deverá parar imediatamente e alarme deverá ser ligado (ALARME = HIGH);
- Para desligar o ALARME, as peças deverão estar desamontoadas (S1 = LOW) e o botão LIGA deve ser pressionado.

![{8841F26D-3E5A-427F-8301-C7F744FE6961}](https://github.com/user-attachments/assets/36e90340-1fad-4eb6-9e5c-373840568cf3)

##### Solução no SimulIDE:
![{EFFC3C3E-4F33-43C2-936E-A53796AD16A8}](https://github.com/user-attachments/assets/7b699dcd-2026-450b-88ef-e003c3a3e70f)


### E209 - Exercicio_2-Lista_Variacoes
02 - Uma cidade está buscando implementar um semáforo preferencial para pedestres. Um microcontrolador é usado para controlar o sistema com três LEDs (vermelho, Amarelo e Azul) e um
botão para ativação. Escreva um firmware que implemente a seguinte lógica:
- Quando o sistema estiver ligado, apenas o LED vermelho deve estar aceso;
- Ao pressionar o botão, o LED amarelo deve piscar por 3 segundos (LIGADO por 0,5s e DESLIGADO por 0,5s) e depois apagar;
- Após o LED amarelo apagar, o LED azul deve acender e permanecer aceso até que o botão seja pressionado novamente;
- Quando o botão for pressionado novamente, o processo volta ao seu estado original, descrito no passo A.

##### Solução no SimulIDE:
![{081E3AFC-04C1-4471-AE53-211AFD380F9C}](https://github.com/user-attachments/assets/9c66cc92-14ba-4773-a62a-e31577fbdd22)


###### Monitor: Marcos Henrique <--> E209-L3
