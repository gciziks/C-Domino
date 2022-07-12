#ifndef DOMIVIEW_H_INCLUDED
#define DOMIVIEW_H_INCLUDED

#include "domiModel.h"

//Mensagens pré-definidas
#define MSG_CRIADAS "\n--------------------------Pecas Criadas----------------------------\n"
#define MSG_EMBARALHADO "\n--------------------------Pecas Embaralhadas----------------------------\n"
#define MSG_SELEC "\nSelecione uma opcao valida\n\n------------------------------------------------------------------------\n"
#define MSG_LINHA "\n------------------------------------------------------------------------\n"
#define MSG_AVISOPECAS "\n-----------------------Crie as pecas primeiro---------------------------\n"
#define MSG_EMDESENV "\n-----------------------EM DESENVOLVIMENTO---------------------------\n"
#define MSG_SAIR "\n-----------------------FECHANDO JOGO...---------------------------\n"
#define MSG_JOGOINIT "\n-----------------------JOGO INICIADO---------------------------\n"
#define MSG_JOGO1P "\n-----------------------1 JOGADOR---------------------------\n"
#define MSG_JOGO2P "\n-----------------------2 JOGADORES---------------------------\n"
#define MSG_OKMOSTRAR "\n--------------------Digite 1 para mostrar suas peças---------------------------\n"
#define MSG_SELECP1 "\n\nJogador 1, escolha uma peca da sua mao para colocar na mesa!\n"
#define MSG_SELECP2 "\n\nJogador 2, escolha uma peca da sua mao para colocar na mesa!\n"
#define MSG_SELECPC "\n\nVez do computador colocar a peca na mesa!\n"
#define MSG_PECAINV "\nEsta peca e invalida para esta posicao!"
#define MSG_MESA "\nMesa:\n"
#define MSG_OPT "\nOpcao: "
#define MSG_SALVAERRO "\n\n O arquivo de save nao pode ser aberto: aperte enter para continuar:"
#define MSG_JOGOSALVO "\nJogo salvo.\n"
#define MSG_SALVANDO "\n\nArquivo aberto: Salvando.\n\n"
#define MSG_VIT01 "\n\nJOGADOR 01 VENCEUU!!\n\n"
#define MSG_VIT02 "\n\nJOGADOR 02 VENCEUU!!\n\n"
#define MSG_EMPT "\n INCRIVEL! DEU EMPATE"

//Inicialização
void exibirMenu();
int obterOpcao();
void mostrarPcs(tipo_peca domino[]);
void exibirMensagem(char msg[]);
void exibirMenuQtdJog();
void mostrarPcsJogadores(tipo_peca pecas_p1[],bool P1,int tam);
void mostrarMesaPcs(tipo_peca mesa[],int inicio,int final);
void exibirMenuJogo();
void exibirMenuLocalPeca();
void exibirMesa();
void exibirRegras();
void flush_in();

#endif // DOMIVIEW_H_INCLUDED
