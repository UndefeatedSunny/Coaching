#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    int n1;
    float n2;
    char c[10];

    fp = fopen("sunny.txt","r");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }
    fscanf(fp,"%d",&n1);
    fscanf(fp,"%f",&n2);
    fscanf(fp,"%s",c);
    printf("%d\n%f\n%s",n1,n2,c);
    printf("\nTask Done Successfully");
    fclose(fp);
    return 0;
}

/*
file
            100 100.111 sunny

output 
            100
            100.111000
            sunny
*/
// Note :- Automatically specify the type else take 0 in place of that.
