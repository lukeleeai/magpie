#include <cstdio>

#include <algorithm>

#include <cstdlib>

#include <ctime>

#define inf 1e18+2

using namespace std;

typedef unsigned long long ll;

inline ll rd()

{

	ll x=0,p=1;

	char a=getchar();

	while((a<48||a>57)&&a!='-')a=getchar();

	if(a=='-')p=-p,a=getchar();

	while(a>47&&a<58)

	{

		x=(x<<1)+(x<<3)+(a&15);

		a=getchar();

	}

	return x*p;

}

inline void write(ll x)

{

	if(x<0)x=-x,putchar('-');

	if(x>9)write(x/10);

	putchar(x%10+48);

}

inline void print(ll x,int type=0)

{

	write(x);

	if(!type)putchar(' ');

	else puts("");

}

struct node

{

	ll x,y;

}d[200002];

ll n,lmax,lmin,rmax,rmin;

ll ans;

int main()

{

	srand(time(0));

	n=rd();

	d[1].x=rd();d[1].y=rd();

	lmax=lmin=d[1].x;rmax=rmin=d[1].y;

	for(int i=2;i<=n;i++)

	{

		d[i].x=rd();d[i].y=rd();

		ll a,b;

		if(d[i].x>lmax)

		{

			if(d[i].y>rmax)a=(d[i].x-lmin)*(d[i].y-rmin);

			else if(d[i].y<rmin)a=(d[i].x-lmin)*(rmax-d[i].y);

			else a=(d[i].x-lmin)*(rmax-rmin);

		}

		else if(d[i].x<lmin)

		{

			if(d[i].y>rmax)a=(lmax-d[i].x)*(d[i].y-rmin);

			else if(d[i].y<rmin)a=(lmax-d[i].x)*(rmax-d[i].y);

			else a=(lmax-d[i].x)*(rmax-rmin);

		}

		else

		{

			if(d[i].y>rmax)a=(lmax-lmin)*(d[i].y-rmin);

			else if(d[i].y<rmin)a=(lmax-lmin)*(rmax-d[i].y);

			else a=(lmax-lmin)*(rmax-rmin);

		}

		swap(d[i].x,d[i].y);

		if(d[i].x>lmax)

		{

			if(d[i].y>rmax)b=(d[i].x-lmin)*(d[i].y-rmin);

			else if(d[i].y<rmin)b=(d[i].x-lmin)*(rmax-d[i].y);

			else b=(d[i].x-lmin)*(rmax-rmin);

		}

		else if(d[i].x<lmin)

		{

			if(d[i].y>rmax)b=(lmax-d[i].x)*(d[i].y-rmin);

			else if(d[i].y<rmin)b=(lmax-d[i].x)*(rmax-d[i].y);

			else b=(lmax-d[i].x)*(rmax-rmin);

		}

		else

		{

			if(d[i].y>rmax)b=(lmax-lmin)*(d[i].y-rmin);

			else if(d[i].y<rmin)b=(lmax-lmin)*(rmax-d[i].y);

			else b=(lmax-lmin)*(rmax-rmin);

		}

		swap(d[i].x,d[i].y);

		if(a<=b)

		{

			lmax=max(lmax,d[i].x);lmin=min(lmin,d[i].x);

			rmax=max(rmax,d[i].y);rmin=min(rmin,d[i].y);

		}

		else

		{

			lmax=max(lmax,d[i].y);lmin=min(lmin,d[i].y);

			rmax=max(rmax,d[i].x);rmin=min(rmin,d[i].x);

		}

	}

	ans=(lmax-lmin)*(rmax-rmin);

	for(int q=1;q<=150;q++)

	{

		random_shuffle(d+1,d+n+1);

		lmax=lmin=d[1].x;rmax=rmin=d[1].y;

		for(int i=2;i<=n;i++)

		{

			ll a,b;

			if(d[i].x>lmax)

			{

				if(d[i].y>rmax)a=(d[i].x-lmin)*(d[i].y-rmin);

				else if(d[i].y<rmin)a=(d[i].x-lmin)*(rmax-d[i].y);

				else a=(d[i].x-lmin)*(rmax-rmin);

			}

			else if(d[i].x<lmin)

			{

				if(d[i].y>rmax)a=(lmax-d[i].x)*(d[i].y-rmin);

				else if(d[i].y<rmin)a=(lmax-d[i].x)*(rmax-d[i].y);

				else a=(lmax-d[i].x)*(rmax-rmin);

			}

			else

			{

				if(d[i].y>rmax)a=(lmax-lmin)*(d[i].y-rmin);

				else if(d[i].y<rmin)a=(lmax-lmin)*(rmax-d[i].y);

				else a=(lmax-lmin)*(rmax-rmin);

			}

			swap(d[i].x,d[i].y);

			if(d[i].x>lmax)

			{

				if(d[i].y>rmax)b=(d[i].x-lmin)*(d[i].y-rmin);

				else if(d[i].y<rmin)b=(d[i].x-lmin)*(rmax-d[i].y);

				else b=(d[i].x-lmin)*(rmax-rmin);

			}

			else if(d[i].x<lmin)

			{

				if(d[i].y>rmax)b=(lmax-d[i].x)*(d[i].y-rmin);

				else if(d[i].y<rmin)b=(lmax-d[i].x)*(rmax-d[i].y);

				else b=(lmax-d[i].x)*(rmax-rmin);

			}

			else

			{

				if(d[i].y>rmax)b=(lmax-lmin)*(d[i].y-rmin);

				else if(d[i].y<rmin)b=(lmax-lmin)*(rmax-d[i].y);

				else b=(lmax-lmin)*(rmax-rmin);

			}

			swap(d[i].x,d[i].y);

			if(a<=b)

			{

				lmax=max(lmax,d[i].x);lmin=min(lmin,d[i].x);

				rmax=max(rmax,d[i].y);rmin=min(rmin,d[i].y);

			}

			else

			{

				lmax=max(lmax,d[i].y);lmin=min(lmin,d[i].y);

				rmax=max(rmax,d[i].x);rmin=min(rmin,d[i].x);

			}

		}

		ans=min(ans,(lmax-lmin)*(rmax-rmin));

	}

	print(ans,1);

	return 0;

}