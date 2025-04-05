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

    int N, A;
    cin >> N;
    vector<int> result;
    vector<int> V;
    for (int i = 0; i < N; i++) {
        cin >> A;
        V.push_back(A);
    }

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(result.begin(), result.end(), V[i]) - result.begin();
        if (idx == result.size())
            result.push_back(V[i]);
        else
            result[idx] = V[i];
    }
    cout << result.size();
}