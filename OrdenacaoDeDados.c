#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

    //Vetor que sera armazenado os dados
    int VETOR[100000];
    //Quantidade de dados que será trabalhado
    int qtde_dados;
    //Condição de alguns laços
    float condicao;


//-----------------------------------------------------------------------------------------------------
//Funcao para ordenar os dados com Isertion Sort

void insertion(int B[], int C){

    int valorAtual;
    int contador;
    int condicao;
    // Ticks é criado como clock
    clock_t Ticks[2];
    Ticks[0] = clock();
    for( contador=1; contador < qtde_dados; contador++ ){
      valorAtual = VETOR[contador];
      condicao = contador-1;
      while(condicao >= 0 && VETOR[condicao] > valorAtual){
        VETOR[condicao+1] = VETOR[condicao];
        condicao--;
      }
      VETOR[condicao+1] = valorAtual;
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) *  1000 / CLOCKS_PER_SEC;
    printf("Tempo gasto para ordenar: %g Milissegundos.", Tempo);
    getchar();
}


//-----------------------------------------------------------------------------------------------------
//Funcao para ordenar com Selection Sort

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection(int arr[], int n)
{

    int i, j, min_idx;


    clock_t Ticks[2];
    Ticks[0] = clock();
    //Mover um ​​por um limite de subarray não classificado
    for (i = 0; i < n-1; i++)
    {
        // Encontre o elemento mínimo na matriz não classificada
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Troque o elemento mínimo encontrado pelo primeiro elemento
        swap(&arr[min_idx], &arr[i]);
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 10000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto para ordenar: %g Milissegundos.", Tempo);
    getchar();
}


//-----------------------------------------------------------------------------------------------------
//Funcao barra de processo. tentei fazer melhor mas nao tive tempo... :/

void processo(int atual, int qtde){
    if (atual >= qtde * condicao){
        condicao = condicao + 0.05;
        printf("\xB2");
    }
}


//-----------------------------------------------------------------------------------------------------
//Funcao para gerar dados. Insere um dado no array e verifica se o dado está em sequencia e se é repetido

void gera_dados(int qtde){
    condicao = 0;
    int status = 0;
    int j = 0;
    int i = 0;
    system ("cls");
    printf("\n    Gerando DADOS...\n\n ");
    for (i = 0; i < qtde; ++i) {
        processo(i, qtde);
        do {
            VETOR[i] = rand() % qtde;
            status = 1;
            for (j = 0; (j < i) && (status == 1); ++j)
            if (VETOR[i] == VETOR[j])
                status = 0;
        } while (status == 0);
    }
}


//-----------------------------------------------------------------------------------------------------
//Funcao para mostrar os dados do Vetor. Percorre o vetor e imprime cada posição

void mostra_dados(){
    int i = 0;
    while (i < qtde_dados){
        printf("\t[%d]",VETOR[i]);
        i++;
    }
    printf("\n");
    system("PAUSE");
}


//-----------------------------------------------------------------------------------------------------
//Inicio do main (Apresentação e tratamento do menu e chamada das funções!

int main(void){
    int op = 1;

    while (op != 0){
        //Apresentacao do MENU
        system("cls");
        system("color 9");//03
        printf("\n\n\tAPS DE ORDENACAO DE DADOS\n\n\tOque deseja fazer?\n\n\t\t1 - GERAR DADOS\n\t\t2 - ORDENAR OS DADOS USANDO INSERTION SORT\n\t\t3 - ORDENAR OS DADOS USANDO SELECTION SORT\n\t\t4 - MOSTRAR OS DADOS ATUAIS\n\t\t5 - SOBRE/MANUAL\n\t\t0 - SAIR\n\n\tInforme a opcao desejada --> ");
        scanf("%d",&op);
        setbuf(stdin,NULL);
        //Fim Apresentacao do MENU
        //Inicio do tratamendo da opcao desejada
        switch (op){
        case 1:
            system("cls");
            printf("\n\n\tGERAR DADOS\n\n\tQual a quantidade de dados que vc deseja gerar?\n\n\n");
            printf("\tQUANTIDADE --> ");
            scanf("%d",&qtde_dados);
            setbuf(stdin,NULL);
            gera_dados(qtde_dados);
            break;
        case 2:
            insertion(VETOR, qtde_dados);
            break;
        case 3:
            selection(VETOR, qtde_dados);
            break;
        case 4:
            mostra_dados();
            break;
        case 5:
            system("cls");
            printf ("\n\t\t\t\t\tBem vindo(a) a APS de ORDENACAO do Bruno\n\n\n\tCom a interface altamente intuitiva e relativamente facil de criar e ordenar os dados!\n\n\tOpcao 1 (GERAR DADOS) Ao selecionar esta opcao sera exibida uma uma tela para escolher a quantidade de dados que devera ser criado, mas cuidado, o processo de criacao pode ser lento em grandes quantidades.\n\tOpcao 2 (ORDENAR OS DADOS USANDO INSERTION SORT) Ao selecionar esta opcao o array atual sera ordenado utilizando o metodo de insertion sort\n\tOpcao 3 (ORDENAR OS DADOS USANDO SELECTION SORT) Ao selecionar esta opcao o array atual sera ordenado utilizando a opcao SELECTION SORT\n\tOpcao 4 (MOSTRAR OS DADOS ATUAIS) Esta opcao pode ser chamada a qualquer momento e devera mostrar os dados atuais no array, seja antes ou depois de ordenar\n\tOpcao 5 (SAIR) Esta opcao e responsavel por terminar a execucao do aplicativo!\n\n\n");
            system("PAUSE");
            system("cls");
            break;
        case 0:
            system("cls");
            printf("Aplicativo finalizado!");
            break;
        default:
            printf("\n\n\t\t\t\tOps... nao encontrei esta opcao!\n\n");
            system("PAUSE");
        }
    }

  return 0;

}

