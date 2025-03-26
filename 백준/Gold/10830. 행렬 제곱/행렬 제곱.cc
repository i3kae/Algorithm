#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#include <stack>

#define L_MIN	(-2147483647L - 1)
#define L_MAX	2147483647L
#define UL_MAX	0xffffffffUL
#define LL_MAX	9223372036854775807
#define LL_MIN	(-9223372036854775807 - 1)
#define ULL_MAX 0xffffffffffffffffu
#define DIVIDE 1000000007
#define lint long long int
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define pii pair<int, int>
#define plii pair<lint, lint>

using namespace std;

lint N, B;
lint m[5][5];

void MS(lint M, lint matrix[5][5]) {
	lint mat[5][5] = { 0, };
	if (M == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				matrix[i][j] = m[i][j];
		}
		return;
	}
	MS(M / 2, mat);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int a = 0; a < N; a++) {
				matrix[i][j] += mat[i][a] * mat[a][j];
				matrix[i][j] %= 1000;
			}
		}
	}
	if (M % 2) {
		lint mm[5][5] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int a = 0; a < N; a++) {
					mm[i][j] += matrix[i][a] * m[a][j];
					mm[i][j] %= 1000;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				matrix[i][j] = mm[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lint MAP[5][5] = { 0, };
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> m[i][j];
	MS(B, MAP);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << MAP[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}
