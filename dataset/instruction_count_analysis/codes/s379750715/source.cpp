#include "stdc++.h"

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

 

const double EPS = 1e-10;

const ll INF = 100000000;

const ll MOD = 1000000007;



struct ITEM {

    int v, w;

    double x;



    bool operator>(const ITEM& right) const {

        return x > right.x;

    }

} item[1000];



int N, W;

int v[1000], w[1000];

int ans;

int ans2;



void dfs (int pos, int val, int sum, bool flag) {

    if (ans < val) {

        ans = val;

        ans2 = sum;

    }

    if (ans == val) {

        ans2 = min(ans2, sum);

    }

    if (pos == N) return;

    if (flag) {

        int _W = W-sum;

        double lim = val;

        for (int i = pos; i < N; i++) {

            if (_W >= item[i].w) {

                lim += item[i].v;

                _W -= item[i].w;

            } else {

                lim += _W * item[i].x;

                break;

            }

        }

        if (lim+EPS < ans) {

            return;

        }

    }

    if (sum+item[pos].w <= W) {

        dfs(pos+1, val+item[pos].v, sum+item[pos].w, false);

    }

    dfs(pos+1, val, sum, true);

}



int main() {

    int testcase = 1;

    while (cin >> W) {

        if (W == 0) break;

        ans = 0;

        cin >> N;

        rep(i,N) {

            char tmp;

            cin >> item[i].v >> tmp >> item[i].w;

            item[i].x = item[i].v / (double)item[i].w;

        }

        sort(item, item+N, greater<ITEM>());

        dfs(0, 0, 0, false);

        cout << "Case " << testcase << ":" << endl;

        cout << ans << endl;

        cout << ans2 << endl;

        testcase++;

    }

}




