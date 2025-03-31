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

vector<tiii> graph;
int N, M, A, B, C;
int total = 0;
vector<int> origin;

vector<int> swapV(int l, int r, vector<int> V) {
    swap(V[l], V[r]);
    return V;
}

bool isSorted(vector<int> V) {
    for (int i = 0; i < V.size() - 1; i++) {
        if (V[i] > V[i + 1])
            return false;
    }
    return true;
}

int f() {
    map<vector<int>, int> visit;
    priority_queue<pair<int, vector<int>> , vector<pair<int, vector<int>> >, greater<pair<int, vector<int>> >> Q;
    Q.push({0, origin});
    while (!Q.empty()) {
        int cost = Q.top().first;
        vector<int> now = Q.top().second;
        Q.pop();
        if (visit.find(now) != visit.end()) continue;
        if (isSorted(now)) return cost;
        visit[now] = cost;
        for (int i = 0; i < M; i++) {
            int a = get<0>(graph[i]), b = get<1>(graph[i]), nextCost = get<2>(graph[i]);
            vector<int> nextV = swapV(a, b, now);
            if (visit.find(nextV) == visit.end())
                Q.push({ cost + nextCost, nextV });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        origin.push_back(A);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        graph.push_back(make_tuple(A - 1, B - 1, C));
    }

    cout << f();
}