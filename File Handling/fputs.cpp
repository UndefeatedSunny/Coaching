#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    char str[100];

    fp = fopen("sunny.txt","w");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    gets(str);

    fputs(str,fp);

    fclose(fp);
    return 0;
}


// Whole 1 line can be taken input and store in file.
