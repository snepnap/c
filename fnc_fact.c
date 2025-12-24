#include<stdio.h>
void fact(int n){
    int d;
    int f=1;
    if(n==0){
        return;
    }
    else{
        d=n;
        f*=d;


        
    }
    printf("%d",f);
    fact(n-1);
    
}
int main(){
    fact(5);
    return 0;
}