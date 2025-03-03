#include <iostream>

#include "stdc++.h"

using namespace std;



#define pb push_back

#define F first

#define S second

#define fo(i,a,b)  for(int i = a; i < b; i++)



using ll = long long;

using ld = long double;

using ul = unsigned long long;

using ii = pair<int, int>;

#define Mosta     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ReadFile            freopen("input.in","r",stdin)

#define WriteFile           freopen("output.txt","w",stdout)

const ll mod7 = 1000000007,mod = 1000000000,OO = 0x3f3f3f3f;

const ld EPS = 1e-7;

double Pi=acos(-1);

const ld rad=Pi/180.0;

ll power(ll x, ll y, ll p)

{

    ll res = 1;

    while (y > 0)

    {

        if (y & 1)

            res = (res*x) % p;

        y = y>>1;

        x = (x*x) % p;

    }

    return res;

}

ll nCr (ll n,ll m)

{

    return(m == 0)?1:n*nCr(n-1,m-1)/m;

}

/*****************************************************/



const int N = (int) 2e5 + 3;

vector <int> oc[N];

int a[N] , n;



int main()

{

    cin >> n;

    for(int i = 1; i <= n; ++i){

        cin >> a[i];

        oc[a[i]].push_back(i);

    }

    int pr = 0 , taken = 0;

    for(int i = 1; i <= n; ++i){

        bool found = false;

        for(auto indx : oc[i]){

            if(indx > pr){

                pr = indx;

                taken++;

                found = true;

                break;

            }

        }

        if(!found)

            break;

    }

    if(taken == 0){

        cout << -1 << "\n";

    }else{

        cout << n - taken << "\n";

    }



    return 0;

}
