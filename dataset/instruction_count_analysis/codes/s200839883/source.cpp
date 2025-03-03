#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vint;

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



int n,k,x,y;



int main() {

    cin>>n>>k>>x>>y;

    int ans = 0;

    FOR(i,1,n+1) {

        if(i<=k) ans += x;

        else ans += y;

    }

    cout<<ans<<"\n";



    return 0;

}
