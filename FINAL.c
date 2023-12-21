#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int month;
    int year;
} date;

typedef struct
{
    char AccNo [12];
    char Name [100];
    char Address [100];
    float Balance;
    char Mobile [12];
    date DateOpened;
}  account;

typedef struct
{
    char username[100];
    char password[100];
} log;

account a[100]; //Global variable
int count1=0; //index to know how many lines in accounts file

void report()
{
    char acc[15],current[20];
    FILE *f;
    printf("Enter account number to view last 5 transactions made: ");
    scanf("%s",acc);
    strcat(acc,".txt");
    while((strlen(acc)!=14)||(f=fopen(acc,"r"))==NULL)
    {
        if(strlen(acc)!=14)
        {
            printf("Invalid account number, try again: ");
            scanf("%s",acc);
            strcat(acc, ".txt");
        }
        else
        {
            printf("Account number not found, try again: ");
            scanf("%s",acc);
            strcat(acc, ".txt");
        }
    }
    printf("Last 5 transactions: \n");
    fseek(f,-3,SEEK_END); //sets position of pointer right before the last number in the file
    char amount[10];
    int n=0;
    while(n<5) //prints 5 transactions or less
    {
        int counter=-3;
        char c;
        while ((c=fgetc(f))!='\n') //checks if the pointer is at a new line
        {
            fseek(f,-2,SEEK_CUR);
            if(ftell(f)<2) //checks if this is the first transaction in the file, prints it and exits function
            {
                fseek(f,0,SEEK_SET); //resets pointer to beginning of file
                fscanf(f,"%s",amount);
                printf("%s\n",amount);
                fclose(f);
                menu();
                return;
            }
            counter--;
        }
        n++;
        fscanf(f,"%s",amount);
        printf("%s\n",amount);//prints the transaction
        fseek(f,counter,SEEK_CUR); //sets the pointer right before the first digit of the line above the one printed
    } //loop repeats for the line above the printed one
    fclose(f);
    menu();
}

void print()
{

}

void menu()
{
    printf("1:ADD\n2:DELETE\n3:MODIFY\n4:SEARCH\n5:ADVANCED SEARCH\n6:WITHDRAW\n7:DEPOSIT\n8:TRANSFER\n9:REPORT\n10:PRINT\n11:QUIT\n");
    printf("Choose one from the above options:\n");
    int x;
    scanf("%d", &x);
    while(x<=0 || x>=12)
    {
        printf("Invalid. Enter a number between 1 and 11:\n");
        scanf("%d", &x);
    }
    switch(x)
    {
    case 1:
        printf("a");//call add func.
        break;
    case 2:
        printf("b"); //call delete func.
        break;
    case 3:
        printf("c"); //call modify func.
        break;
    case 4:
        printf("d"); //call search func.
        break;
    case 5:
        printf("e"); //call advanced search func.
        break;
    case 6:
        printf("f"); //call withdraw func.
        break;
    case 7:
        printf("h"); //call deposit func.
        break;
    case 8:
        printf("i"); //call transfer func.
        break;
    case 9:
        report(); //call report func.
        break;
    case 10:
        printf("k"); //call print func.
        break;
    case 11:
        quit(); //call quit func.
        break;
    }
}

void load()
{
    int i=0;
    char c, x[500], temp[10];
    FILE *f2= fopen("accounts.txt", "r");
    while(!feof(f2))
    {
        int j=0;
        fgets(x,500,f2);
        char *portion1=strtok(x, ",");
        while(portion1!=NULL)
        {
            switch(j)
            {
            case 0:
                strcpy(a[i].AccNo, portion1);
                break;
            case 1:
                strcpy(a[i].Name, portion1);
                break;
            case 2:
                strcpy(a[i].Address, portion1);
                break;
            case 3:
                a[i].Balance=atof(portion1);
                break;
            case 4:
                strcpy(a[i].Mobile, portion1);
                break;
            case 5:
                strcpy(temp, portion1);
                char *portion2=strtok(temp, "-");
                a[i].DateOpened.month=atoi(portion2);
                portion2=strtok(NULL,"-");
                a[i].DateOpened.year=atoi(portion2);
                break;
            }
            portion1=strtok(NULL,",");
            j++;
        }
        i++;
        count1++;
    }
}

void quit()
{
    exit(0);
}

int login()
{
    char username[100], password[100];
    int i=0,m,flag=0;
    log s[100];
    FILE *f1=fopen("users.txt","r");
    while (!feof(f1))
    {
        fscanf(f1,"%s %s",s[i].username,s[i].password);
        i++;
    }
    m=i;
    while(1)
    {
        printf("Username: ");
        scanf("%s",username);
        printf("Password: ");
        scanf("%s",password);
        i=0;
        while(i<m)
        {
            if((strcmp(username,s[i].username))==0&&(strcmp(password,s[i].password))==0)
            {
                printf("Welcome %s!\n",username);
                flag=1;
                menu();
                return;
            }
            i++;
        }
        flag=0;
        printf("Wrong username or password, try again.\n");
        fclose(f1);
    }
}

int main()
{
    login();
    //menu();
    /*int d;
    FILE*f=fopen("1234567890.txt","w");
    fprintf(f,"+100\n-2\n-1\n+1\n-2000\n+10000\n");
    fclose(f);
    printf("choose option: ");
    scanf("%d",&d);
    if(d==1)
        report();
    if(d==2)
        print();
    if(d==3)
        quit();*/
    return 0;
}
