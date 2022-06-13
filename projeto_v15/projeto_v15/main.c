    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <time.h>



    void adc_computador(novo_pc,numero);
    void funcao_menu (novo_pc,numero);
    void adc_intrevencao(nova_intre,numero,novo_pc);
    void adc_registo(novo_pc,nova_intre,reg_intre,numero,fptr_log);
    void informacaoes(novo_pc,nova_intre,reg_intre,numero);
    void guardar(novo_pc, nova_intre, reg_intre, numero);
    void adc_listar(novo_pc, nova_intre, reg_intre, numero);


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
    { // e struct designe para guardar a info sobre solicitacoes de intrevencaos
    char codigo_intrevencao[25] ;
    char n_id_computador[25];
    t_data data_intrevencao;
    char designacao_problema [100];
    int numero_vetor1,resolvido;
    }t_solicitacao;

    typedef struct
    { // e struct designe para guardar a info sobre intrevencoes registadas
    char descricao_intrevencao[25];
    char numero_id[25];
    t_data data_intrevencao;
    float custo_intrevencao;
    }t_intrevencao;

    typedef struct
    {
    int n_pcs, n_soli_intre, n_regis_intre, n_operacional, n_por_intrevencao, n_avariados;
    float valor_total,custo_medio_intrevencoes, menor_valor;
    }cont;



int main ()
{
        cont numero;
        t_pc novo_pc[25];
        t_solicitacao nova_intre[100];
        t_intrevencao reg_intre[100];
        numero.n_pcs=0;
        numero.n_soli_intre=0;
        numero.n_regis_intre=0;
        numero.valor_total=0;
        numero.n_avariados=0;
        numero.n_operacional=0;
        numero.n_por_intrevencao=0;
        int opcao,x,y,i,do_ok;
        char ficheiro[100],ask;

        FILE *fptr_log;
        fptr_log = fopen("dados.log", "a+");
        if (fptr_log == NULL)
        {
        printf("Erro na abertura.");
        }
        do
        {
            do
            {
            do_ok=0;
            ask='e';
            printf("quer abrir um ficheiro com informacao anteriormente guardado??\n\n'Y' -> Yes // 'N' -> No\n");
            fflush(stdin);
            scanf("%c",&ask);
            if (ask == 121 || ask == 110)
            {
            do_ok=1;
            break;
            }
            else
            {
                printf("\nEscreva apenas 'Y' ou 'N'");
            }
            } while( ask!= 110 && ask!=121);
        if (ask == 121)
        {
            printf("\nInsira o nome do ficheiro que quer abrir: ");
            fflush(stdin);
            gets(ficheiro);
            FILE *fptr_bin;
            fptr_bin=fopen(ficheiro, "rb");
            if (fptr_bin == NULL)
            {
                printf("\nEsse ficheiro nao existe\n");
            }
            else
            {
            printf("\nO ficheiro %s vai ser carregado\n", ficheiro);
            fread(novo_pc, sizeof(t_pc), 25, fptr_bin);
            fread(nova_intre, sizeof(t_solicitacao), 100, fptr_bin);
            fread(reg_intre, sizeof(t_intrevencao), 100, fptr_bin);
            fread(&numero, sizeof(cont), 1, fptr_bin);
            fclose(fptr_bin);
            }
        }
        else if (ask==110)
        {

        }

        }while (do_ok!=1);

    do{
        numero.n_por_intrevencao=0;
        numero.n_avariados=0;
        numero.n_operacional=0;


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
        if (numero.n_pcs==0)
        {
            printf("\npor favor adicione um computador primeiro");
        }
        else if (numero.n_pcs>0)
        {
        adc_intrevencao(nova_intre,numero,novo_pc);
        numero.n_soli_intre=numero.n_soli_intre+1;
        }
        break;

        case 3 :
        if (numero.n_soli_intre==0)
        {
            printf("\npor favor adicione uma solicitacao de intrevencao primeiro");
        }
        else if (numero.n_soli_intre>0)
        {
        adc_registo(novo_pc,nova_intre,reg_intre,numero, fptr_log);
        numero.custo_medio_intrevencoes=numero.custo_medio_intrevencoes+reg_intre[numero.n_regis_intre].custo_intrevencao;
        if (numero.n_regis_intre==0)
        {
            numero.menor_valor=reg_intre[numero.n_regis_intre].custo_intrevencao;
        }
        else if ((numero.n_regis_intre>0) && ((numero.menor_valor)>reg_intre[numero.n_regis_intre].custo_intrevencao))
        {
            numero.menor_valor=reg_intre[numero.n_regis_intre].custo_intrevencao;
        }
        numero.n_regis_intre=numero.n_regis_intre+1;
        }
        break;


        case 4 :
            adc_listar(novo_pc, nova_intre, reg_intre, numero);
        break;


        case 5 :
        if (numero.n_pcs==0)
        {
            printf("\npor favor adicione um computador primeiro");
        }
        else if (numero.n_pcs>0)
        {
        for (i=0; i<25;i++)
        {
            if((strcmp(novo_pc[i].estado_do_pc,"1")==0) && i<=numero.n_pcs)
            {
                numero.n_operacional=numero.n_operacional+1;
            }
            if((strcmp(novo_pc[i].estado_do_pc,"2")==0) && i<=numero.n_pcs)
            {
                numero.n_por_intrevencao=numero.n_por_intrevencao+1;
            }
            if((strcmp(novo_pc[i].estado_do_pc,"3")==0) && i<=numero.n_pcs)
            {
                numero.n_avariados=numero.n_avariados+1;
            }
        }
        informacaoes(novo_pc,nova_intre,reg_intre,numero);
        }
        break;

        case 6 :
        if (numero.n_pcs==0)
        {
            printf("\npor favor adicione um computador primeiro");
        }
        else if (numero.n_pcs>0)
        {
            guardar(novo_pc, nova_intre, reg_intre, numero);
        }
        break;



        case 0 :
        do
        {
            do
            {
            do_ok=0;
            ask='e';
            printf("quer guardar a informacao num ficheiro antes de sair??\n\n'Y' -> Yes // 'N' -> No\n");
            fflush(stdin);
            scanf("%c",&ask);
            if (ask == 121 || ask == 110 || ask!= 78 || ask !=89)
            {
            do_ok=1;
            break;
            }
            else
            {
                printf("\nEscreva apenas 'Y' ou 'N'");
            }
            } while( ask!= 110 && ask!=121 && ask!= 78 && ask !=89);
        if (ask == 121 || ask == 89)
        {
            printf("Insira o nome do ficheiro que guardar: ");
            fflush(stdin);
            gets(ficheiro);
            FILE *fptr_bin;
            fptr_bin=fopen(ficheiro, "wb");
            fwrite(novo_pc, sizeof(t_pc), 25, fptr_bin);
            fwrite(nova_intre, sizeof(t_solicitacao), 100, fptr_bin);
            fwrite(reg_intre, sizeof(t_intrevencao), 100, fptr_bin);
            fwrite(&numero, sizeof(cont), 1, fptr_bin);
            fclose(fptr_bin);
        }
        else if (ask==110 || ask == 78)
        {

        }
        }while (do_ok!=1);

        break;

        return 0;
        }
    }while(opcao!=0);
    fclose(fptr_log);
}




