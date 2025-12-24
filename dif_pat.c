#include<stdio.h>
int main(){
    int row;
    printf("enter the row ");
    scanf("%d",&row);
    for(int i =1;i<=row;i++){
        for(int s=1;s<=row-i;s++){
            printf(" ");
        }
        int c =1;
        for( int j=1;j<=i;j++){
            printf("%d",c);
            printf(" ");
            c=c*(i-j)/j;
        }
        printf("\n");
    }
    return 0;
}