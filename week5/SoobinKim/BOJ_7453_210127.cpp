#include <iostream>
#include <vector>
#include <algorithm>

#define MAX			4000

using namespace std;

typedef long long ll;

int n;
ll A[MAX], B[MAX], C[MAX], D[MAX];
vector<ll> ab, cd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, idx_ab, idx_cd;
	ll sum, cnt_ab, cnt_cd, ans = 0;

	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		ab.push_back(A[i] + B[i]);
		cd.push_back(C[i] + D[i]);
		for (j = i - 1; j >= 0; --j) {
			ab.push_back(B[i] + A[j]);
			ab.push_back(A[i] + B[j]);
			cd.push_back(C[i] + D[j]);
			cd.push_back(D[i] + C[j]);
		}
	}
	sort(ab.begin(), ab.end()); // ascending order
	sort(cd.begin(), cd.end(), greater<>()); // descending order

	idx_ab = idx_cd = 0;
	while (idx_ab < ab.size() && idx_cd < cd.size()) {
		sum = ab[idx_ab] + cd[idx_cd];
		if (sum < 0) {
			++idx_ab;
		}
		else if (sum > 0) {
			++idx_cd;
		}
		else {
			cnt_ab = cnt_cd = 0;
			while (idx_ab < ab.size() && ab[idx_ab] + cd[idx_cd] == 0) {
				++cnt_ab; ++idx_ab;
			}
			while (idx_cd < cd.size() && ab[idx_ab - 1] + cd[idx_cd] == 0) {
				++cnt_cd; ++idx_cd;
			}
			ans += (cnt_ab * cnt_cd);
		}
	}
	cout << ans;
}
