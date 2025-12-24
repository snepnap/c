#include<stdio.h>
int main(){
    int a,b;
    printf("enter row and col for your matrix");
    scanf("%d %d",&a,&b);
    int arr[][];
    int arr1[][];
    int add_arr[][];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("enter the value of %dx%d\n:-",i,j);
            scanf("%d",arr[i][j]);
        }
    }
    for ( int p = 0; p < a; p++){
        for(int q=0;q<b;q++){
            printf("enter the value of %dx%d\n:-",p,q);
            scanf("%d",arr1[p][q]);

        }
    }
    for(int k=0;k<a;k++){
        for(int l=0;l<b;l++){
            printf("%d",arr[k][l]);
        }
        printf("\n");
    }
    for(int k=0;k<a;k++){
        for(int l=0;l<b;l++){
            printf("%d",arr1[k][l]);
        }
        printf("\n");
    }
    for(int k=0;k<a;k++){
        for(int l=0;l<b;l++){
            add_arr[k][l]=arr[k][l]+arr1[k][l];
            printf("%d\n",add_arr[k][l]);
        }
    }
    return 0;

    
}