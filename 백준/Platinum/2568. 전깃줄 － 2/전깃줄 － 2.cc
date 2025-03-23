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

bool comp(pii& a, int b) {
    return a.first > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    vector<pii> V;
    vector<int> v;
    vector<pii> capture[500001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        V.push_back({ A, B });
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < N; i++) {
        int idx = upper_bound(v.begin(), v.end(), V[i].second) - v.begin();
        if (v.empty())
            v.push_back(V[i].second);
        else if (idx == v.size())
            v.push_back(V[i].second);
        else
            v[idx] = V[i].second;
        if (idx > 0)
            capture[idx].push_back({ V[i].second, v[idx - 1]});
        else
            capture[idx].push_back({ V[i].second, 0});
    }

    bool vst[500001] = { 0, };
    int now = v.back();
    for (int i = v.size() - 1; i >= 0; i--) {
        vst[now] = true;
        int idx = lower_bound(capture[i].begin(), capture[i].end(), now, comp) - capture[i].begin();
        now = capture[i][idx].second;
    }

    cout << N - v.size() << "\n";
    for (int i = 0; i < N; i++) {
        if (!vst[V[i].second])
            cout << V[i].first << "\n";
    }
}