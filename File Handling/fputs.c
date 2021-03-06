#include <stdio.h>   // Adding Libraries
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ll long long int


struct customer_info
{
    char room_no[20];
    char name[30];
    char address[50];
    char phone_no[15];
    char nationality[10];
    char email[20];
    char period[10];
    char arrival_date[15];
    char members_names[100];
};


int password()
{
    char u_pass[15]={0};        // User Password
    char o_pass[15]={0};        // Original Password
    char ch;
    ll i=0,j=0;

    printf("\t\tPLEASE! ENTER THE PASSWORD\n\n");
    printf("\t\tONLY 3 CHANCES WILL BE GIVEN\n");

    for(i=0;i<3;i++)
    {
        j=0;
        printf("\n\n\nEnter the Password-> ");
        u_pass[0]=getch();

        while(u_pass[j]!='\r')
        {
            if(u_pass[j]=='\b')
            {
                --j;
                printf("\b");
                printf(" ");
                printf("\b");
                u_pass[j]=getch();
            }
            else
            {
                printf("*");
                ++j;
                u_pass[j]=getch();
            }
        }
        u_pass[j]='\0';
        FILE *fp;
        fp=fopen("password","r");
        if(fp==NULL)
        {
            printf("[FILE MISSING]");
            getch();
            return -1;
        }
        else
        {
            j=0;
            while(1)
            {
                ch=fgetc(fp);
                if(ch==EOF)
                {
                    o_pass[j]='\0';
                    break;
                }
                o_pass[j]=ch-5;
                ++j;
            }
        }
        if(strcmp(o_pass,u_pass)==0)
        {
            printf("\n\t\t\tACCESS GRANTED \n");
            return 1;
        }
        else
        {
            printf("\n\t\t\tWRONG PASSWORD \n");
        }
        fclose(fp);
    }
    printf("YOU ARE NOT ALLOWED TO ENTER");
    getch();
    return -1;
}


