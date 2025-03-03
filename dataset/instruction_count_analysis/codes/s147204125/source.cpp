#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cstring>

#define Mod 1000000007

using namespace std;

long long f[2010][2010];

int n,k;

long long fac[4000010],inv[4000010];

long long fpow(long long a,long long b)

{

	long long ans=1,t=a;

	while(b)

	{

		if(b&1)ans=ans*t%Mod;

		t=t*t%Mod;

		b>>=1;

	}

	return ans;

}

void getfac()

{

	fac[0]=1;

	for(int i=1;i<=n*k;i++)

		fac[i]=fac[i-1]*i%Mod;

	inv[n*k]=fpow(fac[n*k],Mod-2);

	for(int i=n*k;i;i--)

		inv[i-1]=inv[i]*i%Mod;

	return ;

}

long long C(int a,int b)

{

	return fac[a]*inv[b]%Mod*inv[a-b]%Mod;

}

int main()

{

	cin>>n>>k;

	if(k==1){

		cout<<1<<"\n";

		return 0;

	}

	getfac();

	f[0][0]=1;

	for(int i=1;i<=n;i++)

		for(int j=0;j<=i;j++)

		{

			f[i][j]+=f[i-1][j];

			if(j)

				f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%Mod*C(n-i+(k-1)*(n-j+1)-1,k-2)%Mod)%Mod;

		}

	printf("%lld\n",f[n][n]);

	return 0;

}