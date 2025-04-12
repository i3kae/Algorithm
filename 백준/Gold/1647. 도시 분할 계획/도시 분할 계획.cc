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
int MAP[100111] = { 0, };
int f(int now) {
    if (!MAP[now] || now == MAP[now]) return now;
    return MAP[now] = f(MAP[now]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B, C, line = 0, totalCost = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii>> Q;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        Q.push({ C, A, B });
    }

    while (line < N - 2) {
        int cost = get<0>(Q.top()), a = get<1>(Q.top()), b = get<2>(Q.top());
        Q.pop();
        int uA = f(a), uB = f(b);
        if (uA == uB) continue;
        if (MAP[uA] == 0)
            MAP[uA] = MAP[uB] = uB;
        else
            MAP[uA] = MAP[uB] = uA;
        line++;
        totalCost += cost;
    }
    cout << totalCost;
}