#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>

using namespace std;
int t, n,core_size;
int ans1=2137000;
int ans2 = 0;
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int map[13][13];
vector<pair<int,int>> core;


void dfs(int c,int c_cnt,int p_cnt) {
	if (c == core_size) {
		if (c_cnt >ans2) {
			ans2 = c_cnt;
			ans1 = p_cnt;
		}
		else if (c_cnt == ans2) {
			if (ans1 > p_cnt) {
				ans1 = p_cnt;
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = core[c].second;
		int ny = core[c].first;
		bool flag = false;
		vector<pair<int, int>> check;

		while (true) {
			if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) {
				flag=true;
				break;
			}
			nx = nx + dx[i];
			ny = ny + dy[i];

			if (map[ny][nx] == 0) 
				check.push_back(make_pair(ny, nx));
			else break;

		}
		if (flag) {
			for (int j = 0; j < check.size(); j++) {
				map[check[j].first][check[j].second] = 2;

				dfs(c + 1, c_cnt + 1, p_cnt + check.size());
				map[check[j].first][check[j].second] = 0;
			}	
		}
	}
	dfs(c + 1, c_cnt, p_cnt);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n;
		memset(map, 0, sizeof(map));
		core.clear();
		ans1 = 2147000;
		ans2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i == 0 || j == 0 || i == n - 1 || j == n - 1)continue;
					core.push_back(make_pair(i, j));
				}
			}
		}
		core_size = core.size();
		dfs(0, 0, 0);
		cout << "#" << test << " " << ans1 << endl;
	}
}
