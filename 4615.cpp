/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
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