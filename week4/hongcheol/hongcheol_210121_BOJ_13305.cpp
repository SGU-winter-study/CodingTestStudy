'''
https://www.acmicpc.net/problem/13305
처음에 long long 에 대입할 때, int*int 한 상태로 넣어줬다.
채점 항목 중에 넘어가는 것이 있을 것이라 생각해서 long long으로 설정했었는데, 자동으로 해줄거라고 생각하고 그냥 제출했다가 틀렸다.

그 이외에는 그냥 쭉 순회하면서 이전 값보다 크면 이전 값으로 바꿔줘서 가장 저렴한 기름값들을 각 도시에 저장했다.
그 다음 거리와 기름값을 곱해줬다.

분명 시간을 더 줄일 수 있는 방법이 있을 것 같은데.. 모르겠다..
'''

#include <stdio.h>

int main(){
    long long d[100001] ={0,};
    long long city[100001] = {0,};
    int n = 0;
    long long price = 0;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        scanf("%lld",&d[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%lld",&city[i]);
    }
    for(int i = 1;i<n;i++){
        if(city[i-1]<city[i]) city[i] = city[i-1];

        price += d[i-1]*city[i-1];
    }
    printf("%lld",price);
}
