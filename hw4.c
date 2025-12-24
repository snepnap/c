#include<stdio.h>
int main(){
    int num;
    int sum=0;
    printf("enter the number");
    scanf("%d",&num);
    for(int i=2;i<=num;i++){
        int n=3*i;
        sum+=n;
    }
    printf("%d",sum);
    return 0;
}