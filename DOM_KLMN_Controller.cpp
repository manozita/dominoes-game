//DOM-KLMN - Projeto Domino - Etapa 3
//20/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.cpp" 
#include "Dom_KLMN_Controller.h"

void fIniciarJogo () //inicio do jogo
{
	fflush(stdin); //limpar buffer
	
	int opcMenu;
	
	putchar('\n');
    
    do
	{
		putchar('\n');
		opcMenu = fMenuInicio(); //guardar a opcao escolhida pelo usuario
		
		switch(opcMenu) //opcao para cada saida do menu
		{
			case 1: //inicio com 2 jogadores
				system("cls");
				fGerarDomino();
				fDoisJogadores ();
				break;
			case 2: //inicio com 1 jogador
				{
				system("cls");
				fGerarDomino();
				char msg[] = "\nFuncao nao implementada.";
				fMensagem (msg);
				break;
				}
			case 0: //sair do jogo
				{
				system("cls");
				char msg[] = "\nSaindo...\n";
				fMensagem (msg);
				break;
				}
			default:
				{
				system("cls");
				char msg[] = "\nOpcao invalida.";
				fMensagem (msg);
				break;
				}
		}
	} while (opcMenu != 0); //condicao de parada
}

void fGerarDomino () //gerar o domino inicial
{
	int i, j;
	int n = 0;
	numeroJogadas = 0; //inicializar numero de jogadas como 0
	
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

void fShuffle () //aleatorizar ordem das pecas
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

void fSepararPecas () //separar as pecas para cada jogador e deposito
{
	fShuffle ();
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (i < 7)
			peca[i].status = 1; //pecas do primeiro jogador
		else if (i < 14)
			peca[i].status = 2; //pecas do segundo jogador (ou computador)
		else
			peca[i].status = 3; //pecas do deposito
	}
}

void fPrimeiroLance() //definir de quem sera a primeira jogada
{
	int i, pj, dupla;
	pj = -1; //posicao da peca encontrada
	dupla = -1;
	//pesquisar entre as peças com lado1 = lado2
	for (i=0; i<14; i++)
	{
		if (peca[i].lado1 == peca[i].lado2)
		{
			if (peca[i].lado1 > dupla)
			{
				dupla = peca[i].lado1;
				pj = i;
			}
		}
	}
	//se nao encontrar, escolher a peca com maior soma
	if (pj == -1)
	{
		dupla = 0;
		for (i=0; i<14; i++)
		{
			if (peca[i].lado1 + peca[i].lado2 > dupla)
			{
				dupla = peca[i].lado1 + peca[i].lado2;
				pj = i;
			}
		}
	}
	//descobrir qual o jogador que jogou a primeira peca
	J = peca[pj].status;
	
	//carregar mesa com a primeira peca na posicao 0
	mesa[0].lado1 = peca[pj].lado1; mesa[0].lado2 = peca[pj].lado2;
	peca[pj].status = 4; //status da peca na mesa
	
	numeroJogadas++; //primeira jogada feita
	
}

void fDoisJogadores () //iniciar o jogo para dois jogadores
{
	
	fSepararPecas ();
	fPrimeiroLance();
	
	fPrintPrimeiroJogador();
	
	do
	{
		
		J = (J == 1) ? 2 : 1; //J = 1? se sim, J = 2, se nao, J = 1
		
		fMesa();
		
		if (fMenuJogador(J) == false) //se o jogador digitar para sair do jogo
			break;
			
		system("cls"); //limpar a tela para o proximo jogador
		
	} while (1);
}

bool fMenuJogador (int jogador) //ler as opcoes do menu
{
	do
	{
		fPrintPecas(jogador);
		char opc[2];

		fMensagem ("J - Jogar\nC - Comprar\nP - Passar\nS - Sair (fim de jogo)\n");

		do
		{
			fMensagem ("Opcao: ");
			fflush(stdin); //limpar o buffer
			scanf("%c", &opc[0]);
			if (opc[0] == '\0') //caso nada tenha sido digitado
			{
				fMensagem ("\nOpcao invalida.");
			}
		} while (opc[0] == '\0');

		opc[0] = toupper(opc[0]); //deixar caractere minusculo maiusculo

		switch(opc[0])
		{
			case 'J': //jogar uma peca
				if (fJogada(jogador)) //se a jogada foi bem sucedida (ou seja, retorna true)
					return true;
				break;
			case 'C': //comprar uma peca
				fCompra(jogador);
				break;
			case 'P': //passar a jogada
			{
				if (fDepositoVazio() == false) //caso o deposito nao estiver vazio
				{
					fMensagem("\nPassagem bloqueada. O deposito nao esta vazio.\nVoce deve jogar ou comprar.\n\n");
					break;
				}
				fMensagem ("\nPassando jogada...");
				return true; //passar jogada
			}
			case 'S': //finalizar o jogo e voltar ao menu
			{
				fMensagem ("\nFinalizando jogo...");
				return false; //sair do jogo
			}
			default:
			{
				fMensagem ("\nOpcao invalida.\n\n");
				break;
			}
		}

	} while (1);
	
}

