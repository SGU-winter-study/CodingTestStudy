#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define YEAR 365

using namespace std;

int N, start_date, end_date;
bool days[YEAR];
vector<pair<int, int>> flowers;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, month, day, bloom, fall, today, max, cnt = 0;
	cin >> N;
	start_date = 301;
	end_date = 1130;

	for (i = 0; i < N; i++) {
		cin >> month >> day;
		bloom = month * 100 + day;
		cin >> month >> day;
		fall = month * 100 + day;
		flowers.push_back(make_pair(bloom, fall));
	}
	sort(flowers.begin(), flowers.end());

	today = start_date;
	pair<int, int> plant;
	while (today <= end_date) {
		max = 0;
		for (i = 0; i < flowers.size(); i++) {
			if (flowers[i].first <= today && max < flowers[i].second - today) {
				plant = flowers[i];
				max = flowers[i].second - today;
			}
		}
		if (max == 0) {
			cnt = 0;
			break;
		}
		today = plant.second;
		cnt++;
	}

	cout << cnt;

}
