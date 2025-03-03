#include"stdc++.h"

using namespace std;

#define ll long long int

#define dbl double

#define pi acos(-1)

#define sc1(a) scanf("%lld",&a)

#define sc2(a,b) scanf("%lld%lld",&a,&b)

#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

#define pb push_back



ll ara[1000005];



map<ll,ll>vis;

map<ll,ll>vis1;

map<ll,ll>pos;

map<ll,ll>high;

map<ll,ll>low;

map<string,ll>mp;

vector<ll>vec;

vector<ll>v;

stack<ll>q;

string str1[100];

string str2[100];

priority_queue<ll>pq;

ll dp[1000005],t;

ll mn=1000000;

ll call(ll id)

{

    if(id==t )return 0;

    if(dp[id]!=-1)

        return dp[id];

    ll p=call(id+1)+abs(ara[id+1]-ara[id]);

    ll q=100000000;

    if(id+2!=t+1)

        q=call(id+2)+abs(ara[id+2]-ara[id]);

    dp[id]=min(p,q);

    return dp[id];



}

int main()

{



    // ll t;

    memset(dp,-1,sizeof(dp));

    sc1(t);

    for(ll i=1; i<=t; i++)

    {

        sc1(ara[i]);

    }

    cout<<call(1)<<endl;

    return 0;

}
