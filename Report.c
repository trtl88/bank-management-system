void Report()
{
    char acc[20],current[20];
    int flag;
    FILE *f;
    printf("Enter account number to view report: ");
    do
    {
        scanf("%10s",acc);
        strcat(acc, ".txt");
        if((f=fopen(acc,"r"))==NULL)
        {
            printf("Account number not found, try again: ");
            flag=0;
        }
        else flag=1;
    }
    while(!flag);
