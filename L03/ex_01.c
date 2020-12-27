#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findWordCount(char *, char *, int *);

struct word
{
    char w[21];
    int n;
};

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int i,j;
    char str[101];
    struct word find[100];
    if(argc != 3)
        return 1;
    if(!(f1 = fopen(argv[1], "r")) || !(f2 = fopen(argv[2], "r")))
        return 2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    for(i=0; fgets(find[i].w, 20, f2); i++);
    for(j=0; j<i; j++)
        find[j].n = 0;
    while(fgets(str, 100, f1))
        for(j=0;j<i;j++)
            findWordCount(str, find[j].w, &(find[j].n));
    for(j=0;j<i;j++)
    {
        printf("%s - ", find[j].w);
        printf("%d occurence(s)\n", find[j].n);
    }
    return 0;
}

void findWordCount(char *str, char *key, int *count)
{
    int i,j;
    for(i=0, j=0;i<strlen(str); i++)
    {
        if(tolower(str[i]) == tolower(key[j]))
            j++;
        else
            j=0;
        
        if((isalpha(str[i+1]) == 0 || strlen(str) == i+1) && j == strlen(key)-1)
            (*count)++;
        
        if((isalpha(str[i+1]) == 0 || strlen(str) == i+1) && j == strlen(key))
            (*count)++;
    }
}