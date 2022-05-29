    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <time.h>



    void adc_computador(novo_pc,numero);
    void funcao_menu (numero);
    void adc_intrevencao(nova_intre,numero);

    typedef struct
    {
    int dia, mes, ano;
    }t_data;




    typedef struct
    { // e struct designe para guardar a info sobre pcs
    int numero_id;
    char designacao [100] ;
    char nome_colaborador_pc [100];
    t_data data_atribuicao;
    char estado_do_pc [100];
    float valor_Equip;
    }t_pc;

    typedef struct
    { // e struct designe para guardar a info sobre intrevencoes
    int codigo_intrevencao ;
    int n_id_computador;
    t_data data_intrevencao;
    char designacao_problema [100];
    }t_solicitacao;

    typedef struct
    {
    int n_pcs, n_soli_intre, n_regis_intre;
    }cont;



int main ()
{
        cont numero;
        t_pc novo_pc[25];
        t_solicitacao nova_intre[100];
        numero.n_pcs=0;
        numero.n_soli_intre=0;
        numero.n_regis_intre=0;
        int opcao;

    do{
        funcao_menu (numero);
        fflush(stdin);
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1 :
        adc_computador(novo_pc,numero);
        numero.n_pcs=numero.n_pcs+1;
        break;



        case 2 :
        adc_intrevencao(nova_intre,numero);
        numero.n_soli_intre=numero.n_soli_intre+1;

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
    }while(opcao!=0);
}

funcao_menu (cont numero)
{
        printf("\n\n\n\n\t\t\t\t\tGestão de Computadores Portáteis\n\n");
        printf("Total de Computadores:%d \t\t\t",numero.n_pcs);
        printf("Valor dos Computadores(euros):(memoria a definir)\n");
        printf("Intervenções Solicitadas:%d\t\t\t\t\t",numero.n_soli_intre);
        printf("Intervenções Efetuadas:%d \n\n",numero.n_regis_intre);

        printf("1. Novo Computador\n");
        printf("2. Solicitar Intervenção\n");
        printf("3. Registar Intervenção\n");
        printf("4. Listar\n");
        printf("5. Informações\n");
        printf("6. Gravar\n");
        printf("0. Sair\n\n");

        printf("Selecione a Opcao:");
}


void adc_computador(t_pc novo_pc[],cont numero)
{
        int f_numero_id , f_dia, f_mes ,f_ano;
        char f_designacao [100], f_nome_colaborador_pc [100], f_estado_do_pc [100] ;
        float f_valor_Equip;


        printf("\nIntroduza o Número de Identificação:\n");
        fflush(stdin);
        scanf("%d",&f_numero_id);
        novo_pc[numero.n_pcs].numero_id=f_numero_id;
        printf("%d\n",novo_pc[numero.n_pcs].numero_id);

        printf("\nIntroduza uma designacao:\n");
        fflush(stdin);
        scanf("%s",&f_designacao);
        strcpy(novo_pc[numero.n_pcs].designacao,f_designacao);
        printf("%s\n",novo_pc[numero.n_pcs].designacao);


        printf("\nIntroduza o nome do colaborador com o computador :\n");
        fflush(stdin);
        scanf("%s",&f_nome_colaborador_pc);
        strcpy(novo_pc[numero.n_pcs].nome_colaborador_pc,f_nome_colaborador_pc);
        printf("%s\n",novo_pc[numero.n_pcs].nome_colaborador_pc);

        printf("\nIntroduza uma data de atribuicao no formato -> ano,mes,dia\n");
        fflush(stdin);
        scanf("%d,%d,%d",&f_ano,
                         &f_mes,
                         &f_dia);
        novo_pc[numero.n_pcs].data_atribuicao.ano=f_ano;
        novo_pc[numero.n_pcs].data_atribuicao.mes=f_mes;
        novo_pc[numero.n_pcs].data_atribuicao.dia=f_dia;
        printf("%d,%d,%d",novo_pc[numero.n_pcs].data_atribuicao.ano,
                         novo_pc[numero.n_pcs].data_atribuicao.mes,
                         novo_pc[numero.n_pcs].data_atribuicao.dia);


        printf("\nIntroduza o estado do computador:\n");
        fflush(stdin);
        scanf("%s",&f_estado_do_pc);
        strcpy(novo_pc[numero.n_pcs].estado_do_pc,f_estado_do_pc);
        printf("%s\n",novo_pc[numero.n_pcs].estado_do_pc);


        printf("\nIntroduza o valor do computador :\n");
        fflush(stdin);
        scanf("%s",&f_estado_do_pc);
        strcpy(novo_pc[numero.n_pcs].estado_do_pc,f_estado_do_pc);
        printf("%s\n",novo_pc[numero.n_pcs].estado_do_pc);
}

void adc_intrevencao(t_solicitacao nova_intre [],cont numero)
{
    int f_codigo_intrevencao,f_n_id_computador, f_dia,f_mes,f_ano;
    char f_designacao_problema [100];

    printf("\nIntroduza o codigo de intrevencao:\n");
    fflush(stdin);
    scanf("%d",&f_codigo_intrevencao);
    nova_intre[numero.n_soli_intre].codigo_intrevencao=f_codigo_intrevencao;
    printf("%d\n",nova_intre[numero.n_soli_intre].codigo_intrevencao);

    printf("\nIntroduza o numero de identificacao do computador:\n");
    fflush(stdin);
    scanf("%d",&f_n_id_computador);
    nova_intre[numero.n_soli_intre].n_id_computador=f_n_id_computador;
    printf("%d\n",nova_intre[numero.n_soli_intre].n_id_computador);

    printf("\nIntroduza uma data de atribuicao no formato -> ano,mes,dia\n");
    fflush(stdin);
    scanf("%d,%d,%d",&f_ano,
                     &f_mes,
                     &f_dia);
    nova_intre[numero.n_soli_intre].data_intrevencao.ano=f_ano;
    nova_intre[numero.n_soli_intre].data_intrevencao.mes=f_mes;
    nova_intre[numero.n_soli_intre].data_intrevencao.dia=f_dia;

    printf("%d,%d,%d",nova_intre[numero.n_soli_intre].data_intrevencao.ano,
                      nova_intre[numero.n_soli_intre].data_intrevencao.mes,
                      nova_intre[numero.n_soli_intre].data_intrevencao.dia);

    printf("\nIntroduza uma breve descricao do problema:\n");
    fflush(stdin);
    scanf("%s",&f_designacao_problema);
    strcpy(nova_intre[numero.n_soli_intre].designacao_problema,f_designacao_problema);
    printf("%s\n",nova_intre[numero.n_soli_intre].designacao_problema);

}


