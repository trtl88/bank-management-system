#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char username[100];
    char password[100];
}log;
int main()
{
    char username[100], password[100];
    int i=0,l,flag=1;
    log s[100];
    gets(username);
    gets(password);
    FILE *f1=fopen("users.txt","r");
    while (!feof(f1)){
        fscanf(f1,"%s %s",s[i].username,s[i].password);
        i++;
    }
    l=i;
    i=0;
    while(i<l){
    if((strcmp(username,s[i].username))==0&&(strcmp(password,s[i].password))==0){

                printf("found");
                flag=0;
                break;

    }
    i++;
    }
    if(flag)
        printf("not found");
    fclose(f1);

    return 0;
}
