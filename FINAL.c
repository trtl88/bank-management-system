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
void ModifyName();
void ModifyMobile();
void ModifyEmail();

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
int AccCount=0,loginflag=0,ModifyIndex;
const char* MonthName[]= {"January","February","March","April","May","June","July","August","September","October","November","December"};

int main()
{
    MENU();
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
    AccCount=0;
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
    char AccNumber[20];
    int flag=0,numeric=0;
    printf("Enter the account number to search for: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }
    for (int i=0; i<AccCount; i++)
    {
        if (strcmp(a[i].AccNo,AccNumber)==0)
        {
            printf("Account Number: %s\n",a[i].AccNo);
            printf("Name: %s\n",a[i].Name);
            printf("E-mail: %s\n",a[i].Email);
            printf("Balance: %0.2f\n",a[i].Balance);
            printf("Mobile: %s\n",a[i].Mobile);
            printf("Date Opened: %s %d\n\n",MonthName[a[i].DateOpened.month - 1],a[i].DateOpened.year);
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("Account not found\n\n");
    MENU();
}

void ADVANCED()
{
    char userName[20];
    int i,flag=0;
    printf("Enter keyword: ");
    scanf(" %[^\n]",userName);
    printf("Search Results:\n");
    for(i=0; i<AccCount; i++)
    {
        if(strstr(a[i].Name,userName)!=NULL)
        {
            printf("Account Number: %s\n",a[i].AccNo);
            printf("Name: %s\n",a[i].Name);
            printf("E-mail: %s\n",a[i].Email);
            printf("Balance: %0.2f\n",a[i].Balance);
            printf("Mobile: %s\n",a[i].Mobile);
            printf("Date Opened: %s %d\n\n",MonthName[a[i].DateOpened.month-1],a[i].DateOpened.year);
            flag=1;
        }
    }
    if(flag==0)
        printf("No accounts found.\n\n");
    MENU();
}

void ADD()
{
    char AccNumber[20],balance[20];
    int i,x,found=0,numeric=0,nameflag=0,emailflag=0;
    printf("For account creation, provide a 10-digit account number: ");
    while(!found)
    {
        numeric=0;
        while(!numeric)
        {
            while(1)
            {
                scanf(" %s",AccNumber);
                if(strlen(AccNumber)!=10)
                    printf("Only 10 characters allowed, try again: ");
                else break;
            }
            for(int i=0; AccNumber[i]!='\0'; i++)
            {
                if (!isdigit(AccNumber[i]))
                {
                    numeric=0;
                    printf("Only digits allowed, try again: ");
                    break;
                }
                else
                    numeric=1;
            }
        }

        for(i=0; i<AccCount; i++)
        {
            if(strcmp(AccNumber,a[i].AccNo)==0)
            {
                printf("Account number already exists, try again: ");
                found=0;
                break;
            }
            else found=1;
        }
    }
    strcpy(a[AccCount].AccNo,AccNumber);
    while(!nameflag)
    {
        printf("Enter name: ");
        scanf(" %[^\n]",a[AccCount].Name);
        for(i=0; a[AccCount].Name[i]; i++)
        {
            if((!isalpha(a[AccCount].Name[i]))&&(a[AccCount].Name[i])!=' ')
            {
                printf("The name shouldn't include any numbers or special characters.\n");
                nameflag=0;
                break;
            }
            else nameflag=1;
        }
    }
    while(!emailflag)
    {
        printf("Enter e-mail address: ");
        scanf(" %s",a[AccCount].Email);
        if((strstr(a[AccCount].Email,"@")==NULL)&&(strstr(a[AccCount].Email,".com")==NULL)&&(strstr(a[AccCount].Email," ")==NULL))
        {
            printf("Invalid email format.\n");
            emailflag=0;
        }
        else emailflag=1;
    }
    numeric=0;
    printf("Enter balance: ");
    while(!numeric)
    {
        scanf(" %s",balance);
        for(i=0; balance[i]!='\0'; i++)
        {
            if((!isdigit(balance[i]))&&balance[i]!='.')
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else numeric=1;
        }
    }
    a[AccCount].Balance=atof(balance);
    printf("Enter mobile number: ");
    numeric=0;
    while(!numeric)
    {
        scanf(" %s",a[AccCount].Mobile);
        for(i=0; a[AccCount].Mobile[i]!='\0'; i++)
        {
            if(!isdigit(a[AccCount].Mobile[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else numeric=1;
        }
    }
    time_t t;
    t=time(NULL);
    struct tm tm=* localtime(&t);
    a[AccCount].DateOpened.month=tm.tm_mon+1;
    a[AccCount].DateOpened.year=tm.tm_year+1900;
    AccCount++;
    printf("Account added!\n\n");
    printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n#:");
    scanf("%d",&x);
    while(x!=1&&x!=2)
    {
        printf("Invalid. Enter 1 or 2:\n");
        scanf("%d",&x);
    }


    if(x==1)
    {
        FILE *f=fopen("accounts.txt", "w");
        for(i=0; i<AccCount; i++)
        {
            if(i==0)
                fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
            else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
        }
        fclose(f);
        printf("Saved changes!\n\n");
        char file_name[15];
        strcpy(file_name,AccNumber);
        strcat(file_name,".txt");
        FILE *f3=fopen(file_name,"w");
        fclose(f3);
        LOAD();
        MENU();
        return;
    }
    else
    {
        printf("Discarded changes.\n\n");
        LOAD();
        MENU();
        return;
    }
}

void DELETE()
{
    char AccNumber[20],temp[20];
    int i,x,found,numeric=0;
    float temp2;
    printf("Enter the account number you want to delete: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }

    for(i=0; i<AccCount; i++)
    {
        if(strcmp(AccNumber,a[i].AccNo)!=0)
        {
            found=0;
        }
        else
        {
            found=1;
            if(a[i].Balance==0)
            {
                strcpy(temp,(a[i].AccNo));
                strcpy((a[i].AccNo),(a[AccCount-1].AccNo));
                strcpy((a[AccCount-1].AccNo),temp);
                strcpy(temp,(a[i].Name));
                strcpy((a[i].Name),(a[AccCount-1].Name));
                strcpy((a[AccCount-1].Name),temp);
                strcpy(temp,(a[i].Email));
                strcpy((a[i].Email),(a[AccCount-1].Email));
                strcpy((a[AccCount-1].Email),temp);
                temp2=a[i].Balance;
                a[i].Balance=a[AccCount-1].Balance;
                a[AccCount-1].Balance=temp2;
                strcpy(temp,(a[i].Mobile));
                strcpy((a[i].Mobile),(a[AccCount-1].Mobile));
                strcpy((a[AccCount-1].Mobile),temp);
                temp2=a[i].DateOpened.month;
                a[i].DateOpened.month=a[AccCount-1].DateOpened.month;
                a[AccCount-1].DateOpened.month=temp2;
                temp2=a[i].DateOpened.year;
                a[i].DateOpened.year=a[AccCount-1].DateOpened.year;
                a[AccCount-1].DateOpened.year=temp2;
                AccCount--;
                printf("Account deleted!\n\n");


                printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n");
                scanf("%d",&x);
                while(x!=1&&x!=2)
                {
                    printf("Invalid. Enter 1 or 2:\n");
                    scanf("%d",&x);
                }


                if(x==1)
                {
                    FILE *f=fopen("accounts.txt", "w");
                    for(i=0; i<AccCount; i++)
                    {
                        if(i==0)
                            fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                        else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                    }
                    fclose(f);
                    printf("Saved changes!\n\n");
                    strcat(AccNumber,".txt");
                    remove(AccNumber);
                    LOAD();
                    MENU();
                    return;
                }
                else
                {
                    printf("Discarded changes.\n\n");
                    LOAD();
                    MENU();
                    return;
                }
                break;
            }
            else
            {
                printf("Balance not equal zero, can't delete account.\n\n");
                MENU();
                return;
            }
        }
    }
    if(!found)
    {
        printf("Account not found.\n\n");
        MENU();
        return;
    }
}

void MODIFY()
{
    int i,j,found=0,numeric=0;
    char AccNumber[20];
    printf("Enter account number to modify its data: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }
    for(i=0; i<AccCount; i++)
    {
        if(strcmp(AccNumber,a[i].AccNo)==0)
        {
            found=1;
            ModifyIndex=i;
            break;
        }
    }
    if(!found)
    {
        printf("Account not found.\n\n");
        MENU();
        return;
    }
    printf("\nAccount Number: %s\n",a[ModifyIndex].AccNo);
    printf("Name: %s\n",a[ModifyIndex].Name);
    printf("E-mail: %s\n",a[ModifyIndex].Email);
    printf("Balance: %0.2f\n",a[ModifyIndex].Balance);
    printf("Mobile: %s\n",a[ModifyIndex].Mobile);
    printf("Date Opened: %s %d\n\n",MonthName[a[ModifyIndex].DateOpened.month - 1],a[ModifyIndex].DateOpened.year);
    while(1)
    {
        printf("Which one from the following do you want to modify:\n1:Name\n2:Mobile\n3:Email\n4.SAVE\n#:");
        scanf("%d",&j);
        while(j<=0||j>=5)
        {
            printf("Invalid. Enter a number between 1 and 4:\n#: ");
            scanf("%d",&j);
        }
        switch(j)
        {
        case 1:
            ModifyName();
            break;
        case 2:
            ModifyMobile();
            break;
        case 3:
            ModifyEmail();
            break;
        case 4:
            SAVE();
            return;
        }
    }
}

void WITHDRAW()
{
    char AccNumber[20];
    float amount;
    int i,x,numeric=0,found=0;
    printf("Enter account number: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }
    for(i=0; i<AccCount; i++)
    {
        if(strcmp(AccNumber,a[i].AccNo)==0)
        {
            printf("Enter amount to be withdrawn: ");
            scanf("%f",&amount);
            if(amount>10000)
                printf("Maximum withdraw limit is $10,000\nTransaction failed!\n\n");
            else
            {
                a[i].Balance-=amount;
                printf("Transaction Successful!\n\n");
                printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n");
                scanf("%d",&x);
                while(x!=1&&x!=2)
                {
                    printf("Invalid. Enter 1 or 2:\n");
                    scanf("%d",&x);
                }


                if(x==1)
                {
                    FILE *f=fopen("accounts.txt", "w");
                    for(i=0; i<AccCount; i++)
                    {
                        if(i==0)
                            fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                        else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                    }
                    fclose(f);
                    printf("Saved changes!\n\n");
                    strcat(AccNumber,".txt");
                    FILE *f1=fopen(AccNumber,"a");
                    fprintf(f1,"-%.2f\n",amount);
                    fclose(f1);
                    LOAD();
                    MENU();
                    return;
                }
                else
                {
                    printf("Discarded changes.\n\n");
                    LOAD();
                    MENU();
                    return;
                }
            }
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Account not found.\n\n");
        MENU();
        return;
    }
}

void DEPOSIT()
{
    char AccNumber[20];
    float amount;
    int i,x,numeric=0,found=0;
    printf("Enter account number: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }
    for(i=0; i<AccCount; i++)
    {
        if(strcmp(AccNumber,a[i].AccNo)==0)
        {
            printf("Enter amount to be deposited: ");
            scanf("%f",&amount);
            if(amount>10000)
                printf("Maximum deposit limit is $10,000\nTransaction failed!\n\n");
            else
            {
                a[i].Balance+=amount;
                printf("Transaction Successful!\n\n");
                printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n");
                scanf("%d",&x);
                while(x!=1&&x!=2)
                {
                    printf("Invalid. Enter 1 or 2:\n");
                    scanf("%d",&x);
                }


                if(x==1)
                {
                    FILE *f=fopen("accounts.txt", "w");
                    for(i=0; i<AccCount; i++)
                    {
                        if(i==0)
                            fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                        else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
                    }
                    fclose(f);
                    printf("Saved changes!\n\n");
                    strcat(AccNumber,".txt");
                    FILE *f1=fopen(AccNumber,"a");
                    fprintf(f1,"+%.2f\n",amount);
                    fclose(f1);
                    LOAD();
                    MENU();
                    return;
                }
                else
                {
                    printf("Discarded changes.\n\n");
                    LOAD();
                    MENU();
                    return;
                }
            }
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Account not found.\n\n");
        MENU();
        return;
    }
}

void TRANSFER()
{
    char sender[20],receiver[20];
    int i,x,flag=0,found=0,numeric=0,sendID,receiveID;
    float amount;
    printf("Please enter sender's account number: ");
    while(found==0)
    {
        while(!numeric)
        {
            while(1)
            {
                scanf("%s",sender);
                if(strlen(sender)!=10)
                    printf("Only 10 characters allowed, try again: ");
                else break;
            }
            for(int i=0; sender[i]!='\0'; i++)
            {
                if (!isdigit(sender[i]))
                {
                    numeric=0;
                    printf("Only digits allowed, try again: ");
                    break;
                }
                else
                    numeric=1;
            }
        }
        for(i=0; i<AccCount; i++)
        {
            if(strcmp(sender,a[i].AccNo)==0)
            {
                sendID=i;
                found=1;
                break;
            }
        }
        if(found==0)
            printf("Account not found, try again: ");
    }
    numeric=0;
    found=0;
    printf("Please enter receiver's account number: ");
    while(found==0)
    {
        while(!numeric)
        {
            while(1)
            {
                scanf("%s",receiver);
                if(strlen(receiver)!=10)
                    printf("Only 10 characters allowed, try again: ");
                else break;
            }
            for(int i=0; receiver[i]!='\0'; i++)
            {
                if (!isdigit(receiver[i]))
                {
                    numeric=0;
                    printf("Only digits allowed, try again: ");
                    break;
                }
                else
                    numeric=1;
            }
        }
        for(i=0; i<AccCount; i++)
        {
            if(strcmp(receiver,a[i].AccNo)==0)
            {
                receiveID=i;
                found=1;
                break;
            }
        }
        if(found==0)
        {
            printf("Account not found, try again: ");
            flag=0;
        }
    }
    printf("Enter amount to be transferred: ");
    flag=0;
    while(!flag)
    {
        scanf("%f",&amount);
        if(amount>10000)
        {

            printf("Maximum transfer limit is $10,000!\nEnter amount again: ");
            flag=0;
        }
        else flag=1;
    }
    a[sendID].Balance-=amount;
    a[receiveID].Balance+=amount;
    printf("Transaction Successful!\n");
    printf("Sender's new balance=%.2f\n",a[sendID].Balance);
    printf("Receiver's new balance=%.2f\n\n",a[receiveID].Balance);
    printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n");
    scanf("%d",&x);
    while(x!=1&&x!=2)
    {
        printf("Invalid. Enter 1 or 2:\n");
        scanf("%d",&x);
    }


    if(x==1)
    {
        FILE *f=fopen("accounts.txt", "w");
        for(i=0; i<AccCount; i++)
        {
            if(i==0)
                fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
            else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
        }
        fclose(f);
        printf("Saved changes!\n\n");
        strcat(sender,".txt");
        strcat(receiver,".txt");
        FILE *fs=fopen(sender,"a");
        FILE *fr=fopen(receiver,"a");
        fprintf(fs,"-%.2f\n",amount);
        fprintf(fr,"+%.2f\n",amount);
        fclose(fs);
        fclose(fr);
        LOAD();
        MENU();
        return;
    }
    else
    {
        printf("Discarded changes.\n\n");
        LOAD();
        MENU();
        return;
    }
}

void REPORT()
{
    char AccNumber[20];
    int numeric=0;
    printf("Enter account number to view last 5 transactions made: ");
    while(!numeric)
    {
        while(1)
        {
            scanf("%s",AccNumber);
            if(strlen(AccNumber)!=10)
                printf("Only 10 characters allowed, try again: ");
            else break;
        }
        for(int i=0; AccNumber[i]!='\0'; i++)
        {
            if (!isdigit(AccNumber[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else
                numeric=1;
        }
    }
    strcat(AccNumber,".txt");
    FILE *f;
    if((f=fopen(AccNumber,"r"))==NULL)
    {
        printf("No history found for this account.\n\n");
        MENU();
        return;
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
    return;
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
    for(i=0; i<AccCount; i++)
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

void SAVE()
{
    int x,i;
    printf("Do you want to save this operation?\n1.Yes\n2.No, discard changes.\n");
    scanf("%d",&x);
    while(x!=1&&x!=2)
    {
        printf("Invalid. Enter 1 or 2:\n");
        scanf("%d",&x);
    }


    if(x==1)
    {
        FILE *f=fopen("accounts.txt", "w");
        for(i=0; i<AccCount; i++)
        {
            if(i==0)
                fprintf(f,"%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
            else fprintf(f,"\n%s,%s,%s,%.2f,%s,%d-%d",a[i].AccNo,a[i].Name,a[i].Email,a[i].Balance,a[i].Mobile,a[i].DateOpened.month,a[i].DateOpened.year);
        }
        fclose(f);
        printf("Saved changes!\n\n");
        LOAD();
        MENU();
        return;
    }
    else
    {
        printf("Discarded changes.\n\n");
        LOAD();
        MENU();
        return;
    }
}

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
void ModifyName()
{
    printf("Enter the new name: ");
    char n[100];
    scanf(" %[^\n]", n);
    int i=0;
    while(n[i])
    {
        if (!(isalpha(n[i])) && n[i]!=' ')
        {
            printf("The name shouldn't include any numbers or special characters.\n");
            ModifyName();
            return;
        }
        i++;
    }
    strcpy(a[ModifyIndex].Name, n);
    printf("Modified name!\n");
    return;
}
void ModifyMobile()
{
    int i,numeric=0;
    printf("Enter the new mobile number: ");
    char n[20];
    while(!numeric)
    {
        while(1)
        {
            scanf(" %s", n);
            if(strlen(n)!=11)
                printf("Invalid. Enter 11 digits: ");
            else break;
        }
        for(i=0; n[i]!='\0'; i++)
        {
            if (!isdigit(n[i]))
            {
                numeric=0;
                printf("Only digits allowed, try again: ");
                break;
            }
            else numeric=1;
        }
    }
    strcpy(a[ModifyIndex].Mobile, n);
    printf("Modified mobile number!\n");
    return;
}
void ModifyEmail()
{
    char n[100];
    printf("Enter new email address: ");
    scanf(" %s",n);
    if((strstr(n,"@")==NULL)&&(strstr(n,".com")==NULL)&&(strstr(n," ")==NULL))
    {
        printf("Invalid email format.\n");
        ModifyEmail();
        return;
    }
    strcpy(a[ModifyIndex].Email,n);
    printf("Modified e-mail!\n");
    return;
}
