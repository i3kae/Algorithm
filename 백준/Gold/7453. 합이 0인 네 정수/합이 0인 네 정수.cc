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

    int N, a, b, c, d;
    vector<lint> A, B, C, D;
    vector<lint> AB, CD;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            AB.push_back(A[i] + B[j]);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            CD.push_back(C[i] + D[j]);
    }

    sort(CD.begin(), CD.end());

    lint totalCnt = 0;
    for (int i = 0; i < N * N; i++) {
        int idx1 = lower_bound(CD.begin(), CD.end(), AB[i] * -1) - CD.begin();
        int idx2 = upper_bound(CD.begin(), CD.end(), AB[i] * -1) - CD.begin();
        if (idx1 < CD.size() && AB[i] * -1 == CD[idx1])
            totalCnt += (idx2 - idx1);
    }
    cout << totalCnt;
}