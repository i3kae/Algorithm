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

int N, M;
int A, B, C, NO[11];
vector<tiii> edge;
int totalMin = L_MAX;
vector<int> result;
bool vst[11];

int unionF(int A, int checker[11]) {
    if (checker[A] == A || checker[A] == 0)
        return A;
    return unionF(checker[A], checker);
}

void check(vector<int> V) {
    int checker[11] = { 0, };
    int count[11] = { 0, };
    for (int i = 0; i < N - 1; i++) {
        int nodeA = get<0>(edge[V[i]]), nodeB = get<1>(edge[V[i]]);
        int A = unionF(nodeA, checker), B = unionF(nodeB, checker);
        if (A == B) return;
        count[nodeA]++;
        count[nodeB]++;
        if (NO[nodeA] < count[nodeA] || NO[nodeB] < count[nodeB])
            return;
        checker[A] = checker[B] = A;
    }
    int total = 0;
    for (int i = 0; i < N - 1; i++)
        total += get<2>(edge[V[i]]);
    if (total < totalMin) {
        totalMin = total;
        result = V;
    }
}

void f(vector<int> V, int now) {
    if (V.size() == N - 1) {
        check(V);
        return;
    }
    for (int i = now; i < M; i++) {
        V.push_back(i);
        f(V, i + 1);
        V.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> V;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> NO[i];
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edge.push_back(make_tuple(A, B, C));
    }
    f(V, 0);
    if (totalMin == L_MAX)
        cout << "NO";
    else {
        cout << "YES\n";
        for (auto i : result)
            cout << get<0>(edge[i]) << " " << get<1>(edge[i]) << "\n";
    }
}