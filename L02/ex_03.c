#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void returnWBPmiOne(char *str, char *key, char *out)
{
    int i,j;
    for(i=0, j=0;i<strlen(str);i++)
    {
        if(*(str+i) == *(key+j))
            j++;
        else
            j=0;
        if(j == strlen(key))
            strncpy(out, str, i-j+1);
    }
}

void returnWEPplOne(char *str, char *key, char *out)
{
    int i,j;
    for(i=0, j=0;i<strlen(str);i++)
    {
        if(*(str+i) == *(key+j))
            j++;
        else
            j=0;
        if(j == strlen(key))
            strcpy(out, str+i+1);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1,*f2;
    char str[101], str1[21], str2[21], tmp[101], out[101];
    if(argc != 5)
        return 1;
    if(!(f1 = fopen(argv[2], "r")))
        return 2;
    f1 = fopen(argv[2], "r");
    f2 = fopen(argv[4], "w");
    strcpy(str1, argv[1]);
    strcpy(str2, argv[3]);
    while(fgets(str, 100, f1))
    {
        returnWBPmiOne(str, str1, out);
        if(strlen(out) != 0)
        {
            strcpy(tmp, out);
            memset(out, '\0', 100);
            strcat(tmp, str2);
            returnWEPplOne(str, str1, out);
            strcat(tmp, out);
            memset(out, '\0', 100);
            fprintf(f2, "%s", tmp);
            memset(tmp, '\0', 100);
        }
        else
            fprintf(f2, "%s", str);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
