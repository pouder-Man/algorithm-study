#include <iostream>

using namespace std;

int D[101][10] = {0};
int main()
{
	int n;
	cin >> n;
	long nanu = 1000000000;
	D[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			
			if (j == 0) {
				D[i][j] = D[i - 1][j + 1];
			}
			else if (j == 9) {
				D[i][j] = D[i - 1][j - 1];
			}
			else {
				D[i][j] = D[i-1][j - 1] + D[i-1][j + 1];
			}
			D[i][j] %= nanu;
		}
	}
	long hap=0;
	for (int i = 0; i <= 9; i++) {
		hap += D[n][i];
	}
	cout << hap%nanu << endl;

}

