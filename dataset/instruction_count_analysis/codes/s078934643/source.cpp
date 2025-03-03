#include "stdc++.h"



using namespace std;

#define int long long

#define x first

#define y second



#define vert int v, int tl, int tr

#define tm ((tl + tr) >> 1)

#define left (v << 1), tl, tm

#define right (v << 1) + 1, tm, tr



typedef pair<int, int> pii;

typedef long long ll;

typedef long double ld;



int n;

int a[100009];

int pref[100009];



int tree[800009];

void build(vert) {

    tree[v] = 0;

    if (tr - tl == 1) return;



    build(left);

    build(right);

}



void upd(vert, int i, int x) {

    tree[v] += x;

    if (tr - tl == 1) {

        return;

    }



    if (i < tm) {

        upd(left, i, x);

    }



    else {

        upd(right, i, x);

    }

}



int getsum(vert, int l, int r) {

    if (l >= tr || tl >= r) return 0;

    if (tl >= l && tr <= r) return tree[v];

    return getsum(left, l, r) + getsum(right, l, r);

}



int check(int x) {

    for (int i = 0; i < n; i ++) {

        if (a[i] >= x)

            pref[i + 1] = pref[i] + 1;

        else

            pref[i + 1] = pref[i] - 1;

    }



    build(1, 0, 2 * n + 2);

    int cnt = 0;

    for (int i = 0; i <= n; i ++) {

        cnt += getsum(1, 0, 2 * n + 2, 0, pref[i] + n + 1);

        upd(1, 0, 2 * n + 2, pref[i] + n, 1);

    }



    return cnt;

}



signed main() {

    ios :: sync_with_stdio(0);

    cin.tie(0);



    cin >> n;

    for (int i = 0; i < n; i ++) {

        cin >> a[i];

    }



    int l = 0, r = (1e9) + 1;

    int eth = (n * n) / 2;

    while (r - l > 1) {

        int m = (r + l) / 2;

        if (check(m) <= (eth + 1) / 2) {

            r = m;

        }



        else {

            l = m;

        }

    }



    cout << l;



    return 0;

}
