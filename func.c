#include <stdio.h>
float area(float r){
    float x=r*r*3.14;
    return x;
}
float main(){
    float rad;
    printf("enter the radius");
    scanf("%f",&rad);
    float arr=area(rad);
    printf("%f",arr);
    return 0;
}