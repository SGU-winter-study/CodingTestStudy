#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<string> map;
queue<pair<pair<int, int>, pair<int, int>>> q;
queue<string> p;
pair<int, int> red, blue, hole;

pair<int, int> right(int row, int col, char marble) {
	int j = col;
	while (map[row][j + 1] == '.') {
		j++;
	}
	if (map[row][j + 1] == 'O')
		return hole;

	map[row][j] = marble;
	return make_pair(row, j);
}

pair<int, int> left(int row, int col, char marble) {
	int j = col;
	while (map[row][j - 1] == '.') {
		j--;
	}
	if (map[row][j - 1] == 'O')
		return hole;

	map[row][j] = marble;
	return make_pair(row, j);
}

pair<int, int> up(int row, int col, char marble) {
	int i = row;
	while (map[i - 1][col] == '.') {
		i--;
	}
	if (map[i - 1][col] == 'O')
		return hole;

	map[i][col] = marble;
	return make_pair(i, col);
}

pair<int, int> down(int row, int col, char marble) {
	int i = row;
	while (map[i + 1][col] == '.') {
		i++;
	}
	if (map[i + 1][col] == 'O')
		return hole;

	map[i][col] = marble;
	return make_pair(i, col);
}

void map_init(pair<int, int> red_next, pair<int, int> blue_next) {
	map[red_next.first][red_next.second] = '.';
	map[blue_next.first][blue_next.second] = '.';
	map[hole.first][hole.second] = 'O';
}

int go(pair<int, int> red, pair<int, int> blue) {
	pair<pair<int, int>, pair<int, int>> cur;
	pair<int, int> red_next, blue_next;
	int redi, redj, bluei, bluej;
	string path = "";
	bool blue_flag = false;

	q.push(make_pair(red, blue));
	p.push("S");

	while(!q.empty() && path.length() <= 10) {
		blue_flag = false;
		cur = q.front(); q.pop();
		path = p.front(); p.pop();


		redi = cur.first.first; redj = cur.first.second;
		bluei = cur.second.first; bluej = cur.second.second;

		// left
		if (path[path.length() -1] != 'L') {
			map[redi][redj] = '.'; 
			map[bluei][bluej] = '.';
			map[hole.first][hole.second] = 'O';
			if (redi == bluei && redj < bluej) {
				// 파란 구슬이 오른쪽에 있는 경우
				red_next = left(redi, redj, 'R');
				blue_next = left(bluei, bluej, 'B');
			}
			else {
				blue_next = left(bluei, bluej, 'B');
				red_next = left(redi, redj, 'R');
			}
			if (blue_next != hole) {
				if (red_next == hole)
					return path.length();
				q.push(make_pair(red_next, blue_next));
				p.push(path + "L");
			}
			else {
				blue_flag = true;
			}

		}
		// right
		if (path[path.length() - 1] != 'R') {
			map_init(red_next, blue_next);

			if (redi == bluei && redj < bluej) {
				// 파란 구슬이 오른쪽에 있는 경우
				blue_next = right(bluei, bluej, 'B');
				red_next = right(redi, redj, 'R');
			}
			else {
				red_next = right(redi, redj, 'R');
				blue_next = right(bluei, bluej, 'B');
			}
			if (blue_next != hole) {
				if (red_next == hole)
					return path.length();
				q.push(make_pair(red_next, blue_next));
				p.push(path + "R");
			}
			else {
				blue_flag = true;
			}
		}

		// up
		if (path[path.length() - 1] != 'U') {
			map_init(red_next, blue_next);

			if (redj == bluej && redi < bluei) {
				// 파란 구슬이 아래에 있는 경우
				red_next = up(redi, redj, 'R');
				blue_next = up(bluei, bluej, 'B');

			}
			else {
				blue_next = up(bluei, bluej, 'B');
				red_next = up(redi, redj, 'R');
			}
			if (blue_next != hole) {
				if (red_next == hole)
					return path.length();
				q.push(make_pair(red_next, blue_next));
				p.push(path + "U");
			}
			else {
				blue_flag = true;
			}
		}

		// down
		if (path[path.length() - 1] != 'D') {
			map_init(red_next, blue_next);

			if (redj == bluej && redi < bluei) {
				// 파란 구슬이 아래에 있는 경우
				blue_next = down(bluei, bluej, 'B');
				red_next = down(redi, redj, 'R');
			}
			else {
				red_next = down(redi, redj, 'R');
				blue_next = down(bluei, bluej, 'B');
			}
			if (blue_next != hole) {
				if (red_next == hole)
					return path.length();
				q.push(make_pair(red_next, blue_next));
				p.push(path + "D");
			}
			else {
				blue_flag = true;
			}
		}

		map_init(red_next, blue_next);

	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j;
	string tmp;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> tmp;
		map.push_back(tmp);
		for (j = 0; j < M; j++) {
			if (tmp[j] == 'R') {
				red = make_pair(i, j);
				map[i][j] = '.';
			}
			else if (tmp[j] == 'B') {
				blue = make_pair(i, j);
				map[i][j] = '.';
			}
			else if (tmp[j] == 'O') {
				hole = make_pair(i, j);
			}
		}
	}
	cout << go(red, blue);
}
