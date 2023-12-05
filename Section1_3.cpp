#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int i, n, sum = 0;

	cin >> n;
	cout << "1";
	sum += 1;
	for (i = 2; i < n; i++) {
		if (n%i == 0) {
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum;
}
