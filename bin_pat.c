#include<stdio.h>
int main(){
    int n=0;
    int a=1;
    int d=1;
    int p=1;
    for (int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if((i+j)%2==0)
                printf("%d",1);
            else
                printf("%d",0);
        }
        printf("\n");
    }
    return 0;
}