void funcao_menu (t_pc novo_pc[], cont numero)
{
        printf("\n\n\n\n\t\t\t\t\tGestao de Computadores Portateis\n\n");
        printf("Total de Computadores:%d \t\t\t",numero.n_pcs);
        printf("Valor dos Computadores(euros):%.2f\n",numero.valor_total);
        printf("Intervenoes Solicitadas:%d\t\t\t\t",numero.n_soli_intre);
        printf("Intervenoes Efetuadas:%d \n\n",numero.n_regis_intre);

        printf("1. Novo Computador\n");
        printf("2. Solicitar Intervencao\n");
        printf("3. Registar Intervencao\n");
        printf("4. Listar\n");
        printf("5. Informaoes\n");
        printf("6. Gravar\n");
        printf("0. Sair\n\n");

        printf("Selecione a Opcao:");
}

void adc_computador(t_pc novo_pc[],cont numero)
{
        int  i,z,x,repeat,do_ok,valor,f_dia,f_mes,f_ano;
        char f_numero_id[25],f_designacao [100], f_nome_colaborador_pc [100], f_estado_do_pc [100],f_cdia[2], f_cmes [2],f_cano [4],char_apoio;
        float f_valor_Equip;

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza o Numero de Identificacao ate 25 numeros:\n");
        do
        {
            x=0;
            z=0;
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
                            printf("\nNumero de identificacao ja atribuido,\nIntroduza um novo Numero de Identificacao:\n");
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
               else if (do_ok)
                {

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

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza uma designacao:\n");
        do
        {
            x=0;
            z=0;
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
                    printf("\nDesignacao impropria,\nintroduza apenas carateres do tipo ('a' a 'z'),('A' a 'Z'),('0' a '9')");
                    printf("\nIntroduza uma nova designacao para o computador :\n");
                    break;
                }
            }
        }while (do_ok!=1);

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza o nome do colaborador com o computador :\n");
        do
        {
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_nome_colaborador_pc);

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

        ////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza uma data de atribuicao no formatos : \nano ->\nmes ->\ndia ->\n");
        do
        {
            f_ano=0;
            f_mes=0;
            f_dia=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);

            printf("por favor introduzir o ano -> ");
            while(scanf("%d",&f_ano) != 1)
            {
                printf("por favor utilize apenas digitos para o ano: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o mes -> ");
            while(scanf("%d",&f_mes) != 1)
            {
                printf("por favor utilize apenas digitos para o mes: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o dia -> ");
            while(scanf("%d",&f_dia) != 1)
            {
                printf("por favor utilize apenas digitos para o dia: ");
                while(getchar() != '\n');
            }



         if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos nao bissextos
                    (f_mes==2&& f_dia>=29))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos bissextos
                    (f_mes==2&& f_dia>=30))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) || f_mes>=13)//anos bissextos
                {
                    repeat=1;
                    printf("\nData Impropria,\nIntroduza uma nova data de atribuicao no formato -> ano,mes,dia\n");
                }
                else if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos nao bissextos
                    (f_mes==2&& f_dia<=28))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos bissextos
                    (f_mes==2&& f_dia<=29))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) && f_mes<=12)
                    {
                    printf("a data introduzida foi %d,%d,%d?\n",f_ano,f_mes,f_dia);
                    do
                    {
                        printf("escreva 'y' -> sim e 'n' -> nao\n");
                        fflush(stdin);
                        scanf("%c",&x);
                        if (x == 121)
                        {
                        break;
                        }
                    } while( x!= 110 && x!=121);
                    if (x == 121)
                    {
                        do_ok=1;
                        break;
                    }

                    else
                    {
                        repeat=1;
                        do_ok=0;
                    }
                    }

        }while(do_ok!=1 && repeat!=0 && f_dia>0 && f_ano>0);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        printf("\nIntroduza o estado do computador:\n");

        do
        {
            repeat=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            printf("\nEscolha um numero para o estado do computador:\n1 -> operacional\n2 -> por intrevencao\n3 -> avariado\n");
            fflush(stdin);
            gets(f_estado_do_pc);
            for (i=0; i<100;i++)
            {
                if (f_estado_do_pc[i]>=49 &&  f_estado_do_pc[i]<=51)
                {

                }

                else if (f_estado_do_pc[i]=='\0' && repeat==0)
                {
                    do_ok=1;
                    break;
                }
                else if (f_estado_do_pc[i]=='\0' && repeat==1)
                {
                    break;
                }
                else
                {
                    repeat=1;
                    printf("\nEstado do computador incorreto,\nintroduza apenas numeros  de ('1' a '3')");
                    printf("\nIntroduza um novo estado do computador:\n");
                    break;
                }
            }


        }while (do_ok!=1);

        ////////////////////////////////////////////////////////////////////////////////////////////

        printf("\nIntroduza o valor do computador :\n");

        do
        {
            repeat=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            scanf("%f",&f_valor_Equip);
            do
            {
                printf("confirme o valor do computador %f\n",f_valor_Equip);
                printf("escreva 'y' -> sim e 'n' -> nao\n");
                fflush(stdin);
                scanf("%c",&x);
                if (x == 121)
                {
                do_ok=1;
                break;
                }
            } while( x!= 110 && x!=121);
            if (x == 121)
            {
                do_ok=1;
                break;
            }
            else
            {
                printf("intruduza um novo valor do computador:\n");
                do_ok=0;
            }

        }while (do_ok!=1);

        strcpy(novo_pc[numero.n_pcs].numero_id,f_numero_id);

        strcpy(novo_pc[numero.n_pcs].designacao,f_designacao);

        strcpy(novo_pc[numero.n_pcs].nome_colaborador_pc,f_nome_colaborador_pc);

        novo_pc[numero.n_pcs].data_atribuicao.ano=f_ano;
        novo_pc[numero.n_pcs].data_atribuicao.mes=f_mes;
        novo_pc[numero.n_pcs].data_atribuicao.dia=f_dia;

        strcpy(novo_pc[numero.n_pcs].estado_do_pc,f_estado_do_pc);


        novo_pc[numero.n_pcs].valor_Equip=f_valor_Equip;
}

