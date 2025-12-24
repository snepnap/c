#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    printf("\n**************************");
    printf("\n=========welcome==========");
    printf("\n**************************");
    int obj;
    printf("\nenter how much product have");
    scanf("%d",&obj);
    char block[obj];
    float price[obj];
    int quantity[obj];
    for (int i=0;i<obj;i++){
        printf("enter your object\n");
        scanf("%s",&block[i]);
        printf("enter the price of the product:-\n");
        scanf("%f",&price[i]);
        printf("enter the quantity availble of the product:-\n");
        scanf("%d",&quantity[i]);
    }
    printf("product                                                            price             quantity\n");
    for (int j=0;j<obj;j++){

        printf("%d.%c                                                                %f            %d\n",j,block[j],price[j],quantity[j]);
    }
    return 0;
}