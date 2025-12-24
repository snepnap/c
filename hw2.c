#include<stdio.h>
int main(){
    int num;
    int sum=0;
    printf("enter the number ");
    scanf("%d",&num);
    for(int i=1; i<=num;i++){
        int s=i*i;
        sum+=s;
    }
    printf("%d",sum);
    return 0;
}