void adc_intrevencao(t_solicitacao nova_intre [],cont numero,t_pc novo_pc[])
{
    int f_dia,f_mes,f_ano,do_ok,i,x,z,y,valor,repeat,numero_id_pc;
    char f_designacao_problema [100],f_n_id_computador[25],f_codigo_intrevencao[25];


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\nIntroduza o numero de identificacao do computador:\n");
        do
        {
            x=0;
            z=0;
            y=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_n_id_computador);
            for (i=0; i<100;i++)
            {
                if (f_n_id_computador[i]>=48 &&  f_n_id_computador[i]<=57)
                {
                }
                else if (f_n_id_computador[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_n_id_computador[i]=='\0' && repeat==0 && f_n_id_computador[0]!='\0')
                {
                    for (x=0; x<24;x++)
                    {
                        valor=strcmp(novo_pc[x].numero_id,f_n_id_computador);
                        if (valor!=0 && x!=numero.n_pcs)
                        {
                        }
                        else if (valor==0 )
                        {
                            numero_id_pc=x;
                            do_ok=1;
                            break;
                        }
                        else if (valor!=0  && x==numero.n_pcs)
                        {
                            printf("\nNumero de id, nao existe\nintroduza um numero de id de existente :\n");
                            repeat=1;
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    repeat=1;
                    printf("\nnumero de id improprio,\nintroduza apenas carateres do tipo ('0' a '9')");
                    printf("\nIntroduza um novo numero de id:\n");

                }
            }
        }while (do_ok!=1&&i>0);



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza o codigo de intrevencao:\n");
        do
        {
            y=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_codigo_intrevencao);
            for (i=0; i<24;i++)
            {
                if (f_codigo_intrevencao[i]>=48 &&  f_codigo_intrevencao[i]<=57)
                {
                }
                else if (f_codigo_intrevencao[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_codigo_intrevencao[i]=='\0' && repeat==0)
                {

                    for (x=0; x<100;x++)
                    {
                        valor=strcmp(nova_intre[x].codigo_intrevencao,f_codigo_intrevencao);
                        if (valor==0 && numero.n_soli_intre>0)
                        {
                            repeat=1;
                            printf("\ncodigo de intrevencao ja atribuido,\nIntroduza um novo codigo de intrevencao:\n");
                            break;
                        }
                        else if (valor!=0 && x!=numero.n_soli_intre)
                        {

                        }
                        else if ((valor!=0 || numero.n_soli_intre==0) && x==numero.n_soli_intre && repeat==0)
                        {
                            do_ok=1;
                            break;
                        }
                    }
                }
                else if (do_ok)
                {

                }
                else
                {
                    repeat=1;
                    printf("\nCodigo de intrevencao incorreto,\nintroduza apenas carateres ddo tipo ('0' a '9')");
                    printf("\nIntroduza um novo codigo de intrevencao para a intrevencao :\n");
                    break;
                }


            }
       } while (do_ok!=1);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        printf("\nIntroduza uma data de atribuicao no formatos : \nano ->\nmes ->\ndia ->\n");
        do
        {
            f_ano=0;
            f_mes=0;
            f_dia=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);

            printf("por favor introduzir o ano -> ");
            while(scanf("%d",&f_ano) != 1)
            {
                printf("por favor utilize apenas digitos para o ano: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o mes -> ");
            while(scanf("%d",&f_mes) != 1)
            {
                printf("por favor utilize apenas digitos para o mes: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o dia -> ");
            while(scanf("%d",&f_dia) != 1)
            {
                printf("por favor utilize apenas digitos para o dia: ");
                while(getchar() != '\n');
            }



         if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos nao bissextos
                    (f_mes==2&& f_dia>=29))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos bissextos
                    (f_mes==2&& f_dia>=30))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) || f_mes>=13)//anos bissextos
                {
                    repeat=1;
                    printf("\nData Impropria,\nIntroduza uma nova data de atribuicao no formato -> ano,mes,dia\n");
                }
                else if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos nao bissextos
                    (f_mes==2&& f_dia<=28))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos bissextos
                    (f_mes==2&& f_dia<=29))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) && f_mes<=12)
                    {
                    printf("a data introduzida foi %d,%d,%d?\n",f_ano,f_mes,f_dia);
                    do
                    {
                        printf("escreva 'y' -> sim e 'n' -> nao\n");
                        fflush(stdin);
                        scanf("%c",&x);
                        if (x == 121)
                        {
                        break;
                        }
                    } while( x!= 110 && x!=121);
                    if (x == 121)
                    {
                        do_ok=1;
                        break;
                    }

                    else
                    {
                        repeat=1;
                        do_ok=0;
                    }
                    }

        }while(do_ok!=1 && repeat!=0 && f_dia>0 && f_ano>0);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     printf("\nIntroduza uma designacao:\n");
        do
        {
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_designacao_problema);
            for (i=0; i<100;i++)
            {
                if ((f_designacao_problema[i]>=48 &&  f_designacao_problema[i]<=57)||
                    (f_designacao_problema[i]>=97 &&  f_designacao_problema[i]<=122) ||
                    (f_designacao_problema[i]>=65 &&  f_designacao_problema[i]<=90) ||
                    (f_designacao_problema[i]==32))
                {
                }
                else if (f_designacao_problema[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_designacao_problema[i]=='\0' && repeat==0)
                {
                    do_ok=1;
                    break;
                }else
                {
                    repeat=1;
                    printf("\nDesignacao impropria,\nintroduza apenas carateres do tipo ('a' a 'z'),('A' a 'Z'),('0' a '9')");
                    printf("\nIntroduza uma nova designacao para o computador :\n");
                    break;
                }
            }
        }while (do_ok!=1);
        if (strcmp(novo_pc[numero_id_pc].estado_do_pc,"1")==0)
        {
          strcpy(novo_pc[numero.n_pcs-1].estado_do_pc,"2");
        }

         strcpy(nova_intre[numero.n_soli_intre].n_id_computador,f_n_id_computador);

         strcpy(nova_intre[numero.n_soli_intre].codigo_intrevencao,f_codigo_intrevencao);

         nova_intre[numero.n_soli_intre].numero_vetor1=numero_id_pc;

         nova_intre[numero.n_soli_intre].resolvido=0;

         nova_intre[numero.n_soli_intre].data_intrevencao.ano=f_ano;
         nova_intre[numero.n_soli_intre].data_intrevencao.mes=f_mes;
         nova_intre[numero.n_soli_intre].data_intrevencao.dia=f_dia;

         strcpy(nova_intre[numero.n_soli_intre].designacao_problema,f_designacao_problema);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void adc_registo(t_pc novo_pc [],t_solicitacao nova_intre[],t_intrevencao reg_intre[],cont numero, FILE *fptr_log)
{
    int f_dia,f_mes,f_ano,do_ok,i,x,z,y,valor,repeat,contador,numero_intrevencao, vetor_intrevencao;
    char f_descricao_intrevencao [100],f_solicitacao_intrevencao [25], ask;
    float f_custo_intrevencao;
    ////////////////////////////////////////////////////////////////////
    printf("\nIntroduza o numero de solicitacao de intrevencao do computador:\n");
    do
    {
        x=0;
        z=0;
        y=0;
        vetor_intrevencao=0;
        i=0;
        valor=0;
        do_ok=0;
        contador=0;
        numero_intrevencao=0;
        repeat=0;
        fflush(stdin);
        gets(f_solicitacao_intrevencao);
        for (i=0; i<100;i++)
        {
            if (f_solicitacao_intrevencao[i]>=48 &&  f_solicitacao_intrevencao[i]<=57)
            {
            }
            else if (f_solicitacao_intrevencao[i]=='\0' && repeat==1)
            {
                break;
            }
            else if (f_solicitacao_intrevencao[i]=='\0' && repeat==0 && f_solicitacao_intrevencao[0]!='\0')
            {
                for (x=0; x<100;x++)
                {
                    vetor_intrevencao=x;
                    valor=strcmp(nova_intre[x].codigo_intrevencao,f_solicitacao_intrevencao);
                    if (valor!=0 && x!=numero.n_soli_intre)
                    {
                    }
                    else if (valor==0 && nova_intre[x].resolvido==0)
                    {
                        for (y=0;y<100;y++)
                        {
                            if (y<=numero.n_soli_intre-1 && nova_intre[y].resolvido==1)
                            {
                                numero_intrevencao=y;
                                contador=contador+1;
                            }
                        }
                    do_ok=1;
                    break;
                    }
                    else if  (valor==0 && nova_intre[x].resolvido==1)
                    {
                        printf("\nintrevencao ja efetuada,\nintroduza um novo condigo de intrevencao: ");
                        break;
                    }
                    else if (valor!=0  && x==numero.n_soli_intre)
                    {
                    printf("\nNumero de solicitacao de intrevencao, nao existe\nintroduza um solicitacao de intrevencao de existente :\n");
                    repeat=1;
                    break;
                    }
                }
                break;
            }
            else
            {
                repeat=1;
                printf("\nnumero de id improprio,\nintroduza apenas carateres do tipo ('0' a '9')");
                printf("\nIntroduza um novo numero de id:\n");
            }
        }
    }while (do_ok!=1&&i>0);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\nIntroduza uma descricao da intrevencao:\n");
        do
        {
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_descricao_intrevencao);
            for (i=0; i<100;i++)
            {
                if ((f_descricao_intrevencao[i]>=48 &&  f_descricao_intrevencao[i]<=57)||
                    (f_descricao_intrevencao[i]>=97 &&  f_descricao_intrevencao[i]<=122) ||
                    (f_descricao_intrevencao[i]>=65 &&  f_descricao_intrevencao[i]<=90) ||
                    (f_descricao_intrevencao[i]==32))
                {
                }
                else if (f_descricao_intrevencao[i]=='\0' && repeat==1)
                {
                    break;
                }
                else if (f_descricao_intrevencao[i]=='\0' && repeat==0)
                {
                    do_ok=1;
                    break;
                }else
                {
                    repeat=1;
                    printf("\descricao da intrevencao impropria,\nintroduza apenas carateres do tipo ('a' a 'z'),('A' a 'Z'),('0' a '9')");
                    printf("\nIntroduza uma nova descricao da intrevencao para o computador :\n");
                    break;
                }
            }
        }while (do_ok!=1);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf("\nIntroduza uma data de atribuicao no formatos -> \nano ->\nmes ->\ndia ->\n");
        do
        {
            f_ano=0;
            f_mes=0;
            f_dia=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);

            printf("por favor introduzir o ano -> ");
            while(scanf("%d",&f_ano) != 1)
            {
                printf("por favor utilize apenas digitos para o ano: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o mes -> ");
            while(scanf("%d",&f_mes) != 1)
            {
                printf("por favor utilize apenas digitos para o mes: ");
                while(getchar() != '\n');
            }

            fflush(stdin);
            printf("por favor introduzir o dia -> ");
            while(scanf("%d",&f_dia) != 1)
            {
                printf("por favor utilize apenas digitos para o dia: ");
                while(getchar() != '\n');
            }



         if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos nao bissextos
                    (f_mes==2&& f_dia>=29))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia>=32)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia>=31)||//anos bissextos
                    (f_mes==2&& f_dia>=30))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) || f_mes>=13)//anos bissextos
                {
                    repeat=1;
                    printf("\nData Impropria,\nIntroduza uma nova data de atribuicao no formato -> ano,mes,dia\n");
                }
                else if ((((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31 )||//anos nao bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos nao bissextos
                    (f_mes==2&& f_dia<=28))&&f_ano%4!=0)||//anos nao bissextos

                    ((((f_mes==1||f_mes==3||f_mes==5||f_mes==7||f_mes==8||f_mes==10||f_mes==12)&& f_dia<=31)||//anos bissextos
                    ((f_mes==4||f_mes==6||f_mes==9||f_mes==11)&& f_dia<=30)||//anos bissextos
                    (f_mes==2&& f_dia<=29))&&(f_ano%4==0 ||//anos bissextos
                    (f_ano!=400||f_ano!=800||f_ano!=1200||f_ano!=1600||f_ano!=2000||f_ano!=2400||f_ano!=2800||f_ano!=3200||//anos bissextos
                    f_ano!=3600||f_ano!=4000||f_ano!=4400||f_ano!=4800||f_ano!=5200||f_ano!=5600||f_ano!=6000||f_ano!=6400||//anos bissextos
                    f_ano!=6800||f_ano!=7200||f_ano!=7600||f_ano!=8000||f_ano!=8400||f_ano!=8800||f_ano!=9200||f_ano!=9600||//anos bissextos
                    f_ano!=1000)))) && f_mes<=12)
                    {
                    printf("a data introduzida foi %d,%d,%d?\n",f_ano,f_mes,f_dia);
                    do
                    {
                        printf("escreva 'y' -> sim e 'n' -> nao\n");
                        fflush(stdin);
                        scanf("%c",&x);
                        if (x == 121)
                        {
                        break;
                        }
                    } while( x!= 110 && x!=121);
                    if (x == 121)
                    {
                        do_ok=1;
                        break;
                    }

                    else
                    {
                        repeat=1;
                        do_ok=0;
                    }
                    }

        }while(do_ok!=1 && repeat!=0 && f_dia>0 && f_ano>0);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        do
        {
        printf("\nIntroduza o valor da intrevencao :\n");
            repeat=0;
            x=0;
            z=0;
            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            scanf("%f",&f_custo_intrevencao);
            do
            {
                printf("confirme o valor da intrevencao %f\n",f_custo_intrevencao);
                printf("escreva 'y' -> sim e 'n' -> nao\n");
                fflush(stdin);
                scanf("%c",&x);
                if (x == 121)
                {
                do_ok=1;
                break;
                }
            } while( x!= 110 && x!=121);
            if (x == 121)
            {
                if (contador==0)
                {
                do_ok=1;
                }
                else if (contador >0)
                {
                    if (f_custo_intrevencao>novo_pc[nova_intre[numero_intrevencao].numero_vetor1].valor_Equip)
                    {
                        do_ok=1;
                        do
                        {
                        ask=0;
                        printf("\no arranjo nao se justifica,\npretende passar o seu computador para avariado?");
                        printf("\n'y' -> yes , 'n' -> nao\n");
                        fflush(stdin);
                        scanf("%c", &ask);

                            if(ask==121)
                            {
                                strcpy(novo_pc[nova_intre[numero_intrevencao].numero_vetor1].estado_do_pc,"3");
                            }
                        }while (ask!=121 && ask!=110);
                    }
                }
            }
            else
            {
                do_ok=0;
            }
        }while (do_ok!=1);

        strcpy(reg_intre[numero.n_regis_intre].descricao_intrevencao,f_descricao_intrevencao);

        nova_intre[vetor_intrevencao].resolvido=1;

        reg_intre[numero.n_regis_intre].data_intrevencao.ano=f_ano;
        reg_intre[numero.n_regis_intre].data_intrevencao.mes=f_mes;
        reg_intre[numero.n_regis_intre].data_intrevencao.dia=f_dia;

        reg_intre[numero.n_regis_intre].custo_intrevencao=f_custo_intrevencao;

        fprintf(fptr_log, "\tDados da Intervencao com o codigo %s\n", f_solicitacao_intrevencao);
        fprintf(fptr_log, "Nome do Colaborador: %s", novo_pc[nova_intre[vetor_intrevencao].numero_vetor1].nome_colaborador_pc );
        fprintf(fptr_log, "Estado do Computador: %s", novo_pc[nova_intre[vetor_intrevencao].numero_vetor1].estado_do_pc );
        fprintf(fptr_log, "Data da intervencao: %d-%d-%d\n", f_ano, f_mes, f_dia);
        fprintf(fptr_log, "Descricao da intervencao: %s\n", f_descricao_intrevencao);
        fprintf(fptr_log, "Custo da intervencao: %f\n", f_custo_intrevencao);


}

