//DOM-KLMN - Projeto Domino - Etapa 3
//20/08/2023

void fIniciarJogo (); //inicio do jogo
void fGerarDomino (); //gerar o domino inicial
void fShuffle (); //aleatorizar ordem das pecas
void fSepararPecas (); //separar as pecas para cada jogador e deposito
void fPrimeiroLance(); //definir de quem sera a primeira jogada
void fDoisJogadores (); //iniciar o jogo para dois jogadores
bool fMenuJogador (int jogador); //ler as opcoes do menu
bool fJogada (int jogador); //jogar
int fChecarPeca(int i); //checar se a peca e valida
void carregaMesaE(int pj); //atualizar dados da mesa para jogada na esquerda
void carregaMesaD(int pj); //atualizar dados da mesa para jogada na direita
void fCompra (int jogador); //comprar peca
bool fDepositoVazio(); //verificar se esta disponivel para compras
bool fPecasJogaveis(int jogadorDaVez); //checa se ha pecas jogaveis para o jogador da vez
int fChecarVencedor(); //checa se ha um vencedor
