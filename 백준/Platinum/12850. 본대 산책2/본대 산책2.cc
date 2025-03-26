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
#include <string>
#include <stdlib.h>

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
#define tliii tuple<lint, lint, lint>
#define pii pair<int, int>
#define plii pair<lint, lint>

using namespace std;

void MULTI(lint A[8][8], lint B[8][8]) {
	lint newMap[8][8] = { 0, };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				newMap[i][j] = (newMap[i][j] + A[i][k] * B[k][j]) % DIVIDE;
			}
		}
	}
	memcpy(A, newMap, sizeof(newMap));
}

void f(int N, lint MAP[8][8]) {
	if (N == 1)
		return;
	lint newMap[8][8] = { 0, };
	lint prevMap[8][8] = { 0, };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			prevMap[i][j] = MAP[i][j];
	}
	f(N / 2, MAP);
	MULTI(MAP, MAP);
	if (N % 2)
		MULTI(MAP, prevMap);
}


int main() {
	lint N;
	lint MAP[8][8] = {
		0,1,1,0,0,0,0,0,
		1,0,1,1,0,0,0,0,
		1,1,0,1,1,0,0,0,
		0,1,1,0,1,1,0,0,
		0,0,1,1,0,1,1,0,
		0,0,0,1,1,0,0,1,
		0,0,0,0,1,0,0,1,
		0,0,0,0,0,1,1,0
	};
	cin >> N;
	f(N, MAP);
	cout << MAP[0][0];
}