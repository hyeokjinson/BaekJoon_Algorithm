#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int N;
//int **map;
//int** C_map;

int C_map[21][21];
int max_val;

void move(int num) {
	queue<int> q;

	switch (num) {
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (C_map[i][j]) {
					q.push(C_map[i][j]);
				}
				C_map[i][j] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (C_map[i][idx] == 0) { C_map[i][idx] = data; }
				else if (C_map[i][idx] == data) { C_map[i][idx] *= 2; idx++; }
				else {
					idx++;
					C_map[i][idx] = data;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j>=0; j--) {
				if (C_map[i][j]) {
					q.push(C_map[i][j]);
				}
				C_map[i][j] = 0;
			}
			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (C_map[i][idx] == 0) C_map[i][idx] = data;
				else if (C_map[i][idx] == data) { C_map[i][idx] *= 2; idx--; }
				else {
					idx--;
					C_map[i][idx] = data;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (C_map[j][i]) {
					q.push(C_map[j][i]);
				}
				C_map[j][i] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (C_map[idx][i] == 0) C_map[idx][i] = data;
				else if (C_map[idx][i] == data) { C_map[idx][i] *= 2; idx++; }
				else {
					idx++;
					C_map[idx][i] = data;
				}
			}
		}
		break;

	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j>=0; j--) {
				if (C_map[j][i]) {
					q.push(C_map[j][i]);
				}
				C_map[j][i] = 0;
			}
			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (C_map[idx][i] == 0) C_map[idx][i] = data;
				else if (C_map[idx][i] == data) { C_map[idx][i] *= 2; idx--; }
				else {
					idx--;
					C_map[idx][i] = data;
				}
			}
		}
		break;

	}
	
}

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_val = max(max_val, C_map[i][j]);
				return;
			}
		}
	}
	int map[21][21];

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			map[i][j] = C_map[i][j];

	for (int i = 0; i < 4; i++) {
		move(i);
		DFS(cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				C_map[i][j] = map[i][j];
			}
		}
	}
}

void Answer() {
	cin >> N;
	/*map = (int**)malloc(sizeof(int*) * N);
	memset(map, 0, sizeof(int*) * N);
	C_map = (int**)malloc(sizeof(int*) * N);
	memset(C_map, 0, sizeof(int*) * N);
	*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			/*map[i] = (int*)malloc(sizeof(int) * N);
			memset(map[i], 0, sizeof(int) * N);
			C_map[i] = (int*)malloc(sizeof(int) * N);
			memset(C_map[i], 0, sizeof(int) * N);
			*/
			cin >> C_map[i][j];
		}
	}
	DFS(0);
	cout << max_val << endl;
	//free(map);
	//free(C_map);
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}