		/**Bismillahir Rahmanir Rahim**/





#include"stdc++.h"

using namespace std;

#define ll long long



#define pb push_back

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define clr(v) v.clear()

vector<ll>v;

pair<ll,ll>p;

map<ll,ll>mp;

set<ll>st;

deque<ll>dq;

priority_queue<ll>pq;

#define f(i,b) for(i=0;i<b;i++)

#define f1(i,b) for(i=1;i<=b;i++)

#define fr(i,b)for(i=b-1;i>=0;i--)

ll mn=INT_MAX,mx=INT_MIN;

ll n,m,tc,i,j,tmp,sum,cn,ans,res,pos,flag,l,x,k,dif;



string s,str;





ll a[200007],b[200007];

int main()

{





   ll d,a,b,c;



cin>>a>>b>>c>>d;

if(abs(c-a)<=d)

    cout<<"Yes";

else

{

    ll dif=abs(a-b);

    ll dif1=abs(b-c);

    if(dif>d||dif1>d)

        cout<<"No";

    else cout<<"Yes";

}

return 0;

}






