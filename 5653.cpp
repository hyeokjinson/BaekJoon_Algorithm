#include<iostream>
#include <vector>
#include<queue>
using namespace std;
int map[350][350];
int n, m,k;
int res = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct cell {
	int x, y;
	int life;
	int life2;
};

vector<cell> cells;

void input() {
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			map[150 + i][150 + j] = a;
			if (a != 0)cells.push_back({ 150 + i,150 + j,a,a });
		}
	}
	
}
void solve() {
	int dead = 0;
	int len = cells.size();

	while (k > 0) {
		k--;

	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m >> k;
		input();
		solve();
	}
	return 0;
}