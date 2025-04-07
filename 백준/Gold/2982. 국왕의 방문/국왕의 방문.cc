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
#define INF 100000000
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

    int N, M, A, B, K, G, a, b, c;
    int KING[1011];
    int MAP[1011][1011] = { 0, };
    int T[1011][1011] = { 0, };
    cin >> N >> M;
    cin >> A >> B >> K >> G;
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < N + 1; j++)
            MAP[i][j] = T[i][j] = INF;
    for (int i = 0; i < G; i++)
        cin >> KING[i];
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        MAP[a][b] = c;
        MAP[b][a] = c;
    }
    int startTime = 0;
    for (int i = 0; i < G - 1; i++) {
        T[KING[i]][KING[i + 1]] = T[KING[i + 1]][KING[i]] = startTime;
        startTime += MAP[KING[i]][KING[i + 1]];
    }

    bool visit[1011] = { 0, };
    int result[1011] = { 0, };
    for (int i = 1; i <= N; i++)
        result[i] = INF;
    result[A] = K;
    for (int i = 0; i < N; i++) {
        int idx = -1;
        for (int j = 1; j <= N; j++)
            if (!visit[j] && (idx == -1 || result[j] < result[idx]))
                idx = j;
        visit[idx] = true;
        for (int j = 1; j <= N; j++) {
            if (result[idx] < T[idx][j])
                result[j] = min(result[idx] + MAP[idx][j], result[j]);
            else
                result[j] = min(result[j], max(T[idx][j] + MAP[idx][j], result[idx]) + MAP[idx][j]);
        }
    }

    cout << result[B] - K;
}