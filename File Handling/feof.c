#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    char ch;

    fp = fopen("sunny.txt","r");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    while(!(feof(fp)))
    {
        ch=fgetc(fp);
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}


// feof  -->>  return non-zero if fp is on EOF Otherwise return null value.
