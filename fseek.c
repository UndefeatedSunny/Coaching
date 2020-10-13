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

    fseek(fp,6,SEEK_SET);

    while((ch = fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
}

/*
fseek(file_pointer, offset, origin)
        MODES

        SEEK_SET   -->> Beginning of the file.
        SEEK_CUR   -->> current position of the file.
        SEEK_END   -->> end of the file.


I/P                 O/P
APPLESUNNY    -->> UNNY

*/
