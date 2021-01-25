#include <iostream>
#include <stack>
#include <vector>
#include <string>

#define MAX 1000000000

typedef long long ll;
using namespace std;
stack<string> cmd_list;

bool max_error(ll x) {
	if (abs(x) > MAX)
		return true;
	return false;
}

bool div_by_zero_error(ll divisor) {
	if (divisor == 0)
		return true;
	return false;
}

pair<bool, ll> go(stack<ll> s, vector<pair<string, ll>> machine) {
	pair<bool, ll> error = make_pair(false, -1);

	ll tmp1, tmp2, result;
	for (pair<string, ll> cmd : machine) {
		if (!cmd.first.compare("NUM")) {
			if (max_error(cmd.second))
				return error;
			else s.push(cmd.second);
		}
		else if (!cmd.first.compare("POP")) {
			if (s.empty())
				return error;
			else s.pop();
		}
		else if (!cmd.first.compare("INV")) {
			if (s.empty())
				return error;
			else {
				tmp1 = s.top(); s.pop();
				s.push(tmp1 * -1);
			}
		}
		else if (!cmd.first.compare("DUP")) {
			if (s.empty())
				return error;
			else {
				tmp1 = s.top();
				s.push(tmp1);
			}
		}
		else {
			if (s.size() < 2)
				return error;

			tmp1 = s.top(); s.pop();
			tmp2 = s.top(); s.pop();

			if (!cmd.first.compare("SWP")) {
				s.push(tmp1); s.push(tmp2);
			}
			else if (!cmd.first.compare("ADD")) {
				if (max_error(tmp1 + tmp2))
					return error;
				s.push(tmp1 + tmp2);
			}
			else if (!cmd.first.compare("SUB")) {
				if (max_error(tmp2 - tmp1))
					return error;
				s.push(tmp2 - tmp1);
			}
			else if (!cmd.first.compare("MUL")) {
				if (max_error(tmp1 * tmp2))
					return error;
				s.push(tmp1 * tmp2);
			}
			else if (!cmd.first.compare("DIV")) {
				if (div_by_zero_error(tmp1))
					return error;

				result = abs(tmp2) / abs(tmp1);
				if (tmp1 * tmp2 < 0) {
					result *= -1;
				}

				if (max_error(result))
					return error;

				s.push(result);
			}
			else if (!cmd.first.compare("MOD")) {
				if (div_by_zero_error(tmp1))
					return error;

				result = abs(tmp2) % abs(tmp1);
				if (tmp2 < 0) {
					result *= -1;
				}

				if (max_error(result))
					return error;

				s.push(result);

			}
		}
	}
	if (s.size() != 1)
		return error;

	return { true, s.top() };
}

int main() {
	int i, j, N;
	ll x, init;
	string cmd;
	pair<bool, ll> tf;
	vector<pair<string, ll>> machine;
	vector<vector<ll>> res;

	while (1) {
		cin >> cmd;
		if (!cmd.compare("QUIT"))
			break;
		else if (!cmd.compare("END")) {
			cin >> N;
			vector<ll> calc;
			for (i = 0; i < N; i++) {
				stack<ll> s;
				cin >> init;
				s.push(init);
				tf = go(s, machine);
				if (!tf.first) {
					calc.push_back(MAX + 1);
				}
				else {
					calc.push_back(tf.second);
				}
			}
			res.push_back(calc);
			machine.clear();
		}
		else {
			if (!cmd.compare("NUM"))
				cin >> x;
			else x = 0;

			machine.push_back(make_pair(cmd, x));
		}
	}

	for (i = 0; i < res.size(); i++) {
		for (j = 0; j < res[i].size(); j++) {
			if (res[i][j] == MAX + 1)
				cout << "ERROR\n";
			else
				cout << res[i][j] << "\n";
		}
		if (i != res.size()-1) cout << "\n";
	}

	return 0;
}
