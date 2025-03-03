//404 Not Found {=}7 (o)7 (x)7

#include"stdc++.h"

using namespace std;

#define append push_back

#define endl "\n"

#define dbug(x) cout<<#x<<"="<<x<<endl



typedef long long int ll;

typedef long double ld;

typedef pair<int,int> pii;



const ll maxn = 5e5+10, inf = 1e9, mod= 1e9+7;

ll a[maxn];

vector<ll> v;

ll b[maxn];

ll fen[maxn+10];

ll par[maxn];

ll get(ll id)

{

    ll sum = 0;

    for(;id;id -= id&-id)

        sum += fen[id];

    return sum;

}

void add(ll id)

{

    for(;id<maxn;id += id&-id)

        fen[id] ++;

}

int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    

    ll n;

    cin >> n;

    for(ll i = 0;i<n;i++){

        cin >> a[i];

        v.append(a[i]);

    }

    sort(v.begin(),v.end());

    ll l=0,r=n;

    while(l+1 < r)

    {

        ll mid = (l+r) / 2;

        

        for(ll i = 0;i<n;i++)

            b[i] = (a[i]<v[mid]?1ll:-1ll);

        b[0] += n+2;

        for(ll i = 1 ;i<n;i++)

            b[i] += b[i-1];



        ll ans = 0;

        add(n+2);

        ans += get(b[0]-1);

        add(b[0]);

        for(ll i = 1;i < n;i++)

        {

            ans += get(b[i]-1);

            add(b[i]);

        }                                   

        if(ans > (n*(n+1))/4)

        {

            r = mid;

        }

        else

        {

            l = mid;

        }

        for(ll i = 0;i<maxn;i++)

            fen[i] =0;

    }

    cout << v[l];

    

    return 0;

}