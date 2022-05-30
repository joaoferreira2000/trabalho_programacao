#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
z=i;
        printf("%d,numero=z\n",z);


                        for (x=i;x>=0;x--)
                        {
                            if (z=3)
                            {
                                y=1000;
                            }
                            else if (z=2)
                            {
                                y=100;
                            }
                            else if (z=1)
                            {
                                y=10;
                            }

                            else if (z=0)
                            {
                                y=0;
                            }

                            printf("Y=========%d\n",y);
                                switch (f_cano[x])
                                {


                                    case '1' :
                                    f_ano=(f_ano+1*y);
                                    printf("1\n");
                                    break;
                                    case '2' :
                                    f_ano=f_ano+2*y;
                                    printf("2\n");
                                    break;
                                    case '3' :
                                    f_ano=f_ano+3*y;
                                    printf("3\n");
                                    break;
                                    case '4' :
                                    f_ano=f_ano+4*y;
                                    printf("4\n");
                                    break;
                                    case '5' :
                                    f_ano=f_ano+5*y;
                                    printf("5\n");
                                    break;
                                    case '6' :
                                    f_ano=f_ano+6*y;
                                    printf("6\n");
                                    break;
                                    case '7' :
                                    f_ano=f_ano+7*y;
                                    printf("7\n");
                                    break;
                                    case '8' :
                                    f_ano=f_ano+8*y;
                                    printf("8\n");
                                    break;
                                    case '9' :
                                    f_ano=f_ano+9*y;
                                    printf("9\n");
                                    break;
                                    case '0' :
                                    f_ano=f_ano+0*y;
                                    printf("0\n");
                                    break;
                                    return 0;
                                    }
                            z--;

                        };

        printf("\n%d\n",f_ano);
}
