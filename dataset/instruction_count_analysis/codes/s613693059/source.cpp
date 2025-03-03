#include"stdc++.h"

//#include <atcoder/all>



#define INF 1e9

#define rep(i,n)for(long long i=0;(i)<(long long)(n);i++)

#define REP(i,a,b)for(long long i=(long long)(a);(i)<=(long long)(b);i++)

#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;

#define vec(type,n) vector<type>(n)

#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))

#define ALL(a)  (a).begin(),(a).end()

#define pb push_back



using namespace std;

//using namespace atcoder;

using ll = long long;

using P = pair<ll, ll>;

//using mint = modint1000000007;





ll cnt[20][20];

int main(){

    ll n, k;

    cin >> n >> k;

    vector<ll> a(n + 1);

    rep(i, n)cin >> a[i];

    int mx = 62;

    vector<vector<ll>> next(mx + 1, vector<ll> (n + 1, -1));

    rep(i, n)next[0][i + 1] = a[i];

    rep(i, mx){

        REP(j, 1, n)next[i + 1][j] = next[i][next[i][j]];

    }

    int now = 1;

    for(int i = mx; i >= 0; i--){

        if(((k >> i) & 1)){

            now = next[i][now];

        }

    }

    cout << now << endl;

  //rep(i, 10){rep(j, n + 1) cout << next[i][j] << " "; cout << endl;}

}