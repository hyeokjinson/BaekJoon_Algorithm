#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct ball {
	int Rx, Ry;
	int Bx, By;
	int Count;
};

char map[11][11];
bool visit[11][11][11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;

void move(int& rx, int& ry, int& distance, int& i) {
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O') {
		rx = rx + dx[i];
		ry = ry + dy[i];
		distance+=1;
	}
}

void BFS(int Rx, int Ry, int Bx, int By) {
	queue<ball> q;

	q.push({ Rx,Ry,Bx,By,0 });
	visit[Rx][Ry][Bx][By] = true;

	while (!q.empty()) {
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().Count;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by, ncount = count + 1;
			int nrc = 0, nbc = 0;
			if (ncount > 10)break;
			move(nrx, nry, nrc, i);
			move(nbx, nby, nbc, i);

			if (map[nbx][nby] == 'O')continue;

			else if (map[nrx][nry] == 'O') {
				cout << ncount;
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (nrc > nbc) {
					nrx -= dx[i], nry -= dy[i];
				}
				else {
					nbx -= dx[i], nby -= dy[i];
				}
			}
			if (visit[nrx][nry][nbx][nby])continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });

		}

	}
	cout << -1;
}

void Answer() {
	int Rx = 0, Ry = 0, Bx = 0, By = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				Rx = i; Ry = j;
			}
			else if (map[i][j] == 'B') {
				Bx = i; By = j;
			}
		}
	}

	BFS(Rx, Ry, Bx, By);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}