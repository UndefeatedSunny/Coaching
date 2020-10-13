#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;

    char ch;
    int pos;

    fp = fopen("sunny.txt","r");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    pos=ftell(fp);
    printf("Current position is %d\n",pos);

    fseek(fp,6,SEEK_SET);

    pos=ftell(fp);
    printf("Current position is %d\n",pos);

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

*/



/*

fseek(file_pointer, offset, origin)

        MODES
        
        SEEK_SET   -->> Beginning of the file.
        SEEK_CUR   -->> current position of the file.
        SEEK_END   -->> end of the file.
        
        
I/P   -->> APPLESUNNY 

O/P   -->>

Current position is 0
Current position is 6
UNNY

*/
