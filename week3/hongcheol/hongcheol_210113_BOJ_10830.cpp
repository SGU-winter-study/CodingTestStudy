'''

분할 정복의 기본이 되는 문제
b제곱을 했을 때, b/2로 분할하고 홀수인 경우에는 b-1,1로 나눠서 행렬곱을 진행했다.
'''

#include <stdio.h>

int n;
int a[5][5],ans[5][5],temp[5][5];
void multiMat(int A[5][5],int B[5][5]){
    for(int j = 0;j<n;j++){
        for(int i = 0;i<n;i++){
            temp[i][j] = 0;
            for(int l = 0;l<n;l++){
                temp[i][j] += A[i][l]*B[l][j]; 
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            A[i][j] = temp[i][j]%1000;
        }
    }    
}
int main(){
    long long b;
    scanf("%d %lld",&n,&b);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
        ans[i][i] = 1;
    }
    while(b>0){
        if(b%2 == 1) multiMat(ans,a);
        multiMat(a,a);
        b /= 2;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }  
}
