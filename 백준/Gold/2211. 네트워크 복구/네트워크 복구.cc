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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B, C;
    vector<pii> V[1111];
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        V[A].push_back({ B,C });
        V[B].push_back({ A,C });
    }

    int visit[1011];
    for (int i = 0; i <= N; i++)
        visit[i] = 10000000;
    vector<int> R[1011];
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({ 0, 1 });
    while (!Q.empty()) {
        int cost = Q.top().first, now = Q.top().second;
        Q.pop();
        if (visit[now] < cost) continue;
        for (auto i : V[now]) {
            vector<int> tmp = R[now];
            int next = i.first, nextCost = i.second;
            if (cost + nextCost < visit[next]) {
                visit[next] = cost + nextCost;
                tmp.push_back(now);
                R[next] = tmp;
                Q.push({ visit[next], next });
            }
        }
    }

    int totalCnt = 0;
    bool result[1011][1011] = { 0, };
    for (int i = 1; i <= N; i++) {
        if (R[i].empty()) continue;
        for (int j = 0; j < R[i].size() - 1; j++) {
            if (!result[R[i][j]][R[i][j + 1]])
                result[R[i][j]][R[i][j + 1]] = true;
        }
        if (!result[R[i].back()][i])
            result[R[i].back()][i] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (result[i][j]) {
                totalCnt++;
                result[j][i] = false;
            }
        }
    }

    cout << totalCnt << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (result[i][j]) {
                cout << i << " " << j << "\n";
                result[j][i] = false;
            }
        }
    }
}