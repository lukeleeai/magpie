#include"stdc++.h"

using namespace std;

#define inf 0x3f3f3f3f

#define ll long long

const int N=200005;

const int mod=1e9+7;

const double eps=1e-8;

const double PI = acos(-1.0);

#define lowbit(x) (x&(-x))

ll ceils(ll x,ll y)

{

    if(x%y==0)

        return x/y;

    return x/y+1;

}

int main()

{

    std::ios::sync_with_stdio(false);

    int n;

    ll a,b;

    cin>>n>>a>>b;

    for(int i=1;i<n;i++)

    {

        ll x,y;

        cin>>x>>y;

        ll t=max(ceils(a,x),ceils(b,y));

        a=x*t,b=y*t;

    }

    cout<<a+b<<endl;

    return 0;

}