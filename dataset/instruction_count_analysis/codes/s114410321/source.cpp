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

string s;

int l,i;

int main(void)

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin>>s;

    l=s.length();

    for(i=0;i<l;++i)

    {

        if(s[i]=='?')

            cout<<'D';

        else

            cout<<s[i];

    }

    cout<<'\n';

    return 0;

}
