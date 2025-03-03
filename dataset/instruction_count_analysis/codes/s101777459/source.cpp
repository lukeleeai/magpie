#include <iostream>

#include <algorithm>

#include <cmath>

#include <cstdlib>

#include <cstdio>

#include <cstring>

#include <iomanip>

#include <string>

#include <set>

#include <vector>

#include <queue>

#include <stack>

using namespace std;

#define ms(a, x) memset(a, x, sizeof(a))

#define fore(i, a, n) for (long long i = a; i < n; i++)

#define ford(i, a, n) for (long long i = n - 1; i >= a; i--)

#define si(a) scanf("%d", &a)

#define sii(a, b) scanf("%d%d", &a, &b)

#define debug(a) cout << a << endl

#define endl '\n'

#define pi acos(-1.0)

#define tr t[root]

#define lson t[root << 1]

#define rson t[root << 1 | 1]

#define IO ios::sync_with_stdio(false), cin.tie(0)

const double eps = 1e-8;

inline int sgn(const double &x) { return x < -eps ? -1 : x > eps; }

typedef long long ll;

const int inf = 0x3f3f3f3f;

const int maxn=1000100;

#define maxn0 1e9+7;

//=================================================



ll sum;

ll w[maxn];

ll dp[maxn];

ll v[maxn];



// void init() {

//     for(ll i=0;i<=n;i++){

//         w[i]=0;

//         v[i]=0;

//     }

// }

int main() {

    IO;

    ll n,W;

    cin>>n>>W;

    // sum=0;

    // init();

    memset(dp,inf,sizeof(dp));

    dp[0]=0;

    for(int i=1;i<=n;i++){

        cin>>w[i]>>v[i];

        // sum+=v[i];

    }

    for(int i=1;i<=n;i++) {

        for(int j=100000;j>=v[i];j--) {

            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);

        }

    }

    ll ans=-1;

    for(int i=1;i<=100000;++i) {

        if(dp[i]<=W)

            ans=max(ans,1LL*i);

    }

    cout<<ans<<endl;



    return 0;

}