#include <stdio.h>
#include <ctype.h>

#include "domiModel.h"
#include "domiView.h"


void exibirMenu() {
	 //seleção da opção do menu
	printf("\nPor favor, selecione uma das opcoes do menu:\n");
	printf("(1)-Criar / Organizar pecas\n");
	printf("(2)-Embaralhar pecas\n");
	printf("(3)-Mostrar pecas\n");
	printf("(4)-Iniciar jogo\n");
	printf("(5)-Ler regras\n");
	printf("(6)-Continuar jogo\n");
	printf("(7)-Sair do jogo\n");
	printf("\nOpcao: ");

}
int obterOpcao(){
	// Captura da opção selecionada pelo usuário
    int escolha;
    scanf("%d", &escolha);
    return escolha;

}
void mostrarPcs(tipo_peca domino[]){
	//Mostrar todas as peças
    int x;
    for(x=0;x<28;x++){
        printf("\n------------\n|  %d  |  %d  |\n------------",domino[x].p1,domino[x].p2);
    }
}
void mostrarPcsJogadores(tipo_peca pecas[],bool P1,int tam){

    int x;
    //Mostrar peças do jogadores conforme estabelecido pela P1
    for(x=0;x<tam;x++){
        if(pecas[x].p1!=-1)
            printf("\n\t------------\nopcao(%d)|  %d  |  %d  |\n\t------------", x+1, pecas[x].p1, pecas[x].p2);
    }
}

void exibirMensagem(char msg[]) {
	// Exibição de mensagem já predefinidas - facilitação dos prints
    printf("%s\n",msg);
}
void mostrarMesaPcs(tipo_peca mesa[],int inicio,int final){
    //Exibição das peças na mesa
    int x;
    for(x=inicio;x<=final;x++){
        printf("|  %d  |  %d  |",mesa[x].p1,mesa[x].p2);
    }
}
void exibirMenuQtdJog(void){
    //Exibição do menu de numero de jogadores
    printf("\nPor favor, informe o numero de jogadores:\n");
    printf("(1)-Um Jogador\n");
    printf("(2)-Dois Jogadores\n");
    printf("(3)-Voltar\n");
    printf("\nOpcao: ");

}
void exibirMenuJogo(void){
    //Exibiçao do menu durante jogo
    printf("\nO que deseja fazer:\n");
    printf("(1)-Mostrar as pecas do Jogador 01\n");
    printf("(2)-Mostrar as pecas do Jogador 02\n");
    printf("(3)-Mesa/Jogar peça\n");
    printf("(4)-Salvar Jogo\n");
    printf("(5)-Voltar\n");
    printf("\nOpcao: ");
}
void exibirMenuLocalPeca(void){
    //Exibição do menu para local da peça na mesa
    printf("\nOnde deseja colocar a peca? ");
    printf("\n(1)-no comeco da mesa ");
    printf("\n(2)-no final da mesa ");
    printf("\n(3)-Voltar");
    printf("\n(4)-Ver mesa");
    printf("\n(5)-Comprar peça");
    printf("\n(6)-Nenhum dos jogadores possue mais jogadas restantes?");
    printf("\nOpcao: ");

}
void exibirRegras() {
	 // Exibir todas as regras aplicadas
	printf("\n------Regras------\n");
	printf("(1)-Ambos receberao 7 pecas\n");
	printf("(2)-Quem acabar com suas pecas primeiro sera o vencedor\n");
	printf("(3)-Aquele que tiver a peca de maior pontuacao ira começar(E.g |6|6| = 12pts)\n");
	printf("(4)-Caso nao possua jogadas possiveis, o jogador deve comprar pecas do monte ate ter uma jogada possivel\n");
	printf("(5)-Uma vez que o monte acabar, o jogador tera sua vez pulada\n"); // Em Dev
	printf("(6)-Se nenhum jogador tiver mais jogadas possiveis, ganha aquele que possuir a menor quantidade de pontos na mao\n"); // Em Dev
}

void flush_in(){
    char op;
    while ((op = fgetc(stdin)) != EOF && op != '\n'){};
}
