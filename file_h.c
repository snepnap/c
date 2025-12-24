#include<stdio.h>
int main(){
    FILE *file;
    file=fopen("addr.txt","r");
    char ch;
    for(int i=0;i<19;i++){
        fscanf(file,"%c",&ch);
        printf("%c",ch);
    }
    fclose;
    return 0;
}