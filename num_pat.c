#include<stdio.h>
int main(){
    int num=1;
    for (int i=1;i<=4;i++){
        for(int s=4;s>i;s--){
            printf(" ");
        }
        for(int j=0;j<i;++j){
            printf("%d",num);
            printf(" ");
            num++;
        }
        printf("\n");
    }
    return 0;
}