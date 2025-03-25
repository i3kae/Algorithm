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

string itos(lint N) {
    string S;
    while (N) {
        S.push_back('a' + N % 26);
        N /= 26;
    }
    if (S.size() < 13) {
        while (S.size() < 13)
            S.push_back('a');
    }
    return S;
}

lint stoI(string S) {
    lint N = 0, checker = 1;
    for (int i = 0; i < S.length(); i++) {
        N += checker * (S[i] - 'a');
        checker *= 26;
    }
    return N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    if (T == 1) {
        lint A, B;
        cin >> A >> B;
        cout << itos(A + B);
    }
    else {
        string S;
        cin >> S;
        cout << stoI(S);
    }
}