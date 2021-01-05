#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[5];
    float x1, y1, x2, y2;
} rect;

float ab(float x)
{
    if(x>=0)
        return x;
    else
        return -x;
}

float Area(float x1, float y1, float x2, float y2)
{
    return ab((x1-x2)*(y1-y2));
}

float Per(float x1, float y1, float x2, float y2)
{
    return 2*(ab(x1-x2) + ab(y1-y2));
}

int main(int argc, char *argv[])
{
    FILE *f;
    rect *r;
    char name[5], n[3];
    int i,j,k,num;
    float x,y;
    if(argc != 2)
        return 1;
    if(!(f = fopen(argv[1], "r")))
        return 2;
    f = fopen(argv[1], "r");
    fgets(n, 10, f);
    num = atoi(n);
    r = (rect *)malloc(sizeof(rect) * num);
    if(r == NULL)
        return 3;
    for(j=0; !feof(f);j++)
    {
        fscanf(f,"%s %f %f", name, &x, &y);
        if(j==0)
        {
            strcpy(r[j].name,name);
            r[j].x1 = x;
            r[j].y1 = y;
        }
        else
        {
            for(i=0;i<j;i++)
            {
                if(strcmp(name, r[i].name) == 0)
                {
                    r[i].x2 = x;
                    r[i].y2 = y;
                    j--;
                    i=j;
                }
                else
                {
                    if(i==j-1)
                    {
                        strcpy(r[j].name, name);
                        r[j].x1 = x;
                        r[j].y1 = y;
                    }
                }
            }
        }
    }
    for(j=0;j<num;j++)
        printf("%s a:%.2f p:%.2f\n", r[j].name, Area(r[j].x1, r[j].y1, r[j].x2, r[j].y2), Per(r[j].x1, r[j].y1, r[j].x2, r[j].y2));
    free(r);
    return 0;
}