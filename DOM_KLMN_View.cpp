//DOM-KLMN - Projeto Domino - Etapa 2
//16/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.h"

int fMenuInicio () //visualizacao do menu
{
	int opc;

    printf("\n+-------------------------------------------------------+\n");
    printf("|                  Jogo de Domino (PUC-SP)              |\n");
    printf("|                                                       |\n");
    printf("| 1. Iniciar jogo (2 jogadores)                         |\n");
    printf("| 2. Iniciar jogo (contra o computador)                 |\n");
    printf("| 3. Retornar ao jogo interrompido				    	|\n");
    printf("| 4. Regras gerais do Jogo                              |\n");
    printf("| 5. Salvar o jogo                                      |\n");
    printf("| 6. Recuperar o jogo salvo                             |\n");
    printf("| 0. Sair                                               |\n");
    printf("+-------------------------------------------------------+\n\n");

	printf("Digite uma opcao: ");
	scanf("%d", &opc);

	return(opc);
}

void fPrintPecas () //Exibir pecas
{
	for (int i = 0; i < MAX; i++)
    {
        printf("[%d|%d] ", peca[i].ladoE, peca[i].ladoD);
    }
}

int apresentaPeca(char jogador)
{
	return 1;
}

void fPrintMensagem (char *msg)
{
	printf("\n%s", msg);
}

