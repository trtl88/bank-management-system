#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>

void LOGIN();
void LOAD();
void SEARCH();
void ADVANCED();
void ADD();
void DELETE();
void MODIFY();
void WITHDRAW();
void DEPOSIT();
void TRANSFER();
void REPORT();
void PRINT();
void SAVE();
void QUIT();
void MENU();
void SortByName();
void SortByBalance();
void SortByDate();

typedef struct
{
    int month;
    int year;
} date;

typedef struct
{
    char AccNo[11];
    char Name[100];
    char Email[100];
    float Balance;
    char Mobile[12];
    date DateOpened;
}  account;

typedef struct
{
    char username[100];
    char password[100];
} log;

account a[100]; //Global variable
int AccCount=0; //index to know how many lines in accounts file
const char* MonthName[]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
int loginflag=0;

int main()
{
    MENU();
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

void LOGIN()
{
    char username[100], password[100];
    int i=0,m;
    log s[100];
    FILE *f1=fopen("users.txt","r");
    while (!feof(f1))
    {
        fscanf(f1,"%s %s",s[i].username,s[i].password);
        i++;
    }
    m=i;
    printf("Username: ");
    scanf("%s",username);
    printf("Password: ");
    scanf("%s",password);
    i=0;
    while(i<m)
    {
        if((strcmp(username,s[i].username))==0&&(strcmp(password,s[i].password))==0)
        {
            printf("\nWelcome %s!\n",username);
            fclose(f1);
            loginflag=1;
            LOAD();
            return;
        }
        i++;
    }
    printf("Wrong username or password.\n\n");
    MENU();
}

void LOAD()
{
    int i=0;
    char x[500], temp[10];
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
                strcpy(a[i].Email, portion1);
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
        AccCount++;
    }
    fclose(f2);
}

void SEARCH()
{
    /*
       char Accnumber[11];
       int i,flag=0;
       while(1)
       {
           printf("Enter account number to view account's info: ");
           gets(Accnumber);
           Accnumber[strcspn(Accnumber,"\n")]='\0';
           if (!isnumeric(Accnumber))
           {
               printf("Invalid input. Please enter numeric digits only.\n");
           }
           else
               break;
       }
       for(i=0;i<AccCount;i++)
       {
           if(strstr(a[i].AccNo,Accnumber)!=NULL)
           {
               printf("Account Number: %s\n",a[i].AccNo);
               printf("Name: %s\n",a[i].Name);
               printf("E-mail: %s\n",a[i].Email);
               printf("Balance: %0.2f\n",a[i].Balance);
               printf("Mobile: %s\n",a[i].Mobile);
               printf("Date Opened: %s %d\n",MonthName[a[i].DateOpened.month-1],a[i].DateOpened.year);
               flag=1;
               break;
           }
       }
       if(flag==0)
           printf("Account number not found");*/
}

void ADVANCED()
{
    /*
       char userName[20];
       int i,flag=0;
       printf("Enter username to view: ");
       gets(userName);
       printf("Search Results:\n");
       for(i=0;i<AccCount;i++){
              if(strstr(a[i].Name,userName)!=NULL){
               printf("Account Number: %s\n",a[i].AccNo);
               printf("Name: %s\n",a[i].Name);
               printf("E-mail: %s\n",a[i].Email);
               printf("Balance: %0.2f\n",a[i].Balance);
               printf("Mobile: %s\n",a[i].Mobile);
               printf("Date Opened: %s %d\n",MonthName[a[i].DateOpened.month-1],a[i].DateOpened.year);
               flag=1;
              }
          }
          if(flag==0)
           {
           printf("Account number not found");
           }*/
}

void ADD()
{
    char newacc[20];
    int i,flag=1,lengthflag=1,digitflag;;
    printf("For account creation, provide a 10-digit account number: ");
    do
    {
        do
        {
            do
            {
                scanf(" %s",newacc);
                if(strlen(newacc)!=10)
                {
                    printf("Only 10 characters allowed, try again: ");
                    lengthflag=0;
                }
                else lengthflag=1;
            }
            while(lengthflag==0);

            digitflag=1;
            char *temp=newacc;
            while (*temp)
            {
                if (!isdigit(*temp))
                {
                    digitflag=0;
                    printf("Only digits allowed, try again: ");
                    break;
                }
                temp++;
            }
        }
        while(digitflag==0);
        flag=1;
        for(i=0; i<AccCount; i++)
        {
            if(strcmp(newacc,a[i].AccNo)==0)
            {
                flag=0;
                printf("Account number already exists, try again: ");
            }
        }
    }
    while(flag==0);

    char file_name[15];
    strcpy(file_name,newacc);
    file_name[10]='.';
    file_name[11]='t';
    file_name[12]='x';
    file_name[13]='t';
    file_name[14]='\0';
    FILE *f3=fopen(file_name,"w");
    fclose(f3);
    strcpy(a[AccCount].AccNo,newacc);
    printf("Enter name: ");
    scanf(" %[^\n]",a[AccCount].Name);
    printf("Enter e-mail address: ");
    scanf(" %s",a[AccCount].Email);
    printf("Enter balance: ");
    scanf("%f",&a[AccCount].Balance);
    printf("Enter mobile number: ");
    scanf(" %s",a[AccCount].Mobile);
    time_t t;
    t=time(NULL);
    struct tm tm=* localtime(&t);
    a[AccCount].DateOpened.month=tm.tm_mon+1;
    a[AccCount].DateOpened.year=tm.tm_year+1900;
    FILE *f2=fopen("accounts.txt","a");
    fprintf(f2,"\n%s,%s,%s,%.2f,%s,%d-%d",a[AccCount].AccNo,a[AccCount].Name,a[AccCount].Email,a[AccCount].Balance,a[AccCount].Mobile,a[AccCount].DateOpened.month,a[AccCount].DateOpened.year);
    fclose(f2);
    AccCount++;
    printf("Account added!\n\n");
    MENU();
    return;
}

