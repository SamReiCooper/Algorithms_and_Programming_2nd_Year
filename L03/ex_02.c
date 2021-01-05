#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct rect
{
    char name[5];
    float x1, y1, x2, y2;
};

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
    struct rect r[100];
    char name[5];
    int i,j,k;
    float x,y;
    if(argc != 2)
        return 1;
    if(!(f = fopen(argv[1], "r")))
        return 2;
    f = fopen(argv[1], "r");
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
    for(i=0;i<j;i++)
        printf("%s a:%.2f p:%.2f\n", r[i].name, Area(r[i].x1, r[i].y1, r[i].x2, r[i].y2), Per(r[i].x1, r[i].y1, r[i].x2, r[i].y2));
    fclose(f);
    return 0;
}