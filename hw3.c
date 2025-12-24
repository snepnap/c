#include<stdio.h>
int main(){
    int num;
    long int sum=0;
    printf("enter the number ");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        int s=i*i*i;
        sum+=s;
    }
    printf("%ld",sum);
    return 0;
}