#include<stdio.h>
int main(){
    int row;
    int p;

    printf("enter the row");
    scanf("%d",&row);
    printf("enter the howmany * to use");
    scanf("%d",&p);
    for (int i=1;i<=row;i++){
        for(int s=1;s<i;s++){
            printf(" ");

        }
        for(int j=1;j<=p;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;

}