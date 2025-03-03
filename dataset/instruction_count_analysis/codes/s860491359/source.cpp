#include"stdc++.h"

using namespace std;

typedef long long ll;

#define pb push_back

#define pi (acos(-1))

#define ull  unsigned long long

#define ld long double

///freopen("input.txt","r",stdin);

///freopen("output.txt","w",stdout);

#define M 100000

ll LCM(ll a, ll b)

{

    ll g = __gcd(a,b);

    return (a*b)/g ;

}

string numtostr(ll n)

{

    ostringstream str1 ;

    str1 << n ;

    return str1.str();

}

ll strtonum(string s)

{

    ll x ;

    stringstream str1(s);

    str1 >> x ;

    return x ;

}

int h1,m1,h2,m2,a;

int main(void)

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin>>h1>>m1>>h2>>m2>>a;

    cout<<h2*60+m2-(h1*60+m1)-a<<'\n';

    return 0;

}
