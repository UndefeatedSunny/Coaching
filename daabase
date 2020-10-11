#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
    char name[30];
    int age;
    int roll_number;
} student;

void display();

int main(void) {
    int opt;
    FILE *fp;
    student st;

    while (1) {
        system("cls");
        printf("\nMenu: SIS");
        printf("\nEnter Student Record : 1");
        printf("\nDisplay: 2");
        printf("\nExit: 3");
        printf("\n\nEnter your option:");
        scanf("%d", &opt);

        switch(opt) {
        case 1:
                fp = fopen("sis.db", "ab");
                printf("\nEnter name:");
                scanf("%s", st.name);
                printf("\nEnter Age: ");
                scanf("%d", &st.age);
                printf("\nEnter roll num: ");
                scanf("%d", &st.roll_number);
                fwrite(&st, sizeof(student), 1,fp);
                fclose(fp);
             
                break;
        case 2:
                display();
                break;
        case 3:
                printf("\nExiting");
                exit(0);
        default:
                printf("\nInvalid option");
                continue;
        }
    }
}

void display() {
    student s;
    FILE *fp;
    system("cls");
    fp = fopen("sis.db", "rb");
    while(fread(&s, sizeof(s), 1, fp) != 0)
        printf("\n%-10d %-30s %-10d", s.roll_number, s.name, s.age);
    getch();
    
}
