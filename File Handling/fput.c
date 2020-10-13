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

    scanf("%s",str);
    int i;

    for(i=0;str[i]!='\0';i++)
    {
        fputc(str[i],fp);
    }

    fclose(fp);
    return 0;
}


//Store Character Using fgetc() i.e      USE -> A single string file console can fetch character by character and put in the given allocated file.
