#include<stdio.h>
int main(){
    int a=3;
    int b=3;
    int arr[3][3]={{5,5,3},{3,5,2},{5,5,7}};
    int arr1[3][3]={{6,4,2},{5,3,2},{7,7,4}};
    int mult_arr[3][3];
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mult_arr[i][j]=arr[i][0]*arr1[0][j]+arr[i][1]*arr1[1][j]+arr[i][2]*arr1[2][j];
        }
    }
    for (int k=0;k<3;k++){
        for(int l=0;l<3;l++){
            printf("%d\n",mult_arr[k][l]);
        }
    }
    return 0;
}