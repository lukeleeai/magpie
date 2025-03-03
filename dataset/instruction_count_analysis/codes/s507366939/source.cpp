#include "stdc++.h"

using namespace std;

/* typedef */

typedef long long ll;

typedef pair<int, int> pii;

/* constant */

const int INF = 1 << 30;

const ll LINF = 1LL << 50;

const int NIL = -1;

const int MAX = 10000;

const int mod = 1000000007;

const double pi = 3.141592653589;

/* global variables */

/* function */

/* main */

int main(){

    int N, X;

    cin >> N >> X;

    int ans = 1, sum = 0;

    int a;

    for (int i = 0; i < N; i++) {

        cin >> a;

        sum += a;

        if (sum <= X) ans++;

    }

    cout << ans << '\n';

}
