#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    char str[100];

    fp = fopen("sunny.txt","r");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    fgets(str,8,fp);    // 3 arguements fgets(i/p received, no. of characters, file pointer);
    printf("%s",str);

    fclose(fp);
    return 0;
}
