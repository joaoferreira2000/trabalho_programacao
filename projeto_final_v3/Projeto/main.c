    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <time.h>



    void adc_computador(novo_pc,numero);
    void funcao_menu (novo_pc,numero);
    void adc_intrevencao(nova_intre,numero);

    typedef struct
    {
    int dia, mes, ano;
    }t_data;




    typedef struct
    { // e struct designe para guardar a info sobre pcs
    char numero_id[25];
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
    float valor_total;
    }cont;



int main ()
{
        cont numero;
        t_pc novo_pc[25];
        t_solicitacao nova_intre[100];
        numero.n_pcs=0;
        numero.n_soli_intre=0;
        numero.n_regis_intre=0;
        numero.valor_total=0;
        int opcao;


    do{
        funcao_menu (novo_pc,numero);
        fflush(stdin);
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1 :
        adc_computador(novo_pc,numero);
        numero.valor_total=numero.valor_total+novo_pc[numero.n_pcs].valor_Equip;
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




void funcao_menu (t_pc novo_pc[], cont numero)
{
        printf("\n\n\n\n\t\t\t\t\tGest�o de Computadores Port�teis\n\n");
        printf("Total de Computadores:%d \t\t\t",numero.n_pcs);
        printf("Valor dos Computadores(euros):%.2f\n",numero.valor_total);
        printf("Interven��es Solicitadas:%d\t\t\t\t\t",numero.n_soli_intre);
        printf("Interven��es Efetuadas:%d \n\n",numero.n_regis_intre);

        printf("1. Novo Computador\n");
        printf("2. Solicitar Interven��o\n");
        printf("3. Registar Interven��o\n");
        printf("4. Listar\n");
        printf("5. Informa��es\n");
        printf("6. Gravar\n");
        printf("0. Sair\n\n");

        printf("Selecione a Opcao:");
}


void adc_computador(t_pc novo_pc[],cont numero)
{
        int  f_dia, f_mes ,f_ano,i,x,repeat,do_ok,valor;
        char f_numero_id[25],f_designacao [100], f_nome_colaborador_pc [100], f_estado_do_pc [100] ;
        float f_valor_Equip;
        do_ok=0;
        repeat=0;

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza o N�mero de Identifica��o ate 25 carateres:\n");


        do
        {
            repeat=0;
            x=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_numero_id);
            for (i=0; i<25;i++)
            {
                if (f_numero_id[i]>=48 &&  f_numero_id[i]<=57)
                {
                }
                else if (f_numero_id[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_numero_id[i]=='\0' && repeat==0)
                {
                    for (x=0; x<25;x++)
                    {
                        valor=strcmp(novo_pc[x].numero_id,f_numero_id);
                        if (valor==0)
                        {
                            repeat=1;
                            printf("\nNumero de identificacao ja atribuido,\nIntroduza um novo N�mero de Identifica��o:\n");
                            break;
                        }
                        else if (valor!=0 && x!=numero.n_pcs)
                        {

                        }
                        else if ((valor!=0 || numero.n_pcs==0) && x==numero.n_pcs && repeat==0)
                        {
                            do_ok=1;
                            break;
                        }
                    }
                }
                else if (do_ok)//(f_numero_id[i]=='\0' && repeat==0 && numero.n_pcs==0)
                {
                    break;
                }
                else
                {
                    repeat=1;
                    printf("\nNumero de id incorreto,\nintroduza apenas carateres ddo tipo ('0' a '9')");
                    printf("\nIntroduza um novo numero de id para o computador :\n");
                    break;
                }


            }
       } while (do_ok!=1);
       do_ok=0;
       repeat=0;
        strcpy(novo_pc[numero.n_pcs].numero_id,f_numero_id);
        printf("%s\n",novo_pc[numero.n_pcs].numero_id);

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza uma designacao:\n");
        do
        {
            repeat=0;
            x=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_designacao);
            for (i=0; i<100;i++)
            {
                if ((f_designacao[i]>=48 &&  f_designacao[i]<=57)||
                    (f_designacao[i]>=97 &&  f_designacao[i]<=122) ||
                    (f_designacao[i]>=65 &&  f_designacao[i]<=90) ||
                    (f_designacao[i]==32))
                {
                }
                else if (f_designacao[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_designacao[i]=='\0' && repeat==0)
                {
                    do_ok=1;
                    break;
                }else
                {
                    repeat=1;
                    printf("\nDesignacao impropria,\nintroduza apenas carateres do tipo ('a' a 'z'),('A' a 'Z'),('0' a '9', ");
                    printf("\nIntroduza uma nova designacao para o computador :\n");
                    break;
                }
            }
        }while (do_ok!=1);
        strcpy(novo_pc[numero.n_pcs].designacao,f_designacao);
        printf("%s\n",novo_pc[numero.n_pcs].designacao);


        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza o nome do colaborador com o computador :\n");
        do
        {
            fflush(stdin);
            gets(f_nome_colaborador_pc);
            repeat=0;
            for (i=0; i<100;i++)
            {
                if ((f_nome_colaborador_pc[i]>=97 &&  f_nome_colaborador_pc[i]<=122) ||
                    (f_nome_colaborador_pc[i]>=65 &&  f_nome_colaborador_pc[i]<=90) ||
                    (f_nome_colaborador_pc[i]==32))
                {

                }

                else if (f_nome_colaborador_pc[i]=='\0' && repeat==0)
                {
                    do_ok=1;
                    break;
                }
                else if (f_nome_colaborador_pc[i]=='\0' && repeat==1)
                {
                    break;
                }
                else
                {
                    repeat=1;
                    printf("\nNome do colaborador incorreto,\nintroduza apenas carateres do tipo ('a' a 'z') ou('A' a 'Z')");
                    printf("\nIntroduza um novo nome do colaborador com o computador :\n");
                    break;
                }


            }
       } while (do_ok!=1);
       do_ok=0;
       repeat=0;
        strcpy(novo_pc[numero.n_pcs].nome_colaborador_pc,f_nome_colaborador_pc);
        printf("%s\n",novo_pc[numero.n_pcs].nome_colaborador_pc);

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza uma data de atribuicao no formato -> ano,mes,dia\n");
        do
        {
             fflush(stdin);
             scanf("%d,%d,%d",&f_ano,
                              &f_mes,
                              &f_dia);
          if (((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>32)||//anos nao bissextos
                ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>31)||//anos nao bissextos
                (f_mes==2&& f_dia>28))&&f_ano%4!=0)||//anos nao bissextos
                ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>32)||//anos bissextos
                ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>31)||//anos bissextos
                (f_mes==2&& f_dia>29))&&(f_ano%4==0 ||//anos bissextos
                (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                 f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                 f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                 f_ano!=1000))));//anos bissextos
          {

           printf("\nData Impropria,\nIntroduza uma nova data de atribuicao no formato -> ano,mes,dia\n");
          }



        }while(((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>31)||//anos nao bissextos
                ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>30)||//anos nao bissextos
                (f_mes==2&& f_dia>28))&&f_ano%4!=0 && f_mes>12)||//anos nao bissextos


                (((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>31)||//anos bissextos
                ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>30)||//anos bissextos
                (f_mes==2&& f_dia>29))&&(f_ano%4==0 && f_mes>12))||//anos bissextos
                ((f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                 f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                 f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                 f_ano!=1000 )&& f_mes>12)));//anos bissextos

         novo_pc[numero.n_pcs].data_atribuicao.ano=f_ano;
         novo_pc[numero.n_pcs].data_atribuicao.mes=f_mes;
         novo_pc[numero.n_pcs].data_atribuicao.dia=f_dia;
         printf("%d,%d,%d",novo_pc[numero.n_pcs].data_atribuicao.ano,
                           novo_pc[numero.n_pcs].data_atribuicao.mes,
                           novo_pc[numero.n_pcs].data_atribuicao.dia);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        printf("\nIntroduza o estado do computador:\n");
        fflush(stdin);
        scanf("%s",&f_estado_do_pc);
        strcpy(novo_pc[numero.n_pcs].estado_do_pc,f_estado_do_pc);
        printf("%s\n",novo_pc[numero.n_pcs].estado_do_pc);

        ////////////////////////////////////////////////////////////////////////////////////////////

        printf("\nIntroduza o valor do computador :\n");
        fflush(stdin);
        scanf("%f",&f_valor_Equip);
        novo_pc[numero.n_pcs].valor_Equip=f_valor_Equip;
        printf("%f\n",novo_pc[numero.n_pcs].valor_Equip);



        printf("%s\n",novo_pc[0].numero_id);


        printf("%s\n",novo_pc[1].numero_id);


        printf("%s\n",novo_pc[2].numero_id);

}

