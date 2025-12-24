#include<stdio.h>
void pattern(int row){
    for (int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    int r;
    printf("enter the  row");
    scanf("%d",&r);
    pattern(r);
    return 0;

}