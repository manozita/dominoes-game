//DOM-KLMN - Projeto Domino - Etapa 5
//13/09/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.h"
void fMenuInicio () //visualizacao do menu
{

    printf("\n+-------------------------------------------------------+\n");
    printf("|                  Jogo de Domino (PUC-SP)              |\n");
    printf("|                                                       |\n");
    printf("| 1. Iniciar jogo (2 jogadores)                         |\n");
    printf("| 2. Iniciar jogo (1 jogador)                           |\n");
    printf("| 3. Voltar ao jogo                                     |\n");
    printf("| 4. Salvar jogo                                        |\n");
    printf("| 5. Recuperar jogo salvo                               |\n");
    printf("| 0. Sair do jogo                                       |\n");
    printf("+-------------------------------------------------------+\n\n");

	printf("Digite uma opcao: ");
	scanf("%d", &opc);

}

void fPrintPrimeiroJogador()
{
	printf("Primeira jogada foi do jogador %d.\n", J);
}

void fMensagem (char *msg)
{
	printf("%s", msg);
}

void fMesa ()
{
	printf("\n\n===============\nM E S A:");

	int i, j;
	for (i = 0; i < numeroJogadas; i++)
	{
		printf(" [%d|%d]", mesa[i].lado1, mesa[i].lado2);
	}
	printf("\n===============\n\n");
}

void fPrintPecas (int jogador)
{
	indicePeca = 97; int i;
	
	printf("Jogador %d\t Pecas: ", jogador);
	for (i = 0; i < MAX; i++)
	{
		if (peca[i].status == jogador) //se a peca pertencer ao jogador
		{
			printf(" %c.[%d|%d]", indicePeca, peca[i].lado1, peca[i].lado2);
			indicePeca++;
		}
	}
	printf("\n---------------\n\n");
}

void fPrintVencedor(int jogador)
{
	system("cls");
	
	printf("\nParabens, jogador %d, voce venceu o jogo!\n", jogador);
}

char fEscolhaChar()
{
	char opcaoEscolha[2];
	do
	{
		fMensagem ("Opcao: ");
		fflush(stdin); //limpar o buffer
		scanf("%c", &opcaoEscolha[0]);
		if (opcaoEscolha[0] == '\0') //caso nada tenha sido digitado
			fMensagem ("\nOpcao invalida.");

	} while (opcaoEscolha[0] == '\0');
	
	return (opcaoEscolha[0]);
}


