#include<iostream>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;

int N, K, L;
int col, row;
int board[102][102] = { 0, };
bool visit[102][102] = { false, };
//vector<vector<int>>board(102, vector<int>(102, 0));
//vector<vector<bool>>visit(102, vector<bool>(102, false));
int move() {
	queue<pair<int,int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x = 0;
	int y = 0;
	int detection = 0;
	int sec=0;
	char rotate=0;
	int cnt = 0;;

	cin >> L;
	q.push(make_pair(x, y));
	for (int i = 0; i < L; i++) {
		cin >> sec >> rotate;
		
		while (cnt < sec || i == L - 1) {
			int nx = x + dx[detection];
			int ny = y + dy[detection];
			cnt++;
			//cout << nx << ny << "\n";
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[ny][nx]) {
				if (board[ny][nx] == 1) {
					board[ny][nx] = 0;
					visit[ny][nx] = true;
					q.push(make_pair(nx, ny));
				}
				else {
					q.push(make_pair(nx, ny));
					visit[q.front().second][q.front().first] = false;
					visit[ny][nx] = true;
					q.pop();
				}
			}
			else {
				return cnt;
			}

			x = nx;
			y = ny;
			if (cnt == sec) {
				if (rotate == 'D') {
					detection = (detection + 1) % 4;
				}
				else {
					detection = (detection + 3) % 4;
				}
			}
		}
	}
	return cnt;
}

void Answer() {
	int res;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> col >> row;
		board[col-1][row-1] = 1;
	}
	
	res=move();
	cout << res;
}

int main() {
	
	Answer();

	return 0;
}


