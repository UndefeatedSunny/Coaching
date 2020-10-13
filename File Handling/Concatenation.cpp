#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("sunny.txt","r");    // Reading
    fp2 = fopen("sunny1.txt","a");   // Writing

    if(fp1==NULL || fp2==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch,fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
