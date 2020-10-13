
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    char str[100];
    char ch;

    // fp = fopen("sunny.txt","a+");  // Both read and write    -> old value vanish
    
    // fp = fopen("sunny.txt","a+");  // Both read and write    -> old value remains same

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    gets(str);
    fputs(str,fp);
    rewind(fp);                                 // rewind -->> Makes the pointer back to initial position or Beginning i.e 0

    while((ch=getc(fp))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
}
