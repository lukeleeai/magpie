//此程序使用了qt专属名称，请勿模仿。侵权必究！！！

//我真是太菜了…… 

#include"stdc++.h"

using namespace std;

#define ll long long

const ll N=20,P=1e9+7;

ll n,m,ans=1,a[1<<N]={1};

inline ll read()

{

	ll sum=0,flag=1;

	char c;

	for(;c<'0'||c>'9';c=getchar())if(c=='-') flag=-1;

	for(;c>='0'&&c<='9';c=getchar())sum=(sum<<1)+(sum<<3)+c-'0';

	return sum*flag;

}

inline ll pow(ll x,ll y)

{

	ll k=1;

	while(y)

	{

		if(y&1)

		{

			k*=x;

			k%=P;

		}

		y>>=1;

		x*=x;

		x%=P;

	}

	return k;

}

int main()

{

//	freopen("a.in","r",stdin);

//	freopen("a.out","w",stdout);

	n=read();

	m=read();

	for(int i=1;i<=1<<(N-1);++i)

	{

		a[i]=a[i-1]*i%P;

	}

	for(ll i=2;i*i<=m;++i)

	{

		if(!(m%i))

		{

			ll k=0;

			while(!(m%i))

			{

				++k;

				m/=i;

			}

			ans*=a[n+k-1]%P*pow(a[n-1],P-2)%P*pow(a[k],P-2)%P;

			ans%=P;

		}

	}

	if(m>1)

	{

		ans*=n;

		ans%=P;

	}

	printf("%lld\n",ans);

	return 0;

}




