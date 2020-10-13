#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    int array[10];

    fp = fopen("sunny.txt","wb");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }

    fwrite(array,sizeof(int),10,fp);       // Write array in the file (Not in readable format).
    fclose(fp);

    fp = fopen("sunny.txt","rb");
    fread(array,sizeof(int),10,fp);         // Read array from the file (Readable format).

    for(int i=0;i<10;i++)
    {
        printf("%d\n",array[i]);
    }

    fclose(fp);
    return 0;
}
