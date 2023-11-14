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
vector<ROCK> rock;
int map[9][9];
int dx[] = { 1,-1,0,0 ,1,-1};
int dy[] = { 0,0,1,-1 ,1,-1};
void solve() {
	int x,y,nx, ny;
	memset(solve, 0, sizeof(map));
	
	for (int i = 0; i < rock.size(); i++) {
		x = rock[i].x; y = rock[i].y;
		map[y][x] = rock[i].kind;
		for (int j = 0; j < 6; j++) {
			nx = x + dx[j];
			ny = y + dy[j];
			if(map[y][x]==map[ny][nx] &&)
		}
	}
}

void input() {
	int x, y, color;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> color;
		rock.push_back({ x,y,color });
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		input();
		
	}
	return 0;
}