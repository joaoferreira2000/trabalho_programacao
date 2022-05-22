#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define n_pc 25

void opc_escolhida();
int adc_computador();
char adc_designacao();

typedef struct{
int dia, mes, ano;
}t_data;


typedef struct {                // e struct designe para guardar a info sobre pcs
    int numero_id [20];
    char designacao [50];
    char nome_colaborador_pc[50];
    t_data data_atribuicao;
    char estado_do_pc[50];
}t_pc;



int main ()
{

    t_pc pc[25];

    int opcao;
    printf("\n\n\n\n\t\t\t\t\tGestão de Computadores Portáteis\n\n");
    printf("Total de Computadores: (memoria a definir) \t\t\t");
    printf("Valor dos Computadores(euros):(memoria a definir)\n");
    printf("Intervenções Solicitadas:\t\t\t\t\t");
    printf("Intervenções Efetuadas:(memoria a definir)\n\n");

    printf("1. Novo Computador\n");
    printf("2. Solicitar Intervenção\n");
    printf("3. Registar Intervenção\n");
    printf("4. Listar\n");
    printf("5. Informações\n");
    printf("6. Gravar\n");
    printf("0. Sair\n\n");

    printf("Selecione a Opção:");

    fflush(stdin);
    scanf("%d",&opcao);

    opc_escolhida(opcao,pc );
}

void opc_escolhida(opcao,pc)
{
   switch (opcao)
   {
        case 1 :
            printf("ola");
       // adc_computador();
       // adc_descricao();
        break;

        case 2 :
        break;

        case 3 :
        break;

        case 4 :
        break;

        case 5 :
        break;

        case 6 :
        break;

        case 0 :
        break;

  return 0;
   }
}

int adc_computador()
{
    int numero;
    printf("\nIntroduza o Número de Identificação:\n");
    fflush(stdin);
    scanf("%d",&numero);
    return numero;
}

char adc_designacao()
{
    char deesignacao[50];
    printf("\nIntroduza uma designacao:\n");
    fflush(stdin);
    scanf("%c",designacao[50]);
    return designacao[50];
}
