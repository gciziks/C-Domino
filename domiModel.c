#include "domiModel.h"
#include "domiView.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#define min 0
#define max 27 // 28 peças no total
int tam1;
int tam2;
int tammesa;
int jogando;
int monte_cont;
int inicio, final;
int opcao02 = 0;

void setMesa(tipo_peca mesa[]){
    //Cria uma mesa vazia representada com -1 em todas as suas posições
    int x;
    for(x=0;x<56;x++){
        mesa[x].p1=-1;
        mesa[x].p2=-1;
    }
}
void setMonte(tipo_peca monte[], tipo_peca domino[]){
    //Cria o Monte com as peças restantes que não foram entregues para os jogadores
    int x;
    for(x=0;x<14;x++){
        monte[x].p1 = domino[x+14].p1;
        monte[x].p2 = domino[x+14].p2;
    }


}

void embaralhar(tipo_peca domino[]){
    //Gerar um número randômico
    int rnd_n;
    int x;
    time_t t;
    srand((unsigned) time(&t)); // Gera um número randômico ilimitado
    for(x=0;x<28;x++){

        int dominoBfX,dominoBfY;
        int dominoNX,dominoNY;


        rnd_n = rand() % max; // Torna o número randômico em um aleatório no limite permitido (0 - 27)

        // Salvando e invertendo os valores aleatóriamente sem perder as peças montadas
        dominoNX = domino[rnd_n].p1;
        dominoNY = domino[rnd_n].p2;
        dominoBfX = domino[x].p1;
        dominoBfY = domino[x].p2;
        domino[x].p1 = dominoNX;
        domino[x].p2 = dominoNY;
        domino[rnd_n].p1 = dominoBfX;
        domino[rnd_n].p2 = dominoBfY;
    }


}
void distribuirPcs(tipo_peca domino[], tipo_peca pecas_p[],bool P1){
    //Distribui as peças entre os jogadores
    int x;
    for(x=0;x<7;x++){
        if(P1 == true){
            //Jogador 1 recebe as 7 primeiras peças do domino
            pecas_p[x].p1 = domino[x].p1;
            pecas_p[x].p2 = domino[x].p2;
        }
        else{
            //Jogador 2 recebe as 7 primeiras peças que nao foram distribuidas ao jogador 1
            pecas_p[x].p1 = domino[x+7].p1;
            pecas_p[x].p2 = domino[x+7].p2;
        }
    }

}

