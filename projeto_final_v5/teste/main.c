#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x,y,z,f_ano;
    char f_cano[5];
    f_ano=0;
    i=0;
    x=0;
    y=0;
    z=0;
    scanf("%s",&f_cano);
    printf("%s\n",f_cano);
    printf("%c\n",f_cano[0]);
    printf("%c\n",f_cano[1]);
    printf("%c\n",f_cano[2]);
    printf("%c\n",f_cano[3]);
    printf("%c\n",f_cano[4]);

    i=0;
    while (f_cano[i]!='\0')
    {
        i++;
        printf("%d\n",i);
    }
        printf("%d\n",f_ano);
        printf("%d,numero=i\n",i);
z=i-1;
        printf("%d,numero=z\n",z);
                          for (x=i;x>=0;x--)
                            {
                                switch (f_cano[x])
                                {
                                    case '1' :
                                    f_ano=f_ano+1*(10*z);
                                    printf("1\n");
                                    break;
                                    case '2' :
                                    f_ano=f_ano+2*(10*z);
                                    printf("2\n");
                                    break;
                                    case '3' :
                                    f_ano=f_ano+3*(10*z);
                                    printf("3\n");
                                    break;
                                    case '4' :
                                    f_ano=f_ano+4*(10*z);
                                    printf("4\n");
                                    break;
                                    case '5' :
                                    f_ano=f_ano+5*(10*z);
                                    printf("5\n");
                                    break;
                                    case '6' :
                                    f_ano=f_ano+6*(10*z);
                                    printf("6\n");
                                    break;
                                    case '7' :
                                    f_ano=f_ano+7*(10*z);
                                    printf("7\n");
                                    break;
                                    case '8' :
                                    f_ano=f_ano+8*(10*z);
                                    printf("8\n");
                                    break;
                                    case '9' :
                                    f_ano=f_ano+9*(10*z);
                                    printf("9\n");
                                    break;
                                    case '0' :
                                    f_ano=f_ano+0*(10*z);
                                    printf("0\n");
                                    break;
                                    return 0;
                                    }
                             z--;

                            };

        printf("\n%d\n",f_ano);
}
