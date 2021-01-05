#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findWordCount(char *, char *, int *);

typedef struct {
    char *word;
    int occurrences;
} index_t;

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int i,j,num;
    char str[101];
    index_t *find;
    if(argc != 3)
        return 1;
    if(!(f1 = fopen(argv[1], "r")) || !(f2 = fopen(argv[2], "r")))
        return 2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");

    fgets(str, 100, f2);
    num = atoi(str);
    find = (index_t *)malloc(sizeof(index_t) * num);
    if(find == NULL)
        return 3;
    for(j=0; j<num; j++)
    {
        find[j].word = (char*)malloc(sizeof(char)*21);
        if(find[j].word == NULL)
            return 4;
    }
    for(j=0; j<num; j++)
    {
        fgets(find[j].word, 20, f2);
        if(isalpha(find[j].word[strlen(find[j].word) -1]) == 0)
            find[j].word[strlen(find[j].word)-1] = '\0';
    }
    for(j=0; j<num; j++)
        find[j].occurrences = 0;
    while(fgets(str, 100, f1))
        for(j=0;j<num;j++)
            findWordCount(str, find[j].word, &(find[j].occurrences));
    for(j=0;j<num;j++)
    {
        printf("%s - ", find[j].word);
        printf("%d occurence(s)\n", find[j].occurrences);
    }
    for(j=0;j<num;j++)
        free(find[j].word);
    free(find);
    fclose(f1);
    fclose(f2);
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
        
        if((isalpha(str[i+1]) == 0 || strlen(str) == i+1) && j == strlen(key))
            (*count)++;
    }
}