void adc_listar(t_pc novo_pc[],t_solicitacao nova_intre[],t_intrevencao reg_intre[],cont numero)
{/*
    int do_ok,i,x,z,y;
    char opcao;

    printf("\n1->  Dados completos de todos os computadores introduzidos, incluindo as quantidades de intervencoes solicitadas e efetuadas para cada computador.");
    printf("\n2->  Custo medio de computadores\n3-> Intervencao(oes) com menor  custo.\n4->  Dados das intervenções solicitadas num determinado computador (identificado pelo utilizador).");
    printf("\n5->  Dados do computador correspondente ao registo de uma determinada solicitação(identificada pelo utilizador).\n");

    printf("\nSeleciona a opcao: ");

    fflush(stdin);
    scanf("%d",&opcao);


    switch(opcao)
    {
        case 1:
        for(x= 0; x<=25;x++)
        {
            printf("Computador n:%d",numero.n_pcs);
            printf("\nNumero_id:%s",novo_pc[x].numero_id);
            printf("\nDesignacao:%s",novo_pc[x].designacao);
            printf("\nData:%d,%d,%d",novo_pc[x].data_atribuicao.ano,novo_pc[x].data_atribuicao.mes,novo_pc[x].data_atribuicao.dia);
            printf("\nEstado do pc:%s",novo_pc[x].estado_do_pc);
            printf("\nValor a pagar:%f",novo_pc[x].valor_Equip);
            printf("\n Quantidade de intervencoes solicitadas:%s",nova_intre[x].n_id_computador);
            printf("\n Quantidade de intervencoes efetuadas:%s\n",nova_intre[x].codigo_intrevencao);
        }
        break;

        case 2:
        for(x= 0; x<=25;x++)
        {
            printf("Intervencoes solicitadas n:%d",numero.n_regis_intre);
            printf("\nnumero de identificacao do computador:%s",nova_intre[x].n_id_computador);
            printf("\nData:%d,%d,%d",nova_intre[x].data_intrevencao.ano,nova_intre[x].data_intrevencao.mes,nova_intre[x].data_intrevencao.dia);
            printf("\nBreve descricao do problema:%s",nova_intre[x].designacao_problema);
        }
        break;

        case 3:
        for(x= 0; x<=25;x++)
        {
            printf("Intervencoes efetuadas n:%d",x);
            printf("\ndescricao da intervencao:%s",reg_intre[x].descricao_intrevencao);
            printf("\nData:%d,%d,%d",reg_intre[x].data_intrevencao.ano,reg_intre[x].data_intrevencao.mes,reg_intre[x].data_intrevencao.dia);
            printf("\nCusto da intrevencao:%f",reg_intre[x].custo_intrevencao);
        }
        break;

        case 4:

            i=0;
            valor=0;
            do_ok=0;
            repeat=0;
            fflush(stdin);
            gets(f_n_id_computador);
            for (i=0; i<100;i++)
            {
                if (f_n_id_computador[i]>=48 &&  f_n_id_computador[i]<=57)
                {
                }
                else if (f_n_id_computador[i]=='\0' && repeat==1) // invalida
                {
                    break;
                }
                else if (f_n_id_computador[i]=='\0' && repeat==0 && f_n_id_computador[0]!='\0')
                {
                    for (x=0; x<24;x++)
                    {
                        valor=strcmp(novo_pc[x].numero_id,f_n_id_computador); // se as stings tiverem o mesmo valor são iguais
                        if (valor!=0 && x!=numero.n_pcs && x!= ID)
                        {
                        }
                        else if (valor==0 )
                        {
                            do_ok=1;
                            break;
                        }
                        else if (valor!=0  && x==numero.n_pcs && x == ID)
                        {
                            printf("\nNumero de id, nao existe\nintroduza um numero de id de existente :\n");
                            repeat=1;
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    repeat=1;
                    printf("\nnumero de id improprio,\nintroduza apenas carateres do tipo ('0' a '9')");
                    printf("\nIntroduza um novo numero de id:\n");

                }
            }

            for(x= 0; x<=25;x++)
            {
                printf("Introduza o Id n:");
                printf("\nIntervencoes solicitadas n:%s",x);
                printf("\nnumero de identificacao do computador:%s",nova_intre[x].n_id_computador);
                printf("\nData:%d,%d,%d",nova_intre[x].data_intrevencao.ano,nova_intre[x].data_intrevencao.mes,nova_intre[x].data_intrevencao.dia);
                printf("\nBreve descricao do problema:%s",nova_intre[x].designacao_problema);
            break;
            }
*/
    }


