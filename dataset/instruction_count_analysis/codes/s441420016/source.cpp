#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#define rep2(i, x, n) for(int i = x; i <= n; i++)

#define rep3(i, x, n) for(int i = x; i >= n; i--)

#define elif else if

typedef long long ll;

typedef pair<ll, ll> P;

const ll MOD = 1e9+7;

const ll MOD2 = 998244353;

const ll INF = 1e18;



ll f(ll a, ll b){return a+b;}

int other = 0;



struct segment_tree{

    int n;

    int seg[1000000];

    //要素数Nのセグメントツリーを構築

    segment_tree(int N){

        n = 1;

        while(n < N) n *= 2;

        fill_n(seg, 2*n-1, other);

    }

    //i番目の要素をxに変更(0番目から数える)

    void update(int i, ll x){

        i += n-1;

        seg[i] = x;

        while(i > 0){

            i = (i-1)/2;

            seg[i] = f(seg[2*i+1], seg[2*i+2]);

        }

    }

    //要素数N以上の最小の２べきnを取得

    ll size(){return n;}

    //query(a, b, 0, 0, n)でa番目からb-1番目までの演算の結果を取得

    ll query(int a, int b, int i, int l, int r){

        if(a >= r || b <= l) return other;

        elif(a <= l && r <= b) return seg[i];

        else{

            int vl = query(a, b, 2*i+1, l, (l+r)/2);

            int vr = query(a, b, 2*i+2, (l+r)/2, r);

            return f(vl, vr);

        }

    }

};



int main(){

    int N;

    cin >> N;

    ll e[N];

    e[0] = 1;

    rep2(i, 1, N-1) e[i] = (2*e[i-1])%MOD2;

    int x[N], y[N];

    vector<P> vecx, vecy, vec;

    rep(i, N){

        cin >> x[i] >> y[i];

        vecx.push_back(P(x[i], i));

        vecy.push_back(P(y[i], i));

    }

    sort(vecx.begin(), vecx.end());

    sort(vecy.begin(), vecy.end());

    rep(i, N){

        int px = vecx[i].second, py = vecy[i].second;

        x[px] = i, y[py] = i;

    }

    rep(i, N) vec.push_back(P(x[i], y[i]));

    sort(vec.begin(), vec.end());

    int X[N], Y[N];

    rep(i, N) X[i] = vec[i].first, Y[i] = vec[i].second;

    segment_tree segl(N), segr(N);

    ll n = segl.size();

    ll ul[N], ur[N], dl[N], dr[N];

    rep(i, N){

        dl[i] = segl.query(0, Y[i], 0, 0, n);

        ul[i] = i - dl[i];

        segl.update(Y[i], 1);

    }

    rep3(i, N-1, 0){

        dr[i] = segr.query(0, Y[i], 0, 0, n);

        ur[i] = N-1-i - dr[i]; 

        segr.update(Y[i], 1);

    }

    ll ans = (N*e[N-1])%MOD2;

    rep(i, N){

        ll a = (e[ul[i]]-1)*(e[dr[i]]-1) % MOD2;

        ll b = (e[ur[i]]-1)*(e[dl[i]]-1) % MOD2;

        ans += a * e[ur[i]+dl[i]];

        ans %= MOD2;

        ans += b * e[ul[i]+dr[i]];

        ans %= MOD2;

        ans += MOD2*MOD2 - a*b;

        ans %= MOD2;

    }

    cout << ans << endl;

}
