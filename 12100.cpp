#include <iostream>
#include <queue>
#include <stdlib.h>
#include<string.h>

using namespace std;

int N;
vector<vector<int>>board(21, vector<int>(21, 0));
int max_val;

void move(int num) {
	queue<int> q;
	int i, j;
	switch (num) {
	case 0:
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (board[i][j]) { q.push(board[i][j]); }
				board[i][j]=0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0)board[i][idx] = data;
				else if (board[i][idx] == data) { board[i][idx] *= 2; idx++; }
				else { idx++; board[i][idx] = data; }
			}
		}
		break;
	case 1:
		for (i = 0; i < N; i++) {
			for (j = N-1; j >=0; j--) {
				if (board[i][j]) { q.push(board[i][j]); }
				board[i][j]=0;
			}
			int idx = N-1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0)board[i][idx] = data;
				else if (board[i][idx] == data) { board[i][idx] *= 2; idx--; }
				else { idx--; board[i][idx] = data; }
			}
		}
		break;
	case 2:
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (board[j][i]) { q.push(board[j][i]); }
				board[j][i] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][i] == 0)board[idx][i] = data;
				else if (board[idx][i] == data) { board[idx][i] *= 2; idx++; }
				else { idx++; board[idx][i] = data; }
			}
		}
		break;
	case 3:
		for (i = 0; i < N; i++) {
			for (j = N-1; j>=0; j--) {
				if (board[j][i]) { q.push(board[j][i]); }
				board[j][i] = 0;
			}
			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][i] == 0)board[idx][i] = data;
				else if (board[idx][i] == data) { board[idx][i] *= 2; idx--; }
				else { idx--; board[idx][i] = data; }
			}
		}
		break;
	}


	
}



void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_val = max(max_val, board[i][j]);
			}
		}
		return;
	}
	vector<vector<int>>temp = board;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			move(i);
			DFS(cnt + 1);
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					board[i][j] = temp[i][j];
				}
			}
		}
	
}

void Answer() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	DFS(0);
	cout << max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Answer();
	return 0;
}