void informacaoes(t_pc novo_pc [],t_solicitacao nova_intre[],t_intrevencao reg_intre[],cont numero)
{
    int opcao,x;
    printf("\n1 -> Quantidade de computadores em cada estado\n2 -> Custo medio por cada intervenção efetuada nos computadores\n3 -> Intervencao/oes com o menor custo\n");
    printf("4 -> Percentagem de intervenções efetuadas em menos de 10 dias\n5 -> Quantidade de computadores que ja avariaram\n\nSelecione uma opcao:\n");
    fflush(stdin);
    scanf("%d",&opcao);

    switch (opcao)
    {
        case 1 :
            printf("computadores operacionais -> %d\ncomputadores a espera de intrevencao -> %d\ncomputadores avariados -> %d"
                   ,numero.n_operacional,numero.n_por_intrevencao,numero.n_avariados);
        return;
        break;

        case 2 :
            printf("\nO custo medio de %d intrevencoes foi de :%f",numero.n_regis_intre,numero.custo_medio_intrevencoes/numero.n_regis_intre);
        break;

        case 3 :

        printf("\nO custo mais baixo de %d intrevencoes foi de : %f", numero.n_regis_intre, numero.menor_valor);
        break;

        case 4 :
        break;

        case 5 :

        printf("\nA quantidade de computadores avariados e de : %d",numero.n_avariados);
        break;

    }
}


void guardar(t_pc novo_pc[], t_solicitacao nova_intre[], t_intrevencao reg_intre[], cont numero)
{
    char ficheiro[100];
    printf("Insira o nome do ficheiro que guardar: ");
    fflush(stdin);
    gets(ficheiro);
    FILE *fptr_bin;
    fptr_bin=fopen(ficheiro, "wb");
    fwrite(novo_pc, sizeof(t_pc), 25, fptr_bin);
    fwrite(nova_intre, sizeof(t_solicitacao), 100, fptr_bin);
    fwrite(reg_intre, sizeof(t_intrevencao), 100, fptr_bin);
    fwrite(&numero, sizeof(cont), 1, fptr_bin);
    fclose(fptr_bin);
}
