#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("You have logged in successfully.\n");
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
        printf("j"); //call report func.
        break;
    case 10:
        printf("k"); //call print func.
        break;
    case 11:
        printf("l"); //call quit func.
        break;
    }
}
