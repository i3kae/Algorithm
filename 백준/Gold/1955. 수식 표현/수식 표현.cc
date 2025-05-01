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

int f(int N) {
    lint result = 1;
    for (int i = 1; i <= N; i++) {
        result *= i;
        if (result > 10000)
            return -1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int DP[10111] = { 0, 1, };
    for (int i = 2; i < 10111; i++)
        DP[i] = 10000000;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        DP[i] = min(DP[i], DP[i - 1] + 1);
        for (int j = 1; j < i; j++) {
            DP[i] = min(DP[i], DP[j] + DP[i - j]);
            if (i % j == 0)
                DP[i] = min(DP[i], DP[j] + DP[i / j]);
        }
        int checker = f(i);
        if (checker != -1)
            DP[checker] = DP[i];
    }

    cout << DP[N];
}