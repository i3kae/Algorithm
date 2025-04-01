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

int visit[4000444] = { 0, };

int unionF(int n) {
    if (visit[n] == 0 || visit[n] == n)
        return n;
    return unionF(visit[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, N, M, K;
    vector<int> V;
    cin >> N >> M >> K;
    for (int i = 0; i <= M; i++)
        visit[i] = i;
    for (int i = 0; i < M; i++) {
        cin >> A;
        V.push_back(A);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < K; i++) {
        cin >> A;
        int idx = unionF(upper_bound(V.begin(), V.end(), A) - V.begin());
        if (idx < M - 1) {
            int next = unionF(idx + 1);
            visit[idx] = next;
        }
        cout << V[idx] << "\n";
    }
}