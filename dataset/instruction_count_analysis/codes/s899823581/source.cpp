#include<cstdio>

#include<cstring>

#include<algorithm>

typedef long long ll;

typedef long double ld;

ld Max(ld a,ld b){return a>b?a:b;}

inline ll read()

{

	ll x=0,f=1;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}

	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}

	return x*f;

}

ll k,a;

ld MAA,uu;

ll rr(ll x)

{

	ll now=0;

	while(x) now+=x%10,x/=10;

	return now;

}

bool check(ll x)

{

	//printf("%lldzx\n",x);

	ll g=1;

	while(g<=x)

	{

		//printf("%lld %lld %lld %lld %lld %lf %lf\n",g,(x+g),rr(x+g),x,rr(g),(double)1.0*(x+g)/rr(x+g),(double)1.0*x/rr(x));

		if((ld)(x+g)*rr(x)<(ld)x*rr(x+g))return 0;

		g=(g<<3)+(g<<1);

	}

	return 1;

}

int main()

{

	//printf("%lf\n",(double)2/1);

	scanf("%lld",&k);

	while(k--)

	{

		ll r=1;

		while(1)

		{

			if(check(r+a))

			{

				a+=r;

				break;

			}

			r=(r<<3)+(r<<1);

		}

		printf("%lld\n",a);

	}

	return 0;

}