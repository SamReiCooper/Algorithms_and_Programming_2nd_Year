#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int main()
{
    int i, j, k, N1, N2, v1[DIM], n;
    float v2[DIM];
    printf("N1: "); scanf("%d", &N1);
    printf("N2: "); scanf("%d", &N2);
    if(N1>=DIM || N2>=DIM)
        return 1;
    for(i=0;i<N1;i++)
    {
        printf("v1[%d]: ",i); scanf("%d", &v1[i]);
    }  
    printf("\n\n");
    k=0; 
    for(i=0;i<N1;i++)
    {
        v2[k] = 0;
        n = 0;
        for(j=i-N2;j<=i+N2;j++)
        {
            if(0<=j && j<N1)
            {
                v2[k] = v2[k] + v1[j];
                n++;
            }
        }
        v2[k] = v2[k]/n;
        k++;
    }
    for(i=0; i<k; i++)
        printf("%.2f ",v2[i]);
    scanf("%d", &i);
    return 0;
}