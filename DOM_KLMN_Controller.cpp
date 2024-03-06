//DOM-KLMN - Projeto Domino - Etapa 2
//16/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.cpp" 
#include "Dom_KLMN_Controller.h"

void fGerarDomino ()
{
	int i, j;
	int n = 0;
	
	for (i = 0; i <= 6; i++) 
	{
        for (j = i; j <= 6; j++) 
		{
            peca[n].ladoE = i;
            peca[n].ladoD = j;
            n++;
        }
    }
}

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

void fAtribuicaoStatus ()
{
	int i;
	
	for (i = 0; i <= 6; i++) 
	{
        peca[i].status = 1;
    }
    
    for (i = 7; i <= 13; i++) 
	{
        peca[i].status = 2;
    }
}

void fIniciarJogo () 
{
	fShuffle ();
	
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
				fPrintPecas();
				break;
			case 2: //embaralhar pecas
				system("cls");
				fShuffle();
				char mens[] = "Pecas embaralhadas com sucesso.";
				fPrintMensagem(mens);
				break;
			case 3: //reorganizar pecas
				system("cls");
				fGerarDomino();
				mens[] = "Pecas reorganizadas com sucesso.";
				fPrintMensagem(mens);
				break;
			case 4: //sair do jogo
				mens[] = "Saindo...\n";
				fPrintMensagem(mens);
				break;
			default:
				system("cls");
				mens[] = "Opcao invalida.";
				fPrintMensagem(mens);
				break;
		}
	} while (opcMenu != 4); //condicao de parada
}
