#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct athletes_s ath;

struct athletes_s
{
    char *name;
    int id;
    int laps;
    float *times;
    float avt;
};



int main(int argc, char *argv[])
{
    char filename[20], str[30+1], com[31];
    int num, i, j, k, idb;
    float sum, max;
    FILE *f;
    printf("Input file name: "); scanf("%s", filename);
    if(!fopen(filename, "r"))
        return 1;
    f = fopen(filename, "r");
    fgets(str, 30, f);
    num = atoi(str);
    printf("num: %d\n", num);
    ath *a;
    a = (ath *)malloc(sizeof(ath) * num);
    for(i=0;!feof(f);i++)
    {
        fscanf(f, "%s", str);
        (a+i)->name = (char *)malloc(sizeof(char) * (strlen(str)+1));
        strcpy((a+i)->name, str);
        (a+i)->name[strlen((a+i)->name)] = '\0';
        fscanf(f, "%d", &(a+i)->id);
        fscanf(f, "%d", &(a+i)->laps);
        (a+i)->times = (float *)malloc(sizeof(int) * (a+i)->laps);
        sum = 0;
        for(j=0;j<(a+i)->laps;j++)
        {
            fscanf(f, "%f", &(a+i)->times[j]);
            sum = sum + (a+i)->times[j];
        }
        (a+i)->avt = sum/((a+i)->laps);
    }
    i = 1;
    while (i==1)
    {
        printf("Command?: ");
        scanf("%s", com);
        if(strcmp(com, "list") == 0)
        {  
            printf("Number of athletes : %d\n", num);
            for(j=0;j<num;j++)
                printf("Name: %s #Id:%d #Laps:%d\n", (a+j)->name, (a+j)->id, (a+j)->laps);

        }
        if(strcmp(com, "best") == 0)
        {
            max = 0;
            for(j=0;j<num;j++)
                if((a+j)->avt>max)
                    max = (a+j)->avt;
            for(j=0;j<num;j++)
                if((a+j)->avt == max)
                    idb = j;
            printf("Name: %s #Id number:%d Laps:%d Times:", (a+idb)->name, (a+idb)->id, (a+idb)->laps);
            for(k=0;k<(a+idb)->laps;k++)
                printf("%f ", (a+idb)->times[k]);
            printf("(Average:%f)\n", (a+idb)->avt);
           
        }
        if(strcmp(com, "details") == 0)
        {
            printf("Name: ");
            scanf("%s", str);
            for(j=0;j<num;j++)
                if(strcmp((a+j)->name, str) == 0)
                    idb = j;
            printf("#Id:%d #Laps:%d Times: ", (a+idb)->id, (a+idb)->laps);
            for(k=0;k<(a+idb)->laps;k++)
                printf("%f ", (a+idb)->times[k]);
            printf("\n");
        }
        if(strcmp(com, "stop") == 0)
            i = 0;
    }
    for(i=0;i<num;i++)
    {
        free((a+i)->times);
        free((a+i)->name);
        free(a+i);
    }
    fclose(f);
    return 0;
}