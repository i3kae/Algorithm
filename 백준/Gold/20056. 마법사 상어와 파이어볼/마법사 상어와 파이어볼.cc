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

int N, M, K;
int r, c, m, s, d;
int mover[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
vector<tuple<int, int, int, int, int>> V;

void f() {
    vector<tiii> MAP[55][55];
    vector<tuple<int, int, int, int, int>> nextV;
    for (int i = 0; i < V.size(); i++) {
        int y = get<0>(V[i]), x = get<1>(V[i]), m = get<2>(V[i]), s = get<3>(V[i]), d = get<4>(V[i]);
        int nextY = (y + mover[d][0] * s + N * 1000000) % N, nextX = (x + mover[d][1] * s + N * 1000000) % N;
        MAP[nextY][nextX].push_back(make_tuple(m, s, d));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[i][j].empty()) continue;
            if (MAP[i][j].size() == 1) {
                int m = get<0>(MAP[i][j][0]), s = get<1>(MAP[i][j][0]),d  = get<2>(MAP[i][j][0]);
                nextV.push_back(make_tuple(i, j, m, s, d));
            }
            else if (MAP[i][j].size() > 1) {
                int totalM = 0, totalD = 0, totalS = 0;
                for (int k = 0; k < MAP[i][j].size(); k++) {
                    int m = get<0>(MAP[i][j][k]), s = get<1>(MAP[i][j][k]), d = get<2>(MAP[i][j][k]);
                    totalM += m;
                    totalS += s;
                    totalD += d % 2;
                }
                totalM /= 5;
                totalS /= MAP[i][j].size();
                if (totalM == 0)
                    continue;
                if (totalD == 0 || totalD == MAP[i][j].size())
                    totalD = 0;
                else
                    totalD = 1;
                for (int k = totalD; k < 8; k += 2)
                    nextV.push_back(make_tuple(i, j, totalM, totalS, k));
            }
        }
    }
    V = nextV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        V.push_back(make_tuple(r - 1, c - 1, m, s, d));
    }

    for (int i = 0; i < K; i++)
        f();
    int totalM = 0;
    for (int i = 0; i < V.size(); i++)
        totalM += get<2>(V[i]);
    cout << totalM;
}