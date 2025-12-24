#include<stdio.h>
int main(){
    int i,j;
    int a=0;
    int b=1;


    int arr[2][2]={{2,3},{3,2}};
    int arr2[2][2]={{4,5},{5,4}};
    int mult_arr[2][2];
    for (i=0;i<2;i++){
        for(j=0;j<2;j++){
            mult_arr[i][j]=arr[i][a]*arr2[a][j]+arr[i][b]*arr2[b][j];
            printf("%d\n",mult_arr[i][j]);
        }
    }

    return 0;
}