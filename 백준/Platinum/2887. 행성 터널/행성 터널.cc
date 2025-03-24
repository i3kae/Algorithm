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

int M[100111];

int findParent(int now) {
    if (M[now] == now || M[now] == 0)
        return now;
    return M[now] = findParent(M[now]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b, c;
    int line = 0;
    int totalCost = 0;
    vector<pii> A, B, C;
    priority_queue<tiii, vector<tiii>, greater<tiii>> Q;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        A.push_back({ a, i + 1 });
        B.push_back({ b, i + 1 });
        C.push_back({ c, i + 1 });
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    if (N == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < N; i++) {
        Q.push({ abs(A[i - 1].first - A[i].first), A[i - 1].second, A[i].second });
        Q.push({ abs(B[i - 1].first - B[i].first), B[i - 1].second, B[i].second });
        Q.push({ abs(C[i - 1].first - C[i].first), C[i - 1].second, C[i].second });
    }

    while (line < N - 1) {
        int cost = get<0>(Q.top()), S = findParent(get<1>(Q.top())), E = findParent(get<2>(Q.top()));
        Q.pop();
        if (S == E)
            continue;
        M[S] = M[E] = S;
        line++;
        totalCost += cost;
    }
    cout << totalCost;
}