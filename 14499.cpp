#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;
int n, m, x, y, k;
int map[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int dice[7] = { 0 };
vector<int> cmd;
void input() {
	int i_c;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < k; i++) {
		cin >> i_c;
		cmd.push_back(i_c-1);
	}


}
void Roll_Dice(int dir) {
	int d1, d2, d3, d4, d5, d6;
	d1 = dice[1],d2=dice[2],d3=dice[3],d4=dice[4],d5=dice[5],d6=dice[6];

	if (dir == 0) {
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	else if (dir == 1) {
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}
	else if (dir == 2) {
		dice[1] = d5;
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
	}
	else if (dir == 3) {
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
	}
}
void solve() {
	int sx = x;
	int sy = y;

	for (int i = 0; i < cmd.size(); i++) {
		int nx = sx + dx[cmd[i]];
		int ny = sy + dy[cmd[i]];
		int dir = cmd[i];

		if (nx < 0 || ny<0 || nx >= n || ny>=m)continue;
		Roll_Dice(dir);
		if (map[nx][ny] == 0)map[nx][ny] = dice[6];
		else {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1]<<endl;
		sx = nx; sy = ny;
	}
}

void Answer() {
	input();
	solve();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Answer();
	return 0;

}