#include<stdio.h>
int main(){
    int length,breadth,peri;
    printf("enter the two number");
    scanf("%d %d",&length,&breadth);
    peri=2*(length+breadth);
    printf("%d",peri);
    return 0;
}