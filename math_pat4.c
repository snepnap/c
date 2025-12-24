#include<stdio.h>
int main(){
    int terms;
    printf("enter the number how much terms you want");
    scanf("%d",&terms);
    int a=1;
    int num=1;
    for(int i=1;i<=terms;i++){
        printf("%d\n",num);
        num+=a;
        a=a+i;
    }
    return 0;
}