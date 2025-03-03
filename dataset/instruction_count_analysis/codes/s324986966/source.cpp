//    https://youtu.be/N3oCS85HvpY



#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef long double ld;

typedef long long unsigned llu;

typedef pair<long long, long long> pll;

const long long inf = 2000000000000000000LL;	// 2e18

#define pi                  acos(-1.0)

#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define shesh               "\n"

#define ff                  first

#define ss                  second

#define pb                  push_back

#define bp                  pop_back

#define pf                  push_front

#define fp                  pop_front

#define ub                  upper_bound

#define lb                  lower_bound

#define all(x)              x.begin(), x.end()

#define debug(x)            cout<<"debug "<<x<<"\n"

#define mest(a,b)           memset(a,b,sizeof(a))



int main()

{

    fast;

    llu ans=5000000000000000000;

    ll t,n,m,i,j,l,k,temp,flag,x,y,x1,x2,y1,y2;

    cin>>n>>k;

    vector<pair<ll,ll> >v;

    vector<ll>X,Y;

    for(i=0; i<n; i++)

    {

        cin>>x>>y;

        v.pb({x,y});

        X.pb(x);

        Y.pb(y);

    }

//    sort(all(X));

//    sort(all(Y));

    for(j=0; j<n; j++)

    {

        for(x=j+1; x<n; x++)

        {

            for(y=0; y<n; y++)

            {

                for(t=y+1,temp=0; t<n; t++)

                {

                    x1=min(X[j],X[x]);

                    x2=max(X[j],X[x]);

                    y1=min(Y[y],Y[t]);

                    y2=max(Y[y],Y[t]);

                    for(l=0,temp=0; l<n; l++)

                    {

                        if(v[l].ff>=x1 && v[l].ff<=x2 && v[l].ss>=y1 && v[l].ss<=y2)

                            temp++;

                    }

                    if(temp>=k)

                    {

                        if(ans>((llu)abs(x1-x2))*((llu)abs(y1-y2)))

                            ans=((llu)abs(x1-x2))*((llu)abs(y1-y2));

                    }

                }

            }

        }

    }

    cout<<ans;

    return 0;

}
