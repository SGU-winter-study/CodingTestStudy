'''
https://www.acmicpc.net/problem/1107
처음에 브루트포스로 0부터 999999까지 순회하면서 풀 계획을 했다.
근데 생각보다 쉽지않았다.
어떻게 풀면 좋을지 생각을하다가 버튼을 누른 횟수에따라서 백트래킹을 하면서 이동하려는 채널에 가장 근접한 채널을 구한 다음.
+,-로 이동한 결과를 반환하는 move함수를 구현했고,
이를 숫자키 없이 +,-로 이동한 경우랑 비교해서 더 작은 수를 출력하도록 구현했다.
처음에 버튼을 누르는 횟수를 다루는 반복문에서 구간을 실수로 [1,8)로 설정해야하는 것을 [0,7)로 설정했는데, 이떄, 1,1,1을 입력시 1이 출력되며 오답이 나와서 금방 잡을 수 있었다.

'''

#include <stdio.h>
#include <algorithm>
using namespace std;
int gojang[10] = {0,};
bool avail[10] = {true,};
int result = 11111111;
void move(int pushCount, int pushedNum, int number, int N){
    if(pushCount == number){
        result = min(result,abs(N-pushedNum)+number);
        return ;
    }
    for(int i =0; i<10;i++){
        if(avail[i] == true){
            move(pushCount+1,pushedNum*10+i,number,N);
        }
    }
}
int main(){
    int N = 0;
    int M = 0;
    int plusminus = 0;
    scanf("%d",&N);
    scanf("%d",&M);
    plusminus = N > 100 ? N-100 : 100-N;
    for(int i = 0;i<10;i++){
        avail[i] = true;
    }
    for(int i = 0;i<M;i++){
        scanf("%d",&gojang[i]);
    }
    for(int i = 0;i<M;i++){
        avail[gojang[i]] = false; 
    }
    for(int i = 1;i<8;i++){
        move(0,0,i,N);
    }
    printf("%d",min(plusminus,result));
}
