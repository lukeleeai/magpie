#include "stdc++.h"

using namespace std;



inline long long read()

{

	long long x=0,f=1,c=getchar();

	while(c<48) c=='-'&&(f=-1),c=getchar();

	while(c>47) x=x*10+c-'0',c=getchar();

	return x*f;

}



typedef long long ll;

const ll MAXN = 100005;

struct Node {ll a,b;} s[MAXN];

priority_queue<ll,vector<ll>,greater<ll> > q,ept;

ll lp[MAXN],rp[MAXN],ans;

ll n,x,y,z;



int main(int argc, char const *argv[])

{

	x=read(); y=read(); z=read(); n=x+y+z;

	for(ll i=1,k;i<=n;++i)

		ans+=(k=read()),s[i].a=read()-k,s[i].b=read()-k;

	sort(s+1,s+n+1,[](Node a,Node b)

	{return a.a-a.b>b.a-b.b;});

	for(ll i=1;i<=n;++i)

	{

		lp[i]=lp[i-1]+s[i].a; q.push(s[i].a);

		if(q.size()>y) lp[i]-=q.top(),q.pop();

	}

	for(ll i=(q=ept,n);i;--i)

	{

		rp[i]=rp[i+1]+s[i].b; q.push(s[i].b);

		if(q.size()>z) rp[i]-=q.top(),q.pop();

	}

	ll mx=-1000000000000000000ll;

	for(ll i=y;i<=n-z;++i)

		mx=max(mx,lp[i]+rp[i+1]);

	printf("%lld\n", ans+mx);

	return 0;

}