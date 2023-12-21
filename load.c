#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

account a[100]; //Global variable
int count1=0; //index to know how many lines in accounts file

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

int main()
{
    load();
    // printf("%s", a[1].AccNo);
    return 0;
}
