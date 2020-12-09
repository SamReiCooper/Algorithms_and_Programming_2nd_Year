#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 20

int main()
{
    float m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM], sum;
    int r1,c1,r2,c2,i,j,r_1,c_2;
    printf("r1: "); scanf("%d",&r1);
    printf("c1: "); scanf("%d",&c1);
    printf("r2: "); scanf("%d",&r2);
    printf("c2: "); scanf("%d",&c2);
    if(r1 > MAX_DIM || c1 > MAX_DIM || r2 > MAX_DIM || c2 > MAX_DIM || c1!=r2)
        return 1;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("m1[%d][%d]: ", i,j); scanf("%f", &m1[i][j]);
        }
    }
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("m2[%d][%d]: ", i,j); scanf("%f", &m2[i][j]);
        }
    }
    
    c_2 = 0;
    for(r_1=0;r_1<r1;r_1++)
    {
        sum = 0;
        for(j=0;j<r2;j++)
        {
           sum = sum + m1[r_1][j]*m2[j][c_2];
        }
        m3[r_1][c_2] = sum;
        c_2++;
        if(c_2<c2)
           r_1--;
        else
            c_2=0;
     }
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
            printf("%.2f ",m3[i][j]);
        printf("\n");
    }
    scanf("%d",&i);
    return 0;
}