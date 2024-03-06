//DOM-KLMN - Projeto Domino - Etapa 1
//09/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//===========================================================//
#define MAX 28
//===========================================================//

typedef struct pecas //estrutura para as pecas
{
	int lado1; int lado2; //valor numerico (1-6) de cada lado
	int pos; //posicao na ordem correta
	char status;
} valoresPecas;

valoresPecas peca[MAX]; 
valoresPecas aux; //auxiliar para a randomizacao
//===========================================================//

void fGerarDomino (); //gera domino inicial
void fShuffle (); //embaralhar pecas do domino
void fPrint (); //imprimir o domino na tela
int fMenu (); //printar menu de inicio
//===========================================================//

void fGerarDomino ()
{
	int i, j;
	int n = 0;
	
	for (i = 0; i <= 6; i++) 
	{
        for (j = i; j <= 6; j++) 
		{
            peca[n].lado1 = i;
            peca[n].lado2 = j;
            n++;
        }
    }
}
    
//===========================================================//

void fShuffle () 
{
	srand(time(NULL));
	for (int i = 0; i < MAX; i ++)
	{
		int pecaAleatoria = rand() % MAX; 
		aux = peca[i];
		peca[i] = peca[pecaAleatoria];
		peca[pecaAleatoria] = aux;
	}
}
//===========================================================//

void fPrint () 
{
	for (int i = 0; i < MAX; i++)
    {
        printf("[%d|%d] ", peca[i].lado1, peca[i].lado2);
    }
}
//===========================================================//

int fMenuInicio () //visualizacao do menu
{
	int opc;

    printf("\n+-------------------------------------------------------+\n");
    printf("|                  Jogo de Domino (PUC-SP)              |\n");
    printf("|                                                       |\n");
    printf("| 1. Ver pecas                                          |\n");
    printf("| 2. Embaralhar pecas                                   |\n");
    printf("| 3. Reorganizar pecas                                  |\n");
    printf("| 4. Sair do jogo                                       |\n");
    printf("+-------------------------------------------------------+\n\n");

	printf("Digite uma opcao: ");
	scanf("%d", &opc);

	return(opc);
}
//===========================================================//

main()
{
    fGerarDomino();
	
	int opcMenu;
	
	putchar('\n');
    
    do
	{
		putchar('\n');
		opcMenu = fMenuInicio(); //guarda a opcao escolhida pelo usuario
		
		switch(opcMenu) //opcao para cada saida do menu
		{
			case 1: //ver pecas
				system("cls");
				fPrint();
				break;
			case 2: //embaralhar pecas
				system("cls");
				fShuffle();
				printf("\nPecas embaralhadas com sucesso.");
				break;
			case 3: //reorganizar pecas
				system("cls");
				fGerarDomino();
				printf("\nPecas reorganizadas com sucesso.");
				break;
			case 4: //sair do jogo
				printf("\nSaindo...\n");
				break;
			default:
				system("cls");
				printf("\nOpcao invalida.");
				break;
		}
	} while (opcMenu != 4); //condicao de parada
}

//===========================================================//
