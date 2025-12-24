#include<stdio.h>
int prime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2)
        return n;
    else
        return 0;
}
int main(){
    int terms;
    printf("enter the num");
    scanf("%d",&terms);
    int a=2;
    for (int i=2;i<=terms;i++){
        int p=prime(i);
        if(p!=0){
            int d=a++*p;
            int num=2*d;
            printf("%d\n",num);
            
        }
    }
    return 0;
}

