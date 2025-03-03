#include "stdc++.h"

using namespace std;

int n, ans = 0 ;

int d[55], cnt[30] ;

bool vis[30] ;

vector<int> v ;

void dfs (int cur) {

    if (cur == n) {

        int res = 1e9 ;

        for (int i = 0; i < v.size(); i ++)

            for (int j = i + 1; j < v.size(); j ++)

                res = min (res, min (abs (v[i] - v[j]), 24 - abs (v[i] - v[j]))) ;

        ans = max (ans, res) ;

        return ;

    }

    dfs (cur + 1) ;

    if (!vis[v[cur]]) {

        v[cur] = 24 - v[cur] ;

        dfs (cur + 1) ;

        v[cur] = 24 - v[cur] ;

    }

}

int main() {

    cin >> n ;

    cnt[0] = 1 ;

    for (int i = 1; i <= n; i ++) {

        scanf("%d", &d[i]) ;

        cnt[d[i]] ++ ;

    }

    for (int i = 0; i <= 12; i ++)

        if (cnt[i] >= 3) {

            printf("0\n"); return 0 ;

        }

    for (int i = 0; i <= 12; i ++) {

        if (cnt[i] == 1) v.push_back (i) ;

        if (cnt[i] == 2) {

            v.push_back (i), v.push_back (24 - i) ;

            vis[i] = 1; vis[24 - i] = 1 ;

        }

    }

    dfs (1) ;

    cout << ans << endl;

    return 0 ;

}
