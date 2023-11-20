/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
using namespace std;

struct ROCK {
	int x, y;
	int kind;
};
int n, m;
int black = 0;
int white=0;
vector<ROCK> rock;
int map[10][10];
//int dx[8] = { 1,-1,0,0,-1,1,-1,1};
//int dy[8] = { 0,0,1,-1,-1,0,1,1};

int dy[8] = { 0,0,1,1,1,-1,-1,-1 };
int dx[8] = { 1,-1,0,1,-1,0,1,-1 };


void setmap(int sy, int sx, int ey, int ex, int stone, int dir) {
	int y = sy;
	int x = sx;
	while (true) {
		if (y == ey && x == ex)break;
		map[y][x] = stone;
		y += dy[dir]; x += dx[dir];
	}
}

void solve(int y,int x,int kind) {
	int nx;
	int ny;
	
		
	for (int j = 0; j < 8; j++) {
			
		nx = x + dx[j];
		ny = y + dy[j];
		if (ny<1 || nx<1 || ny>n || nx>n)continue;
		if (map[ny][nx] == 0 || map[ny][nx] == kind)continue;

		while (1) {
			ny += dy[j]; nx += dx[j];
			if (ny<1 || nx<1 || ny>n || nx>n)break;
			if (map[ny][nx] ==0)break;
			if (map[ny][nx] == kind) {
				setmap(y, x, ny, nx, kind, j);
				break;
				}
			}
		}
	
}
void init() {
	int y = n / 2;
	int x = n / 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	}

	map[n / 2][n / 2] = 2;
	map[(n / 2) + 1][(n / 2) + 1] = 2;
	map[(n / 2) + 1][n / 2] = 1;
	map[n / 2][(n / 2) + 1] = 1;
}
void input() {
	int x, y, color;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> color;
		//rock.push_back({ x,y,color });
		map[y][x] = color;
		solve(y,x,color);
	}
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> n >> m;
		black = 0; white = 0;
		init();
		input();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 1) { black++; }
				if (map[i][j] == 2) { white++; }
			}
		}
		cout << "#" << test_case << " " << black << " " << white<<endl;
	}
	return 0;
}