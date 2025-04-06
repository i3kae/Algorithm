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

    int DP[10011][2] = {0,};

    for (int i = 0; i < 10011; i++) {
        for (int j = 0; j < 2; j++)
            DP[i][j] = 100011;
    }

    char prev = 0;
    string S;
    cin >> S;
    DP[0][0] = 2;
    for (int i = 1; i < S.length(); i++) {
        DP[i][0] = DP[i][1] = min(DP[i - 1][0], DP[i - 1][1]) + 2;
        int check = 1;
        for (int j = i - 1; j >= 0 && S[j] != S[i]; j--)
            check++;
        if (i - check >= 0)
            DP[i][0] = min(DP[i][0], DP[i - check][0] + (check - 1) * 2 + 1);
    }
    cout << min(DP[S.length() - 1][0], DP[S.length() - 1][1]);
}