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
    int times;
    printf("enter how till you want to check");
    scanf("%d",&times);
    int num=1;
    for(int i=1;i<=times;i++){
        int p=0;
        p=prime(i);
        if(p!=0){
            int d=(p*p)+1;
            printf("%d\n",num); 
            num=num+d;
              
        }
    }
    return 0;
} 