bool fJogada(int jogador) //jogar
{
	int j;
	
	
	for (j = 0; j < MAX; j++) //varrer todas as pecas disponiveis e descobrir se alguma delas e jogavel
	{
		if (peca[j].status == jogador && ((mesa[0].lado1 == peca[j].lado1 || mesa[0].lado1 == peca[j].lado2) || (mesa[numeroJogadas-1].lado2 == peca[j].lado1 || mesa[numeroJogadas-1].lado2 == peca[j].lado2)))
		{
			break;
		}
	}
	if (j >= MAX) //nenhuma peca do jogador e jogavel
	{
		fMensagem("\nNao ha pecas disponiveis para jogada.\nVoce deve comprar uma peca.\n\n");
		return false; //jogada mal sucedida
	}
	
	char opc[2];
	int pj, numeroPeca, aux;
	do
	{
		fMensagem ("Escolha a peca para jogar (0 para desistir): ");
		fflush(stdin); //limpar o buffer
		scanf("%c", &opc[0]);
		opc[0] = tolower(opc[0]); //convertendo o caractere para letra minuscula
		if (opc[0] == '0') //desistir da jogada
		{
			putchar('\n');
			return false;
		}
		else if (opc[0] == '\0' || opc[0] < 97 || opc[0] > indicePeca)
		{
			fMensagem ("\nOpcao invalida.\n\n");
			continue;
		}
	
		numeroPeca = (int)(opc[0]);

		aux = 97-1; //inicializado para 0 pecas
			
		for (pj = 0; pj < MAX; pj++)
		{
			if (peca[pj].status == jogador)
			{
				aux++; //mais uma peca pertencente ao usuario
				if (aux == numeroPeca)
				{
					break;
				}
			}
		}
		
		//pj agora possui o indice da peca a se jogar
		
		aux = fChecarPeca(pj); //checar se a peca e jogavel
			
		if (aux == 0) //a peca nao e jogavel
			continue;
		else if (aux == 1) //peca jogada na esquerda da mesa
			carregaMesaE(pj);
		else //peca jogada na direita da mesa
			carregaMesaD(pj);
			
		break;
		
	} while (1);
	
	return true;
}

int fChecarPeca(int i) //checar se a peca e valida
{
	char opc[2];
	
	if ((mesa[0].lado1 == peca[i].lado1 || mesa[0].lado1 == peca[i].lado2) && (mesa[numeroJogadas-1].lado2 == peca[i].lado1 || mesa[numeroJogadas-1].lado2 == peca[i].lado2))
	{
		do 
		{
			fMensagem("Escolha um lado (E/D): ");
			fflush(stdin);
			scanf("%c", &opc[0]);
			opc[0] = tolower(opc[0]); //convertendo o caractere para letra minuscula
			if (opc[0] == '\0' || (opc[0] != 'd' && opc[0] != 'e'))
			{
				fMensagem ("\nOpcao invalida.\n\n");
			}
			else
				break;
		} while (1);
		
		if (opc[0] == 'd')
			return 2; //2 - direita
		else
			return 1; //1 - esquerda	
	}
	
	if (mesa[0].lado1 == peca[i].lado1 || mesa[0].lado1 == peca[i].lado2)
	{
		return 1;
	}
	else if (mesa[numeroJogadas-1].lado2 == peca[i].lado1 || mesa[numeroJogadas-1].lado2 == peca[i].lado2)
	{
		return 2;
	}
	
	fMensagem ("Jogada invalida.\n\n");
	
	return 0;
	
}

void carregaMesaE(int Pj) //atualizar dados da mesa para jogada na esquerda
{
	//deslocamento de toda a mesa para abrir a primeira posição 0
	for(int i = numeroJogadas; i > 0; i--)
		mesa[i] = mesa[i-1];

	//verifica se será necessário inverter a peça a ser jogada e
	//joga na posição 0 da mesa

	if (peca[Pj].lado2 == mesa[0].lado1)
	{
		mesa[0].lado2 = peca[Pj].lado2;
		mesa[0].lado1 = peca[Pj].lado1;
	}
	else
	{
		mesa[0].lado2 = peca[Pj].lado1;
		mesa[0].lado1 = peca[Pj].lado2;
	}
	//atualiza a variável global mesaE com o ladoE agora atualizado

	numeroJogadas++;

	peca[Pj].status = 4; //atualiza o status da peça jogada

}

void carregaMesaD(int Pj) //atualizar dados da mesa para jogada na direita
{

	//verifica se será necessário inverter a peça a ser jogada e
	//joga na posição 0 da mesa

	if (peca[Pj].lado1 == mesa[numeroJogadas-1].lado2)
	{
		mesa[numeroJogadas].lado2 = peca[Pj].lado2;
		mesa[numeroJogadas].lado1 = peca[Pj].lado1;
	}

	else
	{
		mesa[numeroJogadas].lado2 = peca[Pj].lado1;
		mesa[numeroJogadas].lado1 = peca[Pj].lado2;
	}
	//atualiza a variável global mesaE com o ladoE agora atualizado

	numeroJogadas++;

	peca[Pj].status = 4; //atualiza o status da peça jogada
}

void fCompra(int jogador) //comprar peca
{
	for (int i = 14; i < 28; i++)
	{
		if (peca[i].status == 3) //status 3 = na mesa
		{
			peca[i].status = jogador; //peca comprada
			fMesa ();
			return;
		}
	}
	fMensagem("Nada a comprar.\n");
}

bool fDepositoVazio() //verificar se esta disponivel para compras
{
	for(int i = 0; i < 28; i++)
	{
		if (peca[i].status == 3) //se a peca estiver disponivel para compra
		return false;
	}
	return true;
}





