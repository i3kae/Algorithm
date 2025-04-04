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

typedef struct node {
    int N = -1;
    struct node *LN = NULL;
    struct node*RN = NULL;
} NODE;

vector<int> I, P;
NODE result;

int N;

void f(int iA, int iB, int pA, int pB, NODE *now) {
    if (iB < iA || pB < pA) return;
    if (iA == iB || pA == pB) {
        now->N = I[iA];
        return;
    }
    for (int i = iA; i <= iB; i++) {
        if (I[i] == P[pB]) {
            int cnt = i - iA;
            now->N = I[i];
            now->LN = new NODE;
            now->RN = new NODE;
            f(iA, i - 1, pA, pA + cnt - 1, now->LN);
            f(i + 1, iB, pA + cnt, pB - 1, now->RN);
            return;
        }
    }
}

void printP(NODE *now) {
    cout << now->N << " ";
    if (now->LN != NULL && now->LN->N != -1)
        printP(now->LN);
    if (now->RN != NULL && now->RN->N != -1)
        printP(now->RN);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A;
        I.push_back(A);
    }
    for (int i = 0; i < N; i++) {
        cin >> A;
        P.push_back(A);
    }
    f(0, N - 1, 0, N -1, &result);
    printP(&result);
}