void DELETE()
{

}
void MODIFY()
{

}
void WITHDRAW()
{

}
void DEPOSIT()
{

}
void TRANSFER()
{

}

void REPORT()
{
    char acc[15];
    FILE *f;
    printf("\nEnter account number to view last 5 transactions made: ");
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
    printf("Last 5 transactions(newest to oldest): \n");
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
                printf("%s\n\n",amount);
                fclose(f);
                MENU();
                return;
            }
            counter--;
        }
        n++;
        fscanf(f,"%s",amount);
        printf("%s\n",amount);//prints the transaction
        fseek(f,counter,SEEK_CUR); //sets the pointer right before the first digit of the line above the one printed
    } //loop repeats for the line above the printed one
    printf("\n");
    fclose(f);
    MENU();
}

void PRINT()
{
    int z;
    char sort[12];
    printf("Choose way of sorting:\n1.Name\n2.Balance\n3.Date opened\n");
    scanf("%d",&z);
    while(z!=1&&z!=2&&z!=3)
    {
        printf("Invalid. Enter 1, 2 or 3:\n");
        scanf("%d",&z);
    }
    switch(z)
    {
    case 1:
        strcpy(sort,"name");
        SortByName();
        break;
    case 2:
        strcpy(sort,"balance");
        SortByBalance();
        break;
    case 3:
        strcpy(sort,"date opened");
        SortByDate();
        break;
    }
    printf("\nAccounts sorted by %s:\n",sort);
    int i;
    for(i=0; i<AccCount-1; i++)
    {
        printf("Account Number: %s\n",a[i].AccNo);
        printf("Name: %s\n",a[i].Name);
        printf("E-mail: %s\n",a[i].Email);
        printf("Balance: %.2f$\n",a[i].Balance);
        printf("Mobile: %s\n",a[i].Mobile);
        printf("Date Opened: %s %d\n\n",MonthName[a[i].DateOpened.month-1],a[i].DateOpened.year);
    }
    MENU();
    return;
}

void SAVE();

void QUIT()
{
    exit(0);
}

void MENU()
{
    if(loginflag==0)
    {
        printf("1.LOGIN\n2.QUIT\n");
        printf("Choose one from the above options:\n");
        int z;
        scanf("%d",&z);
        while(z!=1&&z!=2)
        {
            printf("Invalid. Enter 1 or 2:\n");
            scanf("%d",&z);
        }
        if(z==1)
            LOGIN();
        else QUIT();
    }
    printf("1:ADD\n2:DELETE\n3:MODIFY\n4:SEARCH\n5:ADVANCED SEARCH\n6:WITHDRAW\n7:DEPOSIT\n8:TRANSFER\n9:REPORT\n10:PRINT\n11:QUIT\n");
    printf("Choose one from the above options:\n");
    int x;
    scanf("%d",&x);
    while(x<=0 || x>=12)
    {
        printf("Invalid. Enter a number between 1 and 11:\n");
        scanf("%d",&x);
    }
    switch(x)
    {
    case 1:
        ADD();
        break;
    case 2:
        DELETE();
        break;
    case 3:
        MODIFY();
        break;
    case 4:
        SEARCH();
        break;
    case 5:
        ADVANCED();
        break;
    case 6:
        WITHDRAW();
        break;
    case 7:
        DEPOSIT();
        break;
    case 8:
        TRANSFER();
        break;
    case 9:
        REPORT();
        break;
    case 10:
        PRINT();
        break;
    case 11:
        QUIT();
        break;
    }
}

void SortByName()
{
    for(int i=0; i<AccCount-1; i++)
    {
        for(int j=0; j<AccCount-i-1; j++)
        {
            if(strcmp(a[j].Name,a[j+1].Name)>0)
            {
                account temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void SortByBalance()
{
    for(int i=0; i<AccCount-1; i++)
    {
        for(int j=0; j<AccCount-i-1; j++)
        {
            if(a[j].Balance>a[j+1].Balance)
            {
                account temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void SortByDate()
{
    for(int i=0; i<AccCount-1; i++)
    {
        for(int j=0; j<AccCount-i-1; j++)
        {
            if(a[j].DateOpened.year>a[j+1].DateOpened.year)
            {
                account temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            if(a[j].DateOpened.year==a[j+1].DateOpened.year)
            {
                if(a[j].DateOpened.month>a[j+1].DateOpened.month)
                {
                    account temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
}
