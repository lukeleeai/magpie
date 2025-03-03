/*

--------------              |   /

      |                     |  /

      |                     | /

      |             *       |/          |    |         ------            *

      |                     |           |    |        /      \

      |             |       |\          |    |       |       |\          |

   \  |             |       | \         |    |       |       | \         |

    \ |             |       |  \        |    |        \     /   \        |

     V              |       |   \        \__/|         -----     \       |

*/

#include "stdc++.h"

using namespace std;



#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);

#define endl '\n'

#define mem(i,j) memset(i,j,sizeof i);

#define F first

#define S second

#define pb push_back

#define mp make_pair

#define all(a) a.begin(), a.end()

#define bit(s,i) (((s)>>(i))&1LL)

#define lowbit(x) (x&-x)

#define siz(v) (long long)v.size()

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

typedef pair<ll, ll> pll;

const double EPS  = 1e-8;

const int INF     = 0x3F3F3F3F;

const ll LINF     = 4611686018427387903;

const int MOD     = 1e9+7;

const int MAXN    = 2e5+9;

/*-----------------------------------------------------------------------------------------------------*/



string toInt(int a) {

    string s, c;

    while(a>0) {

        s.pb(a%10+'0');

        a/=10;

    }

    for(int i = s.size()-1; i>=0; i--) c.pb(s[i]);

    return c;

}



int main() {

    EmiliaMyWife



    int n, a, b;

    cin >> n >> a >> b;

    if(a>b) swap(a, b);

    ll ans =0;

    for(int i = 1; i <= n; i++) {

        string s = toInt(i);

        //cout << s << endl;

        int cur=0;

        for(auto x: s) {

            cur+=(x-'0');

        }

        if(a<=cur && cur<=b) ans+=i;

    }

    cout << ans;



	return 0;

}
