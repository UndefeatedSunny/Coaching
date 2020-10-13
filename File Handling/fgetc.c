#include<stdio.h>
#include<stdlib.h>

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

    while((ch = fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
}

//Read Character Using fgetc() i.e      USE -> all the data from file input can be PUT on console character by character.
