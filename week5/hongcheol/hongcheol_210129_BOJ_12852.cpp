/*
처음에는 make_one 배열에서 n에서 1까지 이동하면서 처리하려고했다.
이 방법은 이전 단계에 어디서 왔는지에대한 정보가 없어서 오류가 있는 방법이였다.
그래서 이전 단계를 저장하고있는 배열을 따로 만들어서 그 안에 저장을 해줬다. 
*/

#include <stdio.h>

int make_one[1000001] ={0,};
int step[1000001] = {0,};

int min(int a, int b){
	return a>b ? b : a;
}

int main(void) {
	int n = 0;
	scanf("%d",&n);
	int ans = 0;
	make_one[1] = 0;
	
	for(int i = 2;i<=n;i++){
		make_one[i] = make_one[i-1] + 1;
        step[i] = i-1;
		if(i%2 == 0) {
            if(make_one[i] > make_one[i/2]+1){
                make_one[i] = make_one[i/2]+1;
                step[i] = i/2;
            }
        }
		if(i%3 == 0) {
            if(make_one[i] > make_one[i/3]+1){
                make_one[i] = make_one[i/3]+1;
                step[i] = i/3;
            }
        }
	}
    int j = n;
    printf("%d\n",make_one[n]);
    printf("%d ",n);
    while(j!=1){
        printf("%d ",step[j]);
        j = step[j];
    }
	return 0;
}
