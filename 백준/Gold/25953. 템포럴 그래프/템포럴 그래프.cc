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

int N, T, M;
int S, E;
int A, B, C;
int graph[10001];

void f(vector<pii> V[10001]) {
    int newGraph[10001];

    for (int i = 0; i < N; i++)
        newGraph[i] = graph[i];

    vector<int> node;
    for (int i = 0; i < N; i++)
        if (graph[i] != -1)
            node.push_back(i);

    for (int n : node) {
        for (int i = 0; i < V[n].size(); i++) {
            int next = V[n][i].first, cost = V[n][i].second;
            if (graph[next] == -1 || graph[n] + cost < graph[next])
                newGraph[next] = graph[n] + cost;
        }
    }

    for (int i = 0; i < N; i++)
        graph[i] = newGraph[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T >> M;
    cin >> S >> E;

    for (int i = 0; i < N; i++)
        graph[i] = -1;

    graph[S] = 0;
    for (int i = 0; i < T; i++) {
        vector<pii> V[10001];
        for (int j = 0; j < M; j++) {
            cin >> A >> B >> C;
            V[A].push_back({ B, C });
            V[B].push_back({ A, C });
        }
        f(V);
    }

    if (graph[E] != -1)
        cout << graph[E];
    else
        cout << -1;
}