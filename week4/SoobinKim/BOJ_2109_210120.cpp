#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef pair<int, int> info;
priority_queue<info, vector<info>, greater<info>> result;

auto second = [](info left, info right)
{
	return left.second > right.second;
};
priority_queue<info, vector<info>, decltype(second)> lectures(second);

int main() {
	int i, d, p, money = 0;
	info tmp;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> p >> d;
		lectures.push(make_pair(p, d));
	}

	// greedy
	while (!lectures.empty()) {
		tmp = lectures.top(); lectures.pop();
		result.push(tmp);
		money += tmp.first;
		if (result.size() > tmp.second) {
			money -= result.top().first;
			result.pop();
		}
	}


	cout << money;
}
