#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j, k, hc, vc;
    char str[101], tmp[6][101];
    FILE *f;
    if(argc != 2)
        return 1;
    if(!(f = fopen(argv[1], "r")))
        return 2;
    f = fopen(argv[1], "r");
    hc = 0;
    vc = 0;
    k = 0;
    while(fgets(str, 100, f)!=NULL)
    {
        j = 0;
        for(i=0;i < strlen(str);i++)
        {
            if(str[i] == 'h')
                j++;
            else
            {
                if(j==5)
                    hc++;
                j=0;
            }
        }
        if(k>=6)
        {
            for(i=0;i<strlen(tmp[k%6]);i++)
                tmp[k%6][i] = '\0';
            strcpy(tmp[k%6], str);
        }
        else
        {
            for(i=0;i<strlen(tmp[k]);i++)
                tmp[k][i] = '\0';
            strcpy(tmp[k], str);
        }
        
        for(i=0; i<strlen(tmp[k]); i++)
            if( ((k==5) && tmp[0][i] == 'v' && tmp[1][i] == 'v' && tmp[2][i] == 'v' && tmp[3][i] == 'v' && tmp[4][i] == 'v') || 
                ((k==5) && tmp[1][i] == 'v' && tmp[2][i] == 'v' && tmp[3][i] == 'v' && tmp[4][i] == 'v' && tmp[5][i] == 'v') ||
                ((k>=6) && tmp[2][i] == 'v' && tmp[3][i] == 'v' && tmp[4][i] == 'v' && tmp[5][i] == 'v' && tmp[0][i] == 'v') ||
                ((k>=6) && tmp[3][i] == 'v' && tmp[4][i] == 'v' && tmp[5][i] == 'v' && tmp[0][i] == 'v' && tmp[1][i] == 'v') ||
                ((k>=6) && tmp[4][i] == 'v' && tmp[5][i] == 'v' && tmp[0][i] == 'v' && tmp[1][i] == 'v' && tmp[2][i] == 'v') ||
                ((k>=6) && tmp[5][i] == 'v' && tmp[0][i] == 'v' && tmp[1][i] == 'v' && tmp[2][i] == 'v' && tmp[3][i] == 'v'))
                    {
                        printf("k=%d\n", k);
                    vc++;
                    }
        k++;
    }
    printf("hc: %d\n", hc);
    printf("vc: %d\n", vc);
    fclose(f);
    return 0;
}