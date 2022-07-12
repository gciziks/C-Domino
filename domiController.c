#include "domiController.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
void executarController(){
    int escolha;
    FILE *Arqcarregar;
	do {
		// Setar Menu
		exibirMenu();

		escolha = obterOpcao();
		//Variáveis
		bool criou;

		switch (escolha){

			case 1:	//Criar peças - Opção 01
					criarPcs(domino,mesa,monte);
					criou = true;
					exibirMensagem(MSG_CRIADAS);
					break;
			case 2: //Embaralhar peças - Opção 02
					if(criou == true){
						embaralhar(domino);
						setMonte(monte,domino); //Inicializa e monta o Monte
						exibirMensagem(MSG_LINHA);
						exibirMensagem(MSG_EMBARALHADO);
						exibirMensagem(MSG_LINHA);
						break;
					}
					else{
						//Se as peças não foram criadas antes -> aviso
						exibirMensagem(MSG_AVISOPECAS);
						break;
					}
			case 3: // Mostrar todas as peças existentes (Já embaralhadas ou não) - Opção 03
					if(criou == true){
						mostrarPcs(domino);
						exibirMensagem(MSG_LINHA);
						break;
					}
					else{
						//Se as peças não foram criadas antes -> aviso
						exibirMensagem(MSG_AVISOPECAS);
						break;
					}
			case 4: //EM ANDAMENTO
                    if(criou == true){
						exibirMensagem(MSG_LINHA);
                        exibirMensagem(MSG_JOGOINIT);
                        exibirMensagem(MSG_LINHA);
                        logicaPlayer();
						break;
					}
					else{
						//Se as peças não foram criadas antes -> aviso
						exibirMensagem(MSG_AVISOPECAS);
						break;
					}


					break;

            case 5:
                    exibirRegras();
                    break;

            case 6:
                if ((Arqcarregar = fopen("save.dat", "rb")) == NULL) {
                    exibirMensagem(MSG_SALVAERRO);
                    getchar();
                    flush_in();
                    break;
                }

                else{
                    carregarJogo(monte, pecas_p1, pecas_p2, mesa);
                    logicaMesa();
                    }

            case 7: //Sair da aplicação
                    exibirMensagem(MSG_SAIR);
                    break;
			default:
				//Caso o usuario digite algum valor que nao seja os correspondentes dentro do menu, o programa informa o erro e repete o loop
				exibirMensagem(MSG_SELEC);
				exibirMensagem(MSG_LINHA);
				break;
		}
	}while(escolha != 7);


}