void criarPcs(tipo_peca domino[],tipo_peca mesa[],tipo_peca monte[]){
    int x;
    int y;
    tam1 = 7;
    tam2 = 7;
    int count = 0;
    for(x=0;x<7;x++){
        for(y=0;y<=x;y++){

            // Criar peças em efeito pirâmide
            domino[count].p1 = x;
            domino[count].p2 = y;
            count++;

        }

    }
    setMesa(mesa); //Inicializa e seta a Mesa


}
int checarMaior(tipo_peca pecas_p1[],tipo_peca pecas_p2[]){
    int x,y;
    int pp1;
    int pp2;
    int player;
    for(y=6;y>=0;y--){
        for(x=0;x<7;x++){
            if(pecas_p1[x].p1 == y && pecas_p1[x].p2 == y){

                pp1 = pecas_p1[x].p1;
                pp2 = pecas_p1[x].p2;
                player = 1;
                y = -1;

            }
            if(pecas_p2[x].p1 == y && pecas_p2[x].p2 == y){
                pp1 = pecas_p2[x].p1;
                pp2 = pecas_p2[x].p2;
                player = 2;
                y = -1;
            }
        }
    }
    printf("\nJogador %d  começa",player);
    return player;


}
int ChecarVitoria(tipo_peca pecas_p1[],tipo_peca pecas_p2[],int tam1,int tam2){
    int x;
    int somaP1 = 0;
    int somaP2 = 0;
    for(x=0;x<=21;x++){
        somaP1 = somaP1 + pecas_p1[x].p1 + pecas_p1[x].p2;
        somaP2 = somaP2 + pecas_p2[x].p1 + pecas_p2[x].p2;
    }
    if(somaP1 > somaP2){
        return 2;
    }
    else if(somaP2> somaP1){
        return 1;
    }
    else{
        return 0;
    }
}
void logicaMesa(){
    int opcao2;
    int primeiroJoga;
    if(mesa[28].p1==-1){
       tammesa=0;
       jogando=1;
       monte_cont =0;
    }
    primeiroJoga = checarMaior(pecas_p1,pecas_p2);
    if (opcao02==2){

        jogando= primeiroJoga;
    }
    else{
        if(primeiroJoga == 1){
            jogando = primeiroJoga;
        }
        else{
            jogando = 3;
        }
    }

    do{
        //Verifica se é a vez do jogador 1 ou do jogador 2 para colocar a peça na mesa
        if(jogando==1){
            int controle = 0;
            do{
                //Exibe para o jogador da rodada as peças dele e qual ação ele ira tomar
                exibirMensagem(MSG_SELECP1);
                int confirma_opc;
                do{
                    exibirMensagem(MSG_OKMOSTRAR);
                    scanf("%d",&confirma_opc);
                }while(confirma_opc != 1);

                mostrarPcsJogadores(pecas_p1,true,tam1);
                exibirMensagem(MSG_OPT);
                scanf("%d",&opcao2);
                //Verifica se a mesa está vazia para iniciar o controle do posicionamento das peças
                if(mesa[28].p1==-1){
                    mesa[28].p1=pecas_p1[opcao2-1].p1;
                    mesa[28].p2=pecas_p1[opcao2-1].p2;
                    tammesa=tammesa+1;
                    inicio=28;
                    final=28;
                    controle = 1;
                }
                else{
                    int opcao3;
                    bool falhou = false;
                    do{
                        falhou = false;
                        exibirMenuLocalPeca();
                        scanf("%d",&opcao3);
                        //Verifica se o jogador quer colocar a peca no inico ou no final da mesa
                        if(opcao3==1){
                            //Verifica se um dos lados da peça do domino corresponde ao numero da peça na mesa
                            if(pecas_p1[opcao2-1].p1==mesa[inicio].p1){
                                mesa[inicio-1].p1=pecas_p1[opcao2-1].p2;
                                mesa[inicio-1].p2=pecas_p1[opcao2-1].p1;
                                inicio--;
                                controle = 1;
                                }
                            else if(pecas_p1[opcao2-1].p2==mesa[inicio].p1){
                                mesa[inicio-1].p1=pecas_p1[opcao2-1].p1;
                                mesa[inicio-1].p2=pecas_p1[opcao2-1].p2;
                                inicio--;
                                controle = 1;
                                }
                            else{
                                //Apresenta uma mensagem caso a peça esolhida seja invalida
                                exibirMensagem(MSG_PECAINV);
                                falhou = true;
                                }
                        }
                        else if(opcao3 ==2){
                            //Verifica se um dos lados da peça do domino corresponde ao numero da peça na mesa
                            if(pecas_p1[opcao2-1].p1==mesa[final].p2){
                                mesa[final+1].p1=pecas_p1[opcao2-1].p1;
                                mesa[final+1].p2=pecas_p1[opcao2-1].p2;
                                final=++final;
                                controle = 1;
                                }
                            else if(pecas_p1[opcao2-1].p2==mesa[final].p2){
                                mesa[final+1].p1=pecas_p1[opcao2-1].p2;
                                mesa[final+1].p2=pecas_p1[opcao2-1].p1;
                                final=++final;
                                controle = 1;
                                }
                            else{
                                //Apresenta uma mensagem caso a peça esolhida seja invalida
                                exibirMensagem(MSG_PECAINV);
                                falhou = true;
                                }
                            }
                        else if(opcao3==3){
                            opcao2=0;
                            opcao3=0;
                            logicaPlayerEmJogo();
                            }
                         //Comprar Peça
                        else if(opcao3==4){
                        exibirMensagem(MSG_MESA);
                        mostrarMesaPcs(mesa,inicio, final);}
                        //Comprar Peça
                        else if(opcao3==5){
                            if (tam1 == 7){

                                pecas_p1[tam1].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p1[tam1].p2 = monte[monte_cont].p2;
                                tam1++;

                            }
                            else{
                                //senão, aumentar o nmr de peças do jogador

                                pecas_p1[tam1].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p1[tam1].p2 = monte[monte_cont].p2;
                                if (pecas_p1[tam1].p1 == 0 && pecas_p1[tam1].p2 == 0){
                                    pecas_p1[tam1].p1 = -1;
                                    pecas_p1[tam1].p2 = -1;
                                    tam1--;
                                }
                                tam1++;
                            }


                            monte_cont++;
                        }
                        else if(opcao3 ==6){
                            int vencedor;
                            int inf = 0;
                            vencedor = ChecarVitoria(pecas_p1,pecas_p2,tam1,tam2);
                            if(vencedor == 1){
                                do{
                                    exibirMensagem(MSG_VIT01);
                                }while(inf==0);

                            }
                            else if(vencedor ==2){
                                do{
                                    exibirMensagem(MSG_VIT02);
                                }while(inf==0);
                            }
                            else{
                                do{
                                    exibirMensagem(MSG_EMPT);
                                }while(inf==0);
                            }
                        }
                        else{
                            controle = 0;
                        }
                    }while(falhou == true);

                }
            }while(controle != 1); //Permanece dentro deste menu ate que o controle seja principalmente igual a zero (ou diferente de um)

            //Apresenta a mesa na tela, retira a peça da mao do jogador 1 e passa a vez para o jogador 2
            exibirMensagem(MSG_MESA);
            mostrarMesaPcs(mesa,inicio, final);
            pecas_p1[opcao2-1].p1= -1;
            pecas_p1[opcao2-1].p2=-1;
            tam1=tam1--;

            if (opcao02==2)
                jogando=2;
            else{
                jogando=3;
            }
        }
        else if(jogando==2){
            int controle = 0;
            do{

                exibirMensagem(MSG_SELECP2);

                int confirma_opc;
                do{
                    exibirMensagem(MSG_OKMOSTRAR);
                    scanf("%d",&confirma_opc);
                }while(confirma_opc != 1);


                mostrarPcsJogadores(pecas_p2,false,tam2);
                exibirMensagem(MSG_OPT);
                scanf("%d",&opcao2);
                //Verifica se a mesa está vazia para iniciar o controle do posicionamento das peças
                if(mesa[28].p1==-1){
                    mesa[28].p1=pecas_p2[opcao2-1].p1;
                    mesa[28].p2=pecas_p2[opcao2-1].p2;
                    tammesa=tammesa+1;
                    inicio=28;
                    final=28;
                    controle = 1;
                }

                else{
                    int opcao3;

                    exibirMenuLocalPeca();
                    scanf("%d",&opcao3);
                    //Verifica se o jogador quer colocar a peca no inico ou no final da mesa
                    if(opcao3==1){ // no início
                        //Verifica se um dos lados da peça do domino corresponde ao numero da peça na mesa
                        if(pecas_p2[opcao2-1].p1==mesa[inicio].p1){
                            mesa[inicio-1].p1=pecas_p2[opcao2-1].p2; //adiciona peça a mesa
                            mesa[inicio-1].p2=pecas_p2[opcao2-1].p1;
                            inicio--;
                            controle = 1;
                            }
                        else if(pecas_p2[opcao2-1].p2==mesa[inicio].p1){
                            mesa[inicio-1].p1=pecas_p2[opcao2-1].p1; //adiciona peça a mesa
                            mesa[inicio-1].p2=pecas_p2[opcao2-1].p2;
                            inicio--;
                            controle = 1;
                            }
                        else{
                            //Apresenta uma mensagem caso a peça esolhida seja invalida
                            exibirMensagem(MSG_PECAINV);
                            controle = 0;
                            }
                        }
                    else if(opcao3 ==2){ // no final
                        //Verifica se um dos lados da peça do domino corresponde ao numero da peça na mesa
                        if(pecas_p2[opcao2-1].p1==mesa[final].p2){
                            mesa[final+1].p1=pecas_p2[opcao2-1].p1; //adiciona peça a mesa
                            mesa[final+1].p2=pecas_p2[opcao2-1].p2;
                            final=++final;
                            controle = 1;
                            }
                        else if(pecas_p2[opcao2-1].p2==mesa[final].p2){
                            mesa[final+1].p1=pecas_p2[opcao2-1].p2; //adiciona peça a mesa
                            mesa[final+1].p2=pecas_p2[opcao2-1].p1;
                            final=++final;
                            controle = 1;
                            }
                        else{
                            //Apresenta uma mensagem caso a peça esolhida seja invalida
                            exibirMensagem(MSG_PECAINV);
                            controle = 0;
                            }
                        }
                    else if(opcao3==3){
                            opcao2=0;
                            opcao3=0;
                            logicaPlayerEmJogo();
                            }
                    else if(opcao3==4){
                        exibirMensagem(MSG_MESA);
                        mostrarMesaPcs(mesa,inicio, final);}
                    //Comprar Peça
                    else if(opcao3==5){
                        if (tam2 == 7){
                        //Se for a primeira peça, preencher o último espaço predefinido
                            if(monte_cont != 2){
                                pecas_p2[7].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[7].p2 = monte[monte_cont].p2;
                                tam2++;
                            }
                            else{
                                monte_cont++;
                                pecas_p2[7].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[7].p2 = monte[monte_cont].p2;
                                tam2++;
                            }

                        }
                        else{
                        //senão, aumentar o nmr de peças do jogador
                            if (tam2 == 7){

                                pecas_p2[tam2].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[tam2].p2 = monte[monte_cont].p2;
                                tam2++;

                            }
                            else{
                                //senão, aumentar o nmr de peças do jogador

                                pecas_p2[tam2].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[tam2].p2 = monte[monte_cont].p2;
                                if (pecas_p2[tam2].p1 == 0 && pecas_p2[tam1].p2 == 0){
                                    pecas_p2[tam2].p1 = -1;
                                    pecas_p2[tam2].p2 = -1;
                                    tam2--;
                                }
                                tam2++;
                            }
                        }


                        monte_cont++;
                    }
                    else if(opcao3 ==6){
                            int vencedor;
                            int inf = 0;
                            vencedor = ChecarVitoria(pecas_p1,pecas_p2,tam1,tam2);
                            if(vencedor == 1){
                                do{
                                    exibirMensagem(MSG_VIT01);
                                }while(inf==0);

                            }
                            else if(vencedor ==2){
                                do{
                                    exibirMensagem(MSG_VIT02);
                                }while(inf==0);
                            }
                            else{
                                do{
                                    exibirMensagem(MSG_EMPT);
                                }while(inf==0);
                            }
                        }
                    else{
                        controle = 0;
                    }
                }
                }while(controle != 1); //Permanece dentro deste menu ate que o controle seja igual a zero

            //Apresenta a mesa na tela, retira a peça da mao do jogador 2 e passa a vez para o jogador 1
            exibirMensagem(MSG_MESA);
            mostrarMesaPcs(mesa,inicio, final);
            pecas_p2[opcao2-1].p1=-1;
            pecas_p2[opcao2-1].p2=-1;
            tam2=tam2--;
            jogando=1;
        }
        else{
            int i=0;
            int controle = 0;
            exibirMensagem(MSG_SELECPC);
            mostrarPcsJogadores(pecas_p2,false,tam2);
            do{

                //Verifica se a mesa está vazia para iniciar o controle do posicionamento das peças
                if(mesa[28].p1==-1){
                    int j;

                    for(j=7;j>=0;j--){
                        if(pecas_p2[j].p1 == pecas_p2[j].p2){
                            mesa[28].p1=pecas_p2[j].p1;
                            mesa[28].p2=pecas_p2[j].p2;
                        }
                    }

                    tammesa=tammesa+1;
                    inicio=28;
                    final=28;
                    controle = 1;
                    i++;
                    }
                else{
                        if(pecas_p2[i].p1==mesa[inicio].p1){
                            mesa[inicio-1].p1=pecas_p2[i].p2; //adiciona peça a mesa
                            mesa[inicio-1].p2=pecas_p2[i].p1;
                            inicio--;
                            controle = 1;
                        }
                        else if(pecas_p2[i].p2==mesa[inicio].p1&&controle!=1){
                            mesa[inicio-1].p1=pecas_p2[i].p1; //adiciona peça a mesa
                            mesa[inicio-1].p2=pecas_p2[i].p2;
                            inicio--;
                            controle = 1;
                            }

                        //Verifica se um dos lados da peça do domino corresponde ao numero da peça na mesa
                        else if(pecas_p2[i].p1==mesa[final].p2&&controle!=1){
                            mesa[final+1].p1=pecas_p2[i].p1; //adiciona peça a mesa
                            mesa[final+1].p2=pecas_p2[i].p2;
                            final=++final;
                            controle = 1;
                            }
                        else if(pecas_p2[i].p2==mesa[final].p2&&controle!=1){
                            mesa[final+1].p1=pecas_p2[i].p2; //adiciona peça a mesa
                            mesa[final+1].p2=pecas_p2[i].p1;
                            final=++final;
                            controle = 1;
                            }
                        else if(i==tam2){


                            if (tam2 == 7){
                            //Se for a primeira peça, preencher o último espaço predefinido
                                pecas_p2[7].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[7].p2 = monte[monte_cont].p2;
                                tam2++;
                            }
                            else{
                            //senão, aumentar o nmr de peças do jogador
                                tam2++;
                                pecas_p2[tam2].p1 = monte[monte_cont].p1; //Pegando peça do monte
                                pecas_p2[tam2].p2 = monte[monte_cont].p2;
                            }
                        }

                        i++;
                        monte_cont++;
            }

            }while(controle != 1); //Permanece dentro deste menu ate que o controle seja igual a zero

            //Apresenta a mesa na tela, retira a peça da mao do jogador 2 e passa a vez para o jogador 1
            printf ("\n\n--------------Computador escolheu a opcao %d--------------------",i);
            exibirMensagem(MSG_MESA);
            mostrarMesaPcs(mesa,inicio, final);
            pecas_p2[i-1].p1=-1;
            pecas_p2[i-1].p2=-1;
            tam2=tam2--;
            jogando=1;
        }
    }while(tam1!=0||tam2!=0); // Acaba o GameLoop quando um dos dois não tiver mais peças
    if(tam1==0){
        exibirMensagem(MSG_VIT01);
    }
    else if(tam2==0){
        exibirMensagem(MSG_VIT02);
    }

}

