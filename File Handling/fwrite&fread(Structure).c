#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rno;
    char name[10];
};
int main()
{
    FILE *fp;

    struct student s[2];

    fp = fopen("sunny.txt","wb");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File");
        exit(1);
    }
    for(int i=0;i<2;i++)                  // Take 2 Entries only.
    {
        scanf("%d",&s[i].rno);
        fflush(stdin);
        scanf("%s",s[i].name);
        fflush(stdin);
    }

    fwrite(&s,sizeof(struct student),10,fp);       // Write array in the file (Not in readable format).
    fclose(fp);

    fp = fopen("sunny.txt","rb");
    fread(&s,sizeof(struct student),10,fp);         // Read array from the file (Readable format).

    for(int i=0;i<2;i++)
    {
        printf("%d ",s[i].rno);
        printf("%s\n",s[i].name);
    }

    fclose(fp);
    return 0;
}
