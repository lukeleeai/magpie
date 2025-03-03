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

    int N; cin >> N;



    vector<int> v(N);

    vector<vector<int> > p(N, vector<int>(11));

    int a;

    for (int i = 0; i < N; i++) {

        int tmp = 0;

        for (int j = 0; j < 10; j++) {

            cin >> a; tmp += a * (1 << j);

        }

        v[i] = tmp;

    }

    for (int i = 0; i < N; i++) for (int j = 0; j < 11; j++) cin >> p[i][j];



    int ans = -INF;

    for (int b = 1; b < (1 << 10); b++) {

        int tmp = 0;

        for (int i = 0; i < N; i++) {

            int cnt = 0, c = b & v[i];

            for (int j = 0; j < 10; j++) { if (c & (1 << j)) cnt++; }

            tmp += p[i][cnt];

        }

        ans = max(tmp, ans);

    }

    cout << ans << '\n';

}
