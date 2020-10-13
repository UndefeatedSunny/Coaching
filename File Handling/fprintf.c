#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int n1= 100;
    char c[10]= "Sunny";
    float n2= 11.121;

    // fp = fopen("sunny.txt","w");      // Write Mode 1
    // fp = fopen("sunny.txt","w");      // Append Mode 2

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }
    fprintf(fp,"%d\n",n1);
    fprintf(fp,"%.3f\n",n2);
    fprintf(fp,"%s",c);
    printf("Task Done Successfully");
    fclose(fp);
}



/*
OUTPUT
          100                       Write Mode
          11.121
          Sunny
          
                        100        Append Mode
                        11.121
                        Sunny
                        100
                        11.121
                        Sunny

*/
