#include<stdio.h>
int main(){
    for(int i=0;i<7;i++){
        for(char c='A';c<72-i;c++){
            printf("%c",c);
        
        }
        for(int s=1;s<=2*i-1;s++){
            printf(" ");
            

        }
        int a=1;
        for(char rc='G'-i;rc>='A';rc--){
            if(i==0 && rc=='G')
                continue;
            else
                printf("%c",rc);
            
        }
        printf("\n");

       
       
    }
    return 0;
}