void adc_intrevencao(t_solicitacao nova_intre [],cont numero)
{
    int f_codigo_intrevencao,f_n_id_computador, f_dia,f_mes,f_ano;
    char f_designacao_problema [100];


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\nIntroduza o codigo de intrevencao:\n");
    do
    {
        fflush(stdin);
        scanf("%d",&f_codigo_intrevencao);
        if (numero.n_soli_intre!=0&& f_codigo_intrevencao==nova_intre[numero.n_soli_intre-1].codigo_intrevencao)
        {
            printf("\nCodigo de intrevencao ja atribuido,\nIntroduza um novo codigo de intrevencao:\n");
        }

    }while (numero.n_soli_intre!=0&& f_codigo_intrevencao==nova_intre[numero.n_soli_intre-1].codigo_intrevencao);
    nova_intre[numero.n_soli_intre].codigo_intrevencao=f_codigo_intrevencao;
    printf("%d\n",nova_intre[numero.n_soli_intre].codigo_intrevencao);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\nIntroduza o numero de identificacao do computador:\n");
    fflush(stdin);
    scanf("%d",&f_n_id_computador);
    nova_intre[numero.n_soli_intre].n_id_computador=f_n_id_computador;
    printf("%d\n",nova_intre[numero.n_soli_intre].n_id_computador);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\nIntroduza uma breve descricao do problema:\n");
    fflush(stdin);
    scanf("%s",&f_designacao_problema);
    strcpy(nova_intre[numero.n_soli_intre].designacao_problema,f_designacao_problema);
    printf("%s\n",nova_intre[numero.n_soli_intre].designacao_problema);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
