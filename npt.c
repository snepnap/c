#include<stdio.h>
int main(){
    int num;
    printf("enter the num <20 ");
    scanf("%d",&num);
    if (num>20){
        printf("please enter the number < 20 ");
    }
    else{
        for(int i=0;i<num;i++){
            for(int s=1;s<num-i;s++){
                printf(" ");
            }
            for(char c='a'+i;c>='a';c--){
                printf("%c",c);
            }
            for(char rc='b';rc<='a'+i;rc++){
                printf("%c",rc);
            }
            printf("\n");
        }
    }
    return 0;
}