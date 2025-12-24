#include<stdio.h>
int main(){
    int terms;
    printf("enter the how many terms you want");
    scanf("%d",&terms);
    int num=1;
    for(int i=1;i<=terms;i++){
        long int s=i*i;
        printf("%d\n",num);
        num+=s;
    }
    return 0;
}