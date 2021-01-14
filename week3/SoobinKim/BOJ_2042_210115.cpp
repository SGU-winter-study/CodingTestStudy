#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define DUMMY 0

using namespace std;

int N, M, K;
vector<long long int> arr;
long long int *st;

int middle(int start, int end) {
	return (start + end) / 2;
}

int lchild(int parent) {
	return parent * 2 + 1;
}

int rchild(int parent) {
	return parent * 2 + 2;
}

int parent(int child) {
	if (child % 2 == 0) {
		return (child - 2) / 2;
	}
	else {
		return (child - 1) / 2;
	}
}

void init() {
	// allocate memory
	int size = (int)((pow(2, ceil(log2(N))) * 2) - 1);
	st = new long long int[size];
	fill(st, st + size, DUMMY);
}

long long int make_tree(int idx, int start, int end) {
	if (start == end) {
		st[idx] = arr[start];
	}
	else {
		st[idx] = make_tree(lchild(idx), start, middle(start, end)) + \
			make_tree(rchild(idx), middle(start, end) + 1, end);
	}
	return st[idx];
}

void update(int idx, int target, long long int diff, int start, int end) {
	if (target < start || end < target)
		return;
	else {
		st[idx] += diff;
		if (start != end) {
			update(lchild(idx), target, diff, start, middle(start, end));
			update(rchild(idx), target, diff, middle(start, end) + 1, end);
		}
	}
}

long long int get_sum(int idx, int target_start, int target_end, int cur_start, int cur_end) {
	if (target_start <= cur_start && cur_end <= target_end) {
		return st[idx];
	}
	else if (cur_end < target_start || target_end < cur_start) {
		return 0;
	}
	else {
		return get_sum(lchild(idx), target_start, target_end, cur_start, middle(cur_start, cur_end)) \
			+ get_sum(rchild(idx), target_start, target_end, middle(cur_start, cur_end) + 1, cur_end);
	}

}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int i, code, x;
	long long int y;
	long long int tmp;
	
	cin >> N >> M >> K;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	init(); 	
	make_tree(0, 0, N - 1);

	for (i = 0; i < M + K; i++) {
		cin >> code >> x >> y;
		switch (code) {
		case 1:
			update(0, x - 1, y - arr[x - 1], 0, N - 1);
			arr[x - 1] = y;
			break;
		case 2:
			cout << get_sum(0, x - 1, (int)y - 1, 0, N - 1) << "\n";
			break;
		}
	}

}
