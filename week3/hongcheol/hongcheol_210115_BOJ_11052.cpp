#include <stdio.h>

int main(){
    int n = 0;
    int c[1001] = {0,};
    int dp[1001] = {0,};
    scanf("%d",&n);
    for(int i = 1;i<n+1;i++){
        scanf("%d",&c[i]);
 
    }
    c[0] = 0;
    dp[1] = c[1];
    for(int i = 2;i<n+1;i++){
        dp[i] = c[i];
        for(int j = 1;j<i+1;j++){
            if(dp[i] < dp[i-j]+c[j]) dp[i] = dp[i-j]+c[j];
        }
    }
    printf("%d",dp[n]);
    return 0;
}