void logicaPlayerEmJogo(){
    exibirMenuJogo(); // Exibir menu dentro do Jogo já iniciado - Jogar peças - Comprar - Mostrar peças de cada jogador
    int opcao03 = 0;
    do{
        opcao03 = obterOpcao();
        switch(opcao03){
            case 1: mostrarPcsJogadores(pecas_p1,true,tam1);// mostra todas as peças do jogador 01
                    exibirMenuJogo(); // volta a exibir o menu de escolhas dentro do jogo
                    break;
            case 2: mostrarPcsJogadores(pecas_p2,false,tam2);// mostra todas as peças do jogador 02
                    exibirMenuJogo(); // volta a exibir o menu de escolhas dentro do jogo
                    break;
            case 3: logicaMesa(); // exibe a Mesa e permite o mecanismo de colocar a peça e comprá-las
                    break;
            case 4:salvarJogo(monte, pecas_p1, pecas_p2, mesa);
            exit(0);
            default:exibirMensagem(MSG_SELEC);
                 // Opc invalida

        }
    }while(opcao03 != 5);
}
void logicaPlayer(){
    //Menu inicial após jogador iniciar o jogo

    do{

        exibirMenuQtdJog(); // Exibir menu de escolha de 1 ou 2 jogadores
        opcao02 = obterOpcao();


        switch(opcao02){
            case 1: // Opção - 1 jogador
                    exibirMensagem(MSG_JOGO1P);
                    distribuirPcs(domino,pecas_p1,true);
                    distribuirPcs(domino,pecas_p2,false);
                    logicaPlayerEmJogo(); // Função referente aos mecanismos do menu dentro do jogo
                    break;
            case 2: // Opção - 2 jogadores
                    exibirMensagem(MSG_JOGO2P);
                    distribuirPcs(domino,pecas_p1,true);
                    distribuirPcs(domino,pecas_p2,false);
                    logicaPlayerEmJogo(); // Função referente aos mecanismos do menu dentro do jogo
                    break;
            default:exibirMensagem(MSG_SELEC);
                 // Opção inválida
        }
    }while(opcao02 != 3);
}

