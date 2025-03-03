#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

const int N=1000005,md=998244353;

int n,m,ans;

int nyc[N],fac[N],facn[N];

inline int exgcd(int a,int b,int &x,int &y)

{

	if(b==0)

	{

		x=1;

		y=0;

		return a;

	}

	int t=exgcd(b,a%b,y,x);

	y-=a/b*x;

	return t;

}

inline int inv(int a)

{

	int x=0,y=0;

	exgcd(a,md,x,y);

	return (x+md)%md;

}

inline int C(int n,int m)

{

	return (ll)fac[n]*facn[m]%md*facn[n-m]%md;

}

inline int Cn(int n,int m)

{

	return (ll)facn[n]*fac[m]%md*fac[n-m]%md;

}

int main()

{

	scanf("%d%d",&n,&m);

	inv(1);

	nyc[1]=1;

	fac[0]=facn[0]=fac[1]=facn[1]=1;

	for(int i=2;i<=n+m;i++)

	{

		nyc[i]=(ll)(md-md/i)*nyc[md%i]%md;

		fac[i]=(ll)fac[i-1]*i%md;

		facn[i]=(ll)facn[i-1]*nyc[i]%md;

	}

	for(int i=1;i<=n&&i<=m;i++)

		ans=(ans+(ll)C(n+m-2*i,n-i)*C(2*i,i)%md)%md;

	ans=(ll)ans*nyc[2]%md*Cn(n+m,n)%md;

	ans=(ans+max(n,m))%md;

	printf("%d\n",ans);

	return 0;

}
