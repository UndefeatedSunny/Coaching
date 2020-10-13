#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    int num1;

    fp = fopen("sunny.txt","w");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }

    scanf("%d",&num1);                 

    putw(num1,fp);                           // Write only Integer Value value
    fclose(fp);

    fp = fopen("sunny.txt","r");

    int num2;
    num2 = getw(fp);                         // Read only Integer Value value

    printf("%d",num2);

    fclose(fp);
    return 0;
}
