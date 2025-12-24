#include<stdio.h>
int main(){
    int num1,num2,reminder,quatent;
    printf("enter the two number :-");
    scanf("%d %d",&num1,&num2);
    reminder=num1%num2;
    quatent=num1/num2;
    printf("reminder=%d,quatent=%d",reminder,quatent);
    return 0;
}