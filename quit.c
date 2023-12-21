#include <stdio.h>
#include <stdlib.h>
void quit(){
    printf("1.log in\n2.exit\n");
    int x;
    scanf("%d",&x);
    while (x<=0 || x>=3){
        printf("choose between 1 and 2\n");
        scanf("%d",&x);}
    switch(x){
        case 1: printf("hello"); //call func log in//
        break;
        case 2: printf("exit");

    }

}
int main()
{
    quit();
    return 0;
}
