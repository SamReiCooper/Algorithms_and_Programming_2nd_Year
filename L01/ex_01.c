#include <stdio.h>
#include <stdlib.h>

#define DIM 15

int main()
{
    int i, max_g, max_l, id_l_g, id_l_l, a[DIM];
    printf("Input the array:\n");
    for(i=0;i<DIM;i++)
    {
        printf("El[%d]: ",i); scanf("%d",&a[i]);
    }
    max_g = max_l = 0;
    for(i=0;i<DIM-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            max_l++;
            id_l_l = i+1;
        }
        else
        {
            if(max_g <= max_l)
            {
                max_g = max_l;
                id_l_g = id_l_l;
                max_l = 0;
            }
        }
    }
    for(i=id_l_g-max_g; i<=id_l_g; i++)
        printf("%d ", a[i]);
    printf("\n");
    scanf("%d",&i);
    return 0;
}