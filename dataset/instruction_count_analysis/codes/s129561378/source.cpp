#include<cstdio>

#include<cstring>

#include<algorithm>

typedef long long ll;

ll Min(ll a,ll b){return a<b?a:b;}

ll Abs(ll a){return a>0?a:-a;}

inline ll read()

{

	ll x=0,f=1;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}

	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}

	return x*f;

}

ll n,k,a[100005],l,ans=9999999999999999;

int main()

{

	n=read();k=read();

	for(ll i=1;i<=n;i++) a[i]=read();

	l=n+1;

	a[l]=1;

	for(ll i=1;i<=n;i++) if(a[i]>=0){l=i;break;}

	if(n-l+1>=k) ans=a[l+k-1];

	for(ll i=l-1,r=n;i>=1;i--)

	{

		if(n-i+1<k) continue;

		if(l-i+(a[l]==0)==k)

		{

			ans=Min(ans,Abs(a[i]));

			break;

		}

		while(r-i+1>k) r--;

		//printf("%d %d %lld\n",i,r,a[r]+Abs(a[i])+Min(Abs(a[i]),a[r]));

		ans=Min(ans,a[r]+Abs(a[i])+Min(Abs(a[i]),a[r]));

	}

	printf("%lld",ans);

}