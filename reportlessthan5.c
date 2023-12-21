#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define TRANSACTIONS 6

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
    printf("Last 5 transactions: ");
    fseek(f,-2,SEEK_END);
    char amount[10],c;
    int n=0;
    while(n<TRANSACTIONS)
    {
        int counter=-3;
        c=fgetc(f);
        while(c!='\n')
        {
            for(int i=0; i<2; i++)
            {
                fseek(f,-1,SEEK_CUR);
                if(ftell(f)<1)
                {
                    fseek(f,0,SEEK_SET);
                    fscanf(f,"%s",amount);
                    printf("%s\n",amount);
                    return;
                }
            }
            counter--;
            c=fgetc(f);
        }
        fscanf(f,"%s",amount);
        printf("%s\n",amount);
        fseek(f,counter,SEEK_CUR);
        n++;
    }
    fclose(f);
}
