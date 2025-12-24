# include <stdio.h>
int main (){
    int row;
    printf("enter the how many row you want");
    scanf("%d",&row);
    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i;j++){
            printf(" ");
        }
        for(int k=1; k<=i;k++){
            printf("%d",k);
        }
        printf("\n");
    }
    return 0;

}