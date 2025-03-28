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

lint checker(lint N) {
    lint result = N;
    while (N) {
        result += N % 10;
        N /= 10;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lint N, n;
    cin >> N;
    n = N;

    if (N <= 10000) {
        for (int i = 0; i <= N; i++) {
            if (checker(i) == N) {
                cout << i;
                return 0;
            }
        }
    }
    else {
        for (lint i = N - 10000; i <= N; i++) {
            if (checker(i) == N) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;
}