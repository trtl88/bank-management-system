void Report()
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
    int n=0;
    char amount[10],c;
    while (n<6)
    {
        int counter=-3;
        c=fgetc(f);
        while(c!='\n')
          {
            if(fseek(f,-2,SEEK_CUR)!=0)
                break;
            counter--;
            c=fgetc(f);
          }
        fscanf(f,"%s",amount);
        printf("%s\n",amount);
        n++;
        fseek(f,counter,SEEK_CUR);
    }
    fclose(f);
}
