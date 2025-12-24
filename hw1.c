#include<stdio.h>
int main(){
    int num;
    printf("enter the number ");
    scanf("%d",&num);
    int sum=0;
    for(int i=1; i<=num; i++){
        sum+=i;
    }
    printf("%d",sum);
    return 0;

}