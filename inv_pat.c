#include<stdio.h>
int main(){
    int row;
    printf("enter the row");
    scanf("%d",&row);
    for(int i=1;i<=row;i++){
        for(int s=1;s<=i;s++){
            printf(" ");
        

        }
        for(int j=row;j>=i;j--){
            printf("*");
            printf(" ");

        }
        printf("\n");

    }
    return 0;
}