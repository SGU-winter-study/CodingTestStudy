#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int A[501];
vector<int> vec, len1;

int MAX(int a, int b) { return a > b ? a : b; }

void go_ascend() {
	int max;
	for (int i = 0; i < vec.size(); i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i] && len1[j] > max) {
				max = len1[j];
			}
		}
		len1[i] = max + 1;
	}
}

int main() {
	int a, b, i;
	cin >> N;
	fill(A, A + 501, -1);
	for (i = 1; i <= N; i++) {
		cin >> a >> b;
		A[a] = b;
	}
	for (i = 1; i <= 500; i++) {
		if (A[i] != -1) {
			vec.push_back(A[i]);
			len1.push_back(1);
		}
	}

	go_ascend();

	int max1 = 0;
	for (i = 0; i < len1.size(); i++) {
		if (max1 < len1[i]) max1 = len1[i];
	}

	cout << N - max1;

}
