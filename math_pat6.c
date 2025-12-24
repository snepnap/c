#include<stdio.h>
int prime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            count++;
    }
    if(count==2)
        return n;
    else
        return 0;
}
int main(){
    int terms;
    printf("enter the number");
    scanf("%d",&terms);
    int a=2;
    for(int i=1;i<=terms;i++){
        int p=prime(i);
        if(p!=0){
            int m=a++*p;
            int num=m-1;
        printf("%d\n",num);
        }
    }
    return 0;
}