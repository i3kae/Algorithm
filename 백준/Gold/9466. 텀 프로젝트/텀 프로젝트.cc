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

int T, arr[100111];

int f(int now, int visit[100111], int loop) {
    visit[now] = loop;
    if (visit[arr[now]] && visit[arr[now]] != loop) return -1;
    if (visit[arr[now]] == loop) return arr[now];
    return f(arr[now], visit, loop);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        int visit[100111] = { 0, };
        int checker[100111] = { 0, };
        for (int i = 1; i <= N; i++) {
            if (visit[i]) continue;
            int cycle = f(i, visit, i);
            if (cycle != -1)
                f(cycle, checker, i);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++)
            cnt += !checker[i];
        cout << cnt << "\n";
    }
}