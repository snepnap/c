#include<stdio.h>
int main(){
    int num1,num2,sum,mult,div,sub;
    printf("enter the two number");
    scanf("%d %d",&num1,&num2);
    sum=num1+num2;
    mult=num1*num2;
    div=num1/num2;
    sub=num1-num2;
    printf("sum=%d\nmult=%d\ndiv=%d\nsub=%d\n",sum,mult,div,sub);
    return 0;
}