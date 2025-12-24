#include<stdio.h>
int main(){
    int temp;
    int arr[5]={5,3,6,7,3};
    for(int i=0;i<4;i++){
        for (int j=1+i;j<5;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int k=0;k<5;k++){
        printf("%d\n",arr[k]);
    }
    return 0;
}