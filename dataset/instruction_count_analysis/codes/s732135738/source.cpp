#include "stdc++.h"

using namespace std;



#define fori( tt,aa)      for(long long i= tt; i<aa; i++)

#define forj( yy,bb)      for(long long j=yy; j<bb; j++)

#define fork( uu,cc)      for(long long k=uu; k<cc; k++)

#define sz(v)    v.size()

#define all(v)   v.begin(), v.end()

#define endl "\n";

#define pb push_back

#define pf push_front

#define popb pop_back

#define popf pop_front

#define EPS 1e-7

#define F first

#define S second

#define THINK_TWICE_CODE_ONCE; fast();



typedef long long ll;

typedef long double ld;

typedef double dd;

typedef string String;

typedef string str;

typedef vector<int> vecint;

typedef vector<ll> vecll;

typedef pair<int, int> pii;





void accuSum2D(vector<vector<int>>&a){

    //accumulate each row

    fori(1, 101)

     forj(1, 101)

        a[i][j] +=a[i][j-1];



    //accumulate each col

    forj(1, 101)

     fori(1, 101)

        a[i][j] +=a[i-1][j];

}



int sum_range(int i, int j, int k, int l, vector<vector<int>>&s){

    return s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1];

}



void fast(){

    cin.tie(0);

    cout.tie(0);

    cin.sync_with_stdio(0);

}



ld pow (ll a, ll b);

ll numOfDigits(ll n);

int main()

{

    THINK_TWICE_CODE_ONCE;

    //freopen("great Vova Wall1.txt", "r", stdin);

    ll n; cin>>n;

    ll sq = sqrt(n);

    ll mn = n-1;

    fori(1, sq+1){

        if(!(n%i)){

            ll div = n/i;

            ll mn2 = min(div, i), mx2 = max(div, i);

            mn = min(mn, mx2 + mn2 -2);

        }

    }

    cout<<mn;

    return 0;

}

ld pow (ll a, ll b){

    ld pow = 1;

    fori(0,b)

        pow *=a;

    return pow;

}



ll numOfDigits(ll n){

    if(!n) return 1;

    return (ll)(log10(n)+1);

}