void edit_password()
{
    system("cls");

    char pass1[15]={0};
    char pass2[15]={0};
    char ch;
    ll i=0,j=0,match,choice;

    printf("\n\n");
    FILE *fp;
    fp=fopen("password","rb");
    if(fp==NULL)
    {
        fp=fopen("password","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ISSUE -_-");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);

    match=password();

    if(match==-1)
    {
        return;
    }
    do
    {
        if(match==1)
        {
            printf("\nEnter the NEW password -> ");
            fflush(stdin);
            pass1[0]=getch();
            while(pass1[j]!='\r')
            {
                if(pass1[j]=='\b')
                {
                    --j;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass1[j]=getch();
                }
                else
                {
                    printf("*");
                    ++j;
                    pass1[j]=getch();
                }
            }
            pass1[j]='\0';
            i=0;
            printf("\nConfirm Password -> ");
            pass2[0]=getch();
            while(pass2[i]!='\r')
            {
                if(pass2[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass2[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    pass2[i]=getch();
                }
            }
            pass2[i]='\0';
            if(strcmp(pass1,pass2)==0)
            {
                fp=fopen("password","wb");
                 if(fp==NULL)
                 {
                    printf("SYSTEM ERROR -_-");
                    getch();
                    return;
                 }
                i=0;
                while(pass1[i]!='\0')
                {
                    ch=pass1[i];
                    fputc(ch+5,fp);
                    i++;
                }
                fputc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\nWRONG PASSWORD");
                choice=1;
            }
        }
    }while(choice==1);
    printf("\n\n\t\tPassword Changed (-_-)");
    getch();
}


void edit()
{
    system("cls");
    printf("\n\n\t\t\t***********************\n");
    printf("\t\t\t* WELCOME TO EDIT MENU*");
    printf("\n\t\t\t***********************\n\n");

    struct customer_info guest;

    FILE *fp;
    FILE *fptemp;

    fp=fopen("book.txt","r");
    fptemp=fopen("Temp.txt","w");

    if(fp==NULL)
    {
        return;
    }
    if(fptemp==NULL)
    {
        return;
    }
    char room_no[10];
    int check=0;

	printf("Enter Room number of the customer to edit:\n\n");
    fflush(stdin);
	gets(room_no);

    while(fread(&guest,sizeof(guest),1,fp)==1)
    {
        if(strcmp(room_no,guest.room_no)==0)
        {
            check=1;
            strcpy(guest.room_no,room_no);
            printf("\n\t\tEnter the Name: ");
            fflush(stdin);
            gets(guest.name);
            printf("\n\t\tEnter the Address: ");
            fflush(stdin);
            gets(guest.address);
            printf("\n\t\tEnter the Phone No. : ");
            fflush(stdin);
            gets(guest.phone_no);
            printf("\n\t\tEnter the Nationality: ");
            fflush(stdin);
            gets(guest.nationality);
            printf("\n\t\tEnter the Email: ");
            fflush(stdin);
            gets(guest.email);
            printf("\n\t\tEnter the Time Period to Stay : ");
            fflush(stdin);
            gets(guest.period);
            printf("\n\t\tEnter the Arrival Time : ");
            fflush(stdin);
            gets(guest.arrival_date);
            printf("\n\t\tEnter all the Members Details (If Any)");
            fflush(stdin);
            gets(guest.members_names);
            fwrite(&guest, sizeof(guest),1,fptemp);
            continue;
        }
        else
        {
            fwrite(&guest, sizeof(guest),1,fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
    if(check==0)
    {
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        getch();
    }
    else
    {
        remove("book.txt");
        rename("Temp.txt","book.txt");
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
        getch();
    }
}


void delete()
{
    printf("\n\n\t\t\t*************************\n");
    printf("\t\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t\t*************************\n\n");

    FILE *fp;
    FILE *fptemp;
    char room_no[10];
    int check=0;
    struct customer_info removee;

    fp = fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }
    fptemp = fopen("Temp.txt","w");
    if(fptemp==NULL)
    {
        return;
    }
    printf("Enter the Room Number of the hotel to be deleted from the database: \n");
    fflush(stdin);
    gets(room_no);
    fflush(stdin);

    while(fread(&removee,sizeof(removee),1,fp)==1)
    {
        if(strcmp(removee.room_no,room_no)==0)
        {
            check=1;
            continue;
        }
        else
        {
            fwrite(&removee,sizeof(removee),1,fptemp);
        }
    }
    if(check==0)
    {
        fclose(fp);
        fclose(fptemp);
        printf("\n\n Records of Customer in this  Room number is not found!!");
        getch();
        return;
    }
    fclose(fp);
    fclose(fptemp);
    remove("book.txt");
    rename("Temp.txt","book.txt");
    printf("\n\nThe Customer is successfully removed....");
    getch();
}


void book()
{
    system("cls");
    printf("\n\n\t\t\t****************************************\n");
    printf("\t\t\t* WELCOME TO ADD CUSTOMER DETAILS MENU *");
    printf("\n\t\t\t****************************************\n\n");

    struct customer_info guest;
    char enter='Y';
    int exist;

    FILE *fp;
    fp=fopen("book.txt","a+");
    if(fp==NULL)
    {
        fp=fopen("book.txt","w+");
        if(fp==NULL)
        {
            printf("[SYSTEM ERROR -_-]");
            printf("\nEnter any KEY to exit");
            getch();
            return;
        }
        fclose(fp);
    }
    while(enter=='y'||enter=='Y')
    {
        char room_no[10];
        printf("\n\t\tEnter the Room Number => ");
        fflush(stdin);
        gets(room_no);
        fflush(stdin);
        rewind(fp);
        exist=0;
        while(fread(&guest,sizeof(guest),1,fp)==1)
        {
            if(strcmp(room_no,guest.room_no)==0)
            {
                printf("\n\t\tAlready Exists\n");
                exist=1;
            }
        }

        if(exist==0)
        {
            system("cls");
            strcpy(guest.room_no,room_no);
            printf("\n\t\tEnter the Name: ");
            fflush(stdin);
            gets(guest.name);
            printf("\n\t\tEnter the Address: ");
            fflush(stdin);
            gets(guest.address);
            printf("\n\t\tEnter the Phone No. : ");
            fflush(stdin);
            gets(guest.phone_no);
            printf("\n\t\tEnter the Nationality: ");
            fflush(stdin);
            gets(guest.nationality);
            printf("\n\t\tEnter the Email: ");
            fflush(stdin);
            gets(guest.email);
            printf("\n\t\tEnter the Time Period to Stay : ");
            fflush(stdin);
            gets(guest.period);
            printf("\n\t\tEnter the Arrival Time : ");
            fflush(stdin);
            gets(guest.arrival_date);
            printf("\n\t\tEnter all the Members Details (If Any) : ");
            fflush(stdin);
            gets(guest.members_names);
            fwrite(&guest, sizeof(guest),1,fp);
            printf("\n\t\tYOUR RECORD IS ADDED...\n");
        }
        printf("\n\t\tADD another NOTE .... (Y/N) ");
        fflush(stdin);
        enter=getch();
    }
    fclose(fp);
    printf("\n\t\tEnter any KEY to Exit");
    getch();

}


void view()
{
    system("cls");
    if(password()==-1)
    {
        return;
    }
    system("cls");
    struct customer_info info;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t*******************************\n\n");

    FILE *fp;
    fp=fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }
    while(fread(&info,sizeof(info),1,fp)==1)
    {
        printf("Room Number => %s\n",info.room_no);
        printf("Name => %s\n",info.name);
        printf("Address => %s\n",info.address);
        printf("Phone Number => %s\n",info.phone_no);
        printf("Nationality => %s\n",info.nationality);
        printf("Email => %s\n",info.email);
        printf("Stay Time Period  => %s\n",info.period);
        printf("Arrival Date  => %s\n",info.arrival_date);
        printf("Members Details => %s\n",info.members_names);
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    fclose(fp);
    getch();
}


void admin()
{
    system("cls");
    if(password()==-1)
    {
        return;
    }
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf("                            #######    ####      ###     ###   ##    ###     ##          \n");
        printf("                            ##   ##    ##  ##    ## ## ## ##   ##    ## ##   ##          \n");
        printf("                            #######    ##   ##   ##  ##   ##   ##    ##  ##  ##          \n");
        printf("                            ##   ##    ##   ##   ##       ##   ##    ##   ## ##          \n");
        printf("                            ##   ##    #####     ##       ##   ##    ##     ###          \n");
        int option;

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t    { OPTIONS }");
        printf("\n\n\t\t\tBOOK A ROOM\t\t\t\t[1]");
        printf("\n\t\t\tVIEW CUSTOMER RECORD\t\t\t[2]");
        printf("\n\t\t\tDELETE CUSTOMER RECORD\t\t\t[3]");
        printf("\n\t\t\tEDIT CUSTOMER RECORD\t\t\t[4]");
        printf("\n\t\t\tEXIT\t\t\t\t\t[5]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                book();
                break;
            case 2:
                view();
                break;
            case 3:
                delete();
                break;
            case 4:
                edit();
                break;
            case 5:
                return;
        }
        system("cls");
    }
}


void price()
{
    int price=0;
    int days=0;
    int fixed_price=121;
    printf("\n\t\t\tEnter the No. of Days you want to Stay ");
    scanf("%d",&days);
    price=(fixed_price*days);
    printf("\n\t\t\tTOTAL AMOUNT FOR %d DAYS ==> %d",days,price);
    getch();
}


void record()
{
    system("cls");
    printf("\n\n\t\t\t*************************\n");
    printf("\t\t\t* WELCOME TO RECORD MENU*");
    printf("\n\t\t\t*************************\n\n");
    printf("\t\t\tOCCUPATION\tPHONE NO.\n\n");
    printf("\t\t\tGUARD\t\t9953691354\n\n");
    printf("\t\t\tGARDNER\t\t7083691354\n\n");
    printf("\t\t\tMANAGER\t\t7071231354\n\n");
    printf("\t\t\tMEDICAL\t\t8871231214\n\n");
    printf("\t\t\tSWEEPER\t\t9953691354\n\n");
    printf("\t\t\tPOLICE\t\t100\n\n");
    getch();
    return;
}


void availability()
{
    system("cls");
    printf("\n\n\t\t\t********************************\n");
    printf("\t\t\t* WELCOME TO AVAILABILITY MENU *");
    printf("\n\t\t\t********************************\n\n");

    FILE *fp;
    char room_no[10];
    int check=0;
    struct customer_info avail;

    fp = fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }

    printf("\t\t\tEnter the Room Number of the hotel to be SEARCHED from the database: ");
    fflush(stdin);
    gets(room_no);
    fflush(stdin);

    while(fread(&avail,sizeof(avail),1,fp)==1)
    {
        if(strcmp(room_no,avail.room_no)==0 && (strlen(room_no)==strlen(avail.room_no)))
        {
            check=1;
            break;
        }
    }
    fclose(fp);
    if(check==0)
    {
        printf("\n\n\t\t\t AVAILABLE");
        getch();
        return;
    }
    else
    {
        printf("\n\n\t\t\t NOT AVAILABLE [-_-]");
        getch();
        return;
    }
}


void user()
{
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t                       ##  ##    #######    #######   ######                   \n           ");
        printf("                            ##  ##    ##         ##        ##  ##                   \n           ");
        printf("                            ##  ##    #######    #######   ######                   \n           ");
        printf("                            ##  ##         ##    ##        ##   ##                  \n           ");
        printf("                            ######    #######    #######   ##    ###                \n           ");
        int option;

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t\t    { OPTIONS }");
        printf("\n\n\t\t\tSTAY PRICE\t\t\t\t[1]");
        printf("\n\t\t\tCHECK AVAILABILITY OF ROOMS\t\t[2]");
        printf("\n\t\t\tEMPLOYEES RECORDS\t\t\t[3]");
        printf("\n\t\t\tEXIT\t\t\t\t\t[4]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                price();
                break;
            case 2:
                availability();
                break;
            case 3:
                record();
                break;
            case 4:
                return;
        }
        system("cls");
    }
}


int main()
{
    while(1)
    {
        system("COLOR 0A");
        int option;
        printf("\n\n\n");
        printf("\t\t                       ##  ##    #######    #########    ########    ## \n           ");
        printf("                            ##  ##    ##   ##       ##        ##          ## \n           ");
        printf("                            ######    ##   ##       ##        ########    ## \n           ");
        printf("                            ##  ##    ##   ##       ##        ##          ## \n           ");
        printf("                            ##  ##    #######       ##        ########    ###### \n       ");

        printf("\n\n\n");
        printf("                            ###     ###    #######    ####    ##   #######    #######     ######    ###     ###   ######   ####    ##   #########      \n");
        printf("                            ## ## ## ##    ##   ##    ## ##   ##   ##   ##    ##          ##        ## ## ## ##   ##       ## ##   ##      ##          \n");
        printf("                            ##  ##   ##    #######    ##  ##  ##   #######    ##  ###     ######    ##  ##   ##   ######   ##  ##  ##      ##          \n");
        printf("                            ##       ##    ##   ##    ##   ## ##   ##   ##    ##   ##     ##        ##       ##   ##       ##   ## ##      ##          \n");
        printf("                            ##       ##    ##   ##    ##    ####   ##   ##    #######     ######    ##       ##   ######   ##    ####      ##          \n");

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t    { OPTIONS }");
        printf("\n\n\t\t\tADMIN\t\t\t[1]");
        printf("\n\t\t\tUSER\t\t\t[2]");
        printf("\n\t\t\tEDIT PASSWORD\t\t[3]");
        printf("\n\t\t\tEXIT\t\t\t[4]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                admin();
                break;
            case 2:
                user();
                break;
            case 3:
                edit_password();
                break;
            case 4:
                printf("\n\t\t\tTHANK YOU\t [-_-]\n");
                getch();
                return 0;
                break;
        }
        system("cls");
    }
    return 0;
}
