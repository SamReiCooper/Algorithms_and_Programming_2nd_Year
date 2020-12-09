#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 5

int fact(int n)
{
    int res,i;
    res = 1;
    for(i=1;i<=n;i++)
        res = res * i;
    return res;
}

int pow_10(float n)
{
    int i;
    for(i=1;n/i>1;i=i*10);
    return i;
}

int main()
{
    int i,j,m1[R][C],m2[R][C];
    printf("Input matrix: \n");
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            printf("m1[%d][%d]: ", i,j); scanf("%d", &m1[i][j]);
        }
    }
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(m1[i][j]<0)
                m2[i][j] = fact(-m1[i][j]);
            if(m1[i][j]>0)
                m2[i][j] = pow_10((float)m1[i][j]);
            if(m1[i][j]==0)
                m2[i][j] = 0;
        }
    }
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
            printf("%d ",m2[i][j]);
        printf("\n");
    }
    scanf("%d",&i);
    return 0;
}