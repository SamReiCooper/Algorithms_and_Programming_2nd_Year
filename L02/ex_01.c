#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 20

void readDim(int *, int *);
int checkDim(int, int, int, int);
void readMatrix(float [][MAX_DIM], int, int);
void computeProduct(float [][MAX_DIM], int, int, float [][MAX_DIM], int, int, float [][MAX_DIM], int *, int *);
void writeMatrix(float [][MAX_DIM], int, int, float [][MAX_DIM], int, int, float [][MAX_DIM], int, int);
int main()
{
    float m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM], m3[MAX_DIM][MAX_DIM], sum;
    int r1,c1,r2,c2,r3,c3,i,j,r_1,c_2;
    printf("m1: r, c:\n");
    readDim(&r1, &c1);
    printf("m2: r, c:\n");
    readDim(&r2, &c2);
    if(checkDim(r1,c1,r2,c2) == 1)
        return 1;
    printf("Input matrix m1\n");
    readMatrix(m1, r1, c1);
    printf("Input matrix m2\n");
    readMatrix(m2, r2, c2);
    computeProduct(m1, r1, c1, m2, r2, c2, m3, &r3, &c3);
    writeMatrix(m1 ,r1, c1, m2, r2, c2, m3, r3, c3);
    scanf("%d",&i);
    return 0;
}

void readDim(int *r, int *c)
{
    scanf("%d", r);
    scanf("%d", c);
}

int checkDim(int r1, int c1, int r2, int c2)
{
    if(r1 > MAX_DIM || c1 > MAX_DIM || r2 > MAX_DIM || c2 > MAX_DIM || c1!=r2)
        return 1;
    return 0;
}

void readMatrix(float m[][MAX_DIM], int r, int c)
{
    int i, j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("[%d][%d]: ", i,j); scanf("%f", &m[i][j]);
        }
    }
}

void computeProduct(float m1[][MAX_DIM], int r1, int c1, float m2[][MAX_DIM], int r2, int c2, float m3[][MAX_DIM], int *r3, int *c3)
{
    int r_1, c_2, i, j;
    float sum;
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
    *r3 = r1;
    *c3 = c2;
}

void writeMatrix(float m1[][MAX_DIM], int r1, int c1, float m2[][MAX_DIM], int r2, int c2, float m3[][MAX_DIM], int r3, int c3)
{
    int i,j;
    printf("Matrix m1:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            printf("%.2f ",m1[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Matrix m2:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            printf("%.2f ",m2[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Matrix m3:\n");
    for(i=0;i<r3;i++)
    {
        for(j=0;j<c3;j++)
            printf("%.2f ",m3[i][j]);
        printf("\n");
    }
    printf("\n");
}