Jogo de dominó em #C
===================

Jogo de dominó criado em linguagem #C pelo grupo ProjetoD

ÍNDICE
-------------
<!--ts-->
   * [Sobre o ProjetoD](#sobre-o-projetoD)
   * [Descrição do Jogo](#descrição-do-jogo)
   * [Regras do Jogo](#regras-do-jogo)
   * [Estrutura de Dados](#estrutura-de-dados)
   * [Organização dos módulos do programa](#organização-dos-módulos-do-programa)
<!--te-->

Sobre o ProjetoD
----------------

O ProjetoD é um grupo criado para a matéria de Laboratório de Programação do curso de ciência da computação da Pontifícia Universidade Católica de São Paulo. O intuito desta matéria é aplicar os conhecimentos obtidos no decorrer do curso para realização de projetos, bem como a documentação e apresentação dos mesmos.
O Projeto D é composto pelos seguintes integrantes:

    * Gabriel Antony Cadima Ciziks
    * Lucas Guitti Bonando
    * Tiago Rausch de Oliveira

Descrição do Jogo
----------------
O jogo de dominó é organizado por peças (ou pedras) formadas por números indicados por meio de pontos. Como cada peça é composta por dois números, formando assim um retângulo 
por meio de dois quadrados congruentes. O conjunto de dominó é formado por 28 peças retangulares. Nessas peças aparecem todas as combinações possíveis de números que vão de 0 a 
6, e esses números inclusive podem se repetir, portanto, cada número aparecerá oito vezes. 

Regras do Jogo
--------------
Você deverá escolher entre um jogador (jogador vs computador) ou dois jogadores (jogador vs jogador). Cada jogador recebe sete peças e pode comprar sempre que precisar de uma peça para poder jogar e quantas vezes forem necessárias. Dá-se início ao jogo o jogador que tiver a peça com os números repetidos mais altos. Caso nenhum jogador tenha peças iguais em sua mão, os jogadores decidem entre si quem começa o jogo. Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas na mesa, de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde está sendo colocada. Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador. Se um jogador não puder jogar, deverá “comprar” do monte tantas peças como forem necessárias. Se não houver peças no monte, passará o turno ao seguinte jogador. A partida continua com os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes situações:

  • Quando um jogador coloca sua última peça na mesa.

  • Quando nenhum jogador têm uma peça valida para se colocar na mesa e não há mais peças para "comprar" no monte. Neste caso, declara-se vencedor aquele jogador que tiver menos peças.

Estrutura de Dados
------------------
A estrutura das peças se dá pela seguinte forma:
```c
typedef struct peca{
    int p1; // Lado "um" da peça
    int p2; // LAdo "dois" da peça

}tipo_peca;
```

E é inicializada dos seguintes modos para a organização das peças:
```c
tipo_peca domino[28];      //Peças do dominó
tipo_peca pecas_p1[21];    //Peças do jogador 1
tipo_peca pecas_p2[21];    //Peças do jogador 2
tipo_peca mesa[56];        //Peças da mesa
tipo_peca monte[14];       //Peças do monte
```

Organização dos módulos do programa
-----------------------------------
O sistema precisava ter diferentes formas de apresentação do jogo (múltiplas interfaces). Para isso, o padrão MVC foi escolhido. O princípio básico do MVC é a divisão da aplicação em três camadas: a camada de interação do usuário (view), a camada de manipulação dos dados (model) e a camada de controle (controller). Assim, como as próprias camadas indicam, utilizamos a View para todo o código em que haveria alguma interação de tela do usuário, de mostrar o menu até todas as peças em jogo, a Model, para todo o tipo de processamento de dados e afins do jogo, já para o Controller, assim como o nome diz, usamos para controlar toda a estrutura do jogo, também fazendo o link entre a View e a Model.
