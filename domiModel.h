#ifndef DOMIMODEL_H_INCLUDED
#define DOMIMODEL_H_INCLUDED

#include <stdbool.h>


// Estrutura da peça de dominó
typedef struct peca{
    int p1;
    int p2;

}tipo_peca;




//Inicialização das structs
tipo_peca domino[28];
tipo_peca pecas_p1[21];
tipo_peca pecas_p2[21];
tipo_peca mesa[56];
tipo_peca monte[14];

//Inicialização das funções
void setMesa(tipo_peca mesa[]);
void setMonte(tipo_peca monte[], tipo_peca domino[]);
void distribuirPcs(tipo_peca domino[], tipo_peca pecas_p[],bool P1);
void embaralhar(tipo_peca domino[]);
void criarPcs(tipo_peca domino[],tipo_peca mesa[],tipo_peca monte[]);
void logicaPlayerEmJogo();
void logicaPlayer();
void logicaMesa(void);
void menuPrincipal();
void salvarJogo(tipo_peca monte[], tipo_peca pecas_p1[], tipo_peca pecas_p2[],tipo_peca mesa[]);
void carregarJogo(tipo_peca monte[], tipo_peca pecas_p1[], tipo_peca pecas_p2[],tipo_peca mesa[]);
int checarMaior(tipo_peca pecas_p1[],tipo_peca pecas_p2[]);
int ChecarVitoria(tipo_peca pecas_p1[],tipo_peca pecas_p2[],int tam1,int tam2);



#endif // DOMIMODEL_H_INCLUDED

