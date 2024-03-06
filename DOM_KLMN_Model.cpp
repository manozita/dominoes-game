//DOM-KLMN - Projeto Domino - Etapa 2
//16/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_Model.h"

#define MAX 28
typedef struct pecas //estrutura para as pecas
{
	int ladoE; int ladoD; //valor numerico (1-6) de cada lado
	int pos; //posicao na ordem correta
	char status;
} valoresPecas;

valoresPecas peca[MAX]; 
valoresPecas aux; //auxiliar para a randomizacao

struct Mesa
{
	int ladoE;
	int ladoD;
} mesa[28];

