/*
[문제]
1부터 N까지의 책 페이지에서 0~9의 숫자가 각각 몇 번 나오는지를 계산하는 문제
[풀이]
10^n번째 자릿수에 대하여 해당 자릿수가 m일 때,
(a) 0~9가 각각 (n-1)*m 번 등장하고
(b) 1~m-1이 각각 10^n 번 등장한다는 점을 생각하여
입력받은 N에 대하여 재귀적으로 탐색
[TODO]
1. c++로 다시 풀기
*/

#include <stdio.h>
#include <math.h>

/*
N: 탐색하고자 하는 수
mul: 현재 탐색하고 있는 수가 몇 자리 수인지를 저장하는 변수(10^mul)
result: 0~9 의 등장 횟수를 저장하고 있는 리스트 (i의 개수는 i번째 인덱스에 저장)
*/
void divider(int N, int mul, int result[]) {
	int quotient, remainder, power, i, j;

	if (mul == 0) {
		for (i = 0; i <= N; i++) {
			result[i]++;
		}
		return 0;
	}
	else {
		power = pow(10, mul);
		quotient = N / power;
		remainder = N % power;

		result[quotient] += (remainder + 1);
		for (i = 0; i < quotient; i++) {
			result[i] += power;
		}
		for (i = 0; i < 10; i++) {
			for (j = mul - 1; j >= 0; j--) {
				result[i] += (quotient * pow(10, mul - 1));
			}
		}
	}

	divider(remainder, mul - 1, result);
}

int main() {
	int N, tmpN, mul = 0, i;
	int result[10] = { 0, };
	scanf("%d", &N);			  // N <= 1,000,000,000
	tmpN = N;
	while (tmpN >= 10) {		// N이 몇 자리 수인지 파악 (10^mul 자리 수)
		tmpN /= 10;
		mul++;
	}
	divider(N, mul, result);

	for (i = mul; i >= 0; i--) {
		result[0] -= pow(10, i);
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}
