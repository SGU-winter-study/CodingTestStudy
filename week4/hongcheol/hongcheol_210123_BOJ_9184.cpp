'''
메모이제이션 연습.
함수 호출과 main에서 처리하는 코드 2개를 짰는데, 메모리 측면에서 개선은 있었지만, 속도에서의 개선은 없었다.
속도에서의 개선 방법을 찾아봐야겠다.

'''

//함수 호출을 이용한 방법
#include <stdio.h>

int arr[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if( a > 20 || b > 20 || c > 20) return w(20,20,20);
    int &temp = arr[a][b][c];//값 바로 변경시켜주기 위함.종만북에서 배움.
    
    if(temp != -1) return temp;
    if(a<b && b <c) return temp = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return temp = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1) - w(a-1,b-1,c-1);
}
int main(){
    int ans = 0;
    int a,b,c;
    for(int i = 0;i<21;i++){
        for(int j = 0;j<21;j++){
            for(int k = 0;k < 21; k++) arr[i][j][k] = -1;
        }
    }
    while(1){
        scanf("%d %d %d",&a,&b,&c);
        if( a == -1 && b == -1 && c == -1) break;
        else printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    return 0;
}

//main에서 처리
#include <stdio.h>

int main(){
    int a,b,c;
    int dp[21][21][21]={0,};
    for(int i = 0;i<21;i++){
        for(int j = 0;j<21;j++){
            for(int k = 0;k < 21; k++) {
                if(i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 1;
				else if(i < j && j < k)
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    while(1){
        scanf("%d %d %d",&a,&b,&c);
        if( a == -1 && b == -1 && c == -1) return 0;
        else if(a <= 0 || b <= 0 || c <= 0) printf("w(%d, %d, %d) = %d\n",a,b,c,1);
        else if( a > 20 || b > 20 || c > 20) printf("w(%d, %d, %d) = %d\n",a,b,c,dp[20][20][20]);
        else printf("w(%d, %d, %d) = %d\n",a,b,c,dp[a][b][c]);
    }
    return 0;
}
