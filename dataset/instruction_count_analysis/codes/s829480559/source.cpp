#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)

#define rep(i,n) FOR(i,0,n)

#define ALL(x) (x).begin(),(x).end()

#define RALL(x) (x).rbegin(),(x).rend()

#define SZ(x) (int)(x).size()

#define ZERO(a) memset(a,0,sizeof(a))

#define dbg(x) cout<<#x<<": "<<(x)<<"\n"

#define pb push_back

#define eb emplace_back

#define mp make_pair



const int mod = 1e9 + 7;

int n;

int x[114514], y[114514];



void solve() {

    vector<int> t(n), a(n);

    for(auto& i : t) scanf("%d",&i);

    for(auto& i : a) scanf("%d",&i);

    if(t.back() != a[0]) {

        puts("0");

        return ;

    }

    x[0] = x[n-1] = 1;

    FOR(i,1,n-1) {

        if(t[i-1] != t[i]) {

            x[i] = 1;

            y[i] = t[i];

        } else {

            x[i] = t[i];

            y[i] = -1;

        }

    }



    for(int i=n-2; i>=0; i--) {

        if(y[i]!=-1 and a[i] < y[i]) {

            puts("0");

            return ;

        }

        if(a[i] > a[i+1])

            x[i] = 1;

        else

            x[i] = min(x[i], a[i]);

    }



    ll ans = 1;

    rep(i,n) {

        ans = (ans * x[i]) % mod;

    }



    cout << ans << "\n";

}





int main() {

    while(cin>>n) {

        ZERO(x); ZERO(y);

        solve();

    }

    return 0;

}
