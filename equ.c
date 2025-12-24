#include<stdio.h>
#include<math.h>
int main(){
    int x,a,b,c;
    printf("enter the value of a,b,c of your equation :-");
    scanf("%d %d %d",&a,&b,&c);
    int s=sqrt(b*b-4*a*c);
    x=-b+s/2*a;
    printf("%d",x);
    return 0;
}