void carregarJogo(tipo_peca monte[], tipo_peca pecas_p1[], tipo_peca pecas_p2[],tipo_peca mesa[]) {
    FILE *Arqcarregar;

    //Caso arquivo de data esteja vazio
    if ((Arqcarregar = fopen("save.dat", "rb")) == NULL) {
        exibirMensagem(MSG_SALVAERRO);
        getchar();
        flush_in();
        // Retorna erro

    }
    // Carregando infos das peças de ambos jogadores e do monte
    for (int i = 0; i < 28; i++) {
        fread(&monte[i], sizeof(tipo_peca), 1, Arqcarregar);

        fread(&pecas_p1[i], sizeof(tipo_peca), 1, Arqcarregar);

        fread(&pecas_p2[i], sizeof(tipo_peca), 1, Arqcarregar);

    }
    // Carregando infos da mesa
    for (int j = 0; j < 61; j++) {
        fread(&mesa[j], sizeof(mesa), 1, Arqcarregar);
    }
    fclose(Arqcarregar);


}

void salvarJogo(tipo_peca monte[], tipo_peca pecas_p1[], tipo_peca pecas_p2[],tipo_peca mesa[]) {
        FILE *ArqSalvar;
        // Se arquivo de data estiver vazio
        if ((ArqSalvar = fopen("save.dat", "wb")) != NULL) {
            exibirMensagem(MSG_SALVANDO);
        } else {

            exibirMensagem(MSG_SALVAERRO);
            getchar();
            flush_in();
            //retorna
        }
        // Salvando infos das peças de ambos jogadores e do monte
        for (int i = 0; i < 28; i++) {
            fwrite(&monte[i], sizeof(tipo_peca), 1, ArqSalvar);

            fwrite(&pecas_p1[i], sizeof(tipo_peca), 1, ArqSalvar);

            fwrite(&pecas_p2[i], sizeof(tipo_peca), 1, ArqSalvar);
        }
        // Salvando info da mesa
        for (int j = 0; j < 61; j++) {
            fwrite(&mesa[j], sizeof(mesa), 1, ArqSalvar);
        }

        exibirMensagem(MSG_JOGOSALVO);

        fclose(ArqSalvar);
}
