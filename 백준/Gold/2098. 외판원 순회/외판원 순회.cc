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

int DP[16][0b10000000000000000];
int MAP[16][16];
int N;
int totalMin = L_MAX;

int f(int now, int route) {
    if (route == ((1 << N) - 1)) {
        if (!MAP[now][0])
            return -1;
        DP[now][route] = MAP[now][0];
        return MAP[now][0];
    }

    if (DP[now][route]) {
        return DP[now][route];
    }

    for (int i = 1; i < N; i++) {
        if (MAP[now][i] && !(route & (1 << i)) && DP[now][(route | (1 << i))] != -1) {
            int next = f(i, route | (1 << i));
            if (next != -1) {
                if (DP[now][route])
                    DP[now][route] = min(DP[now][route], next + MAP[now][i]);
                else
                    DP[now][route] = next + MAP[now][i];
            }
        }
    }
    if (DP[now][route])
        return DP[now][route];
    DP[now][route] = -1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    }
    cout << f(0, 1);
}