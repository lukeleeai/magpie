#include "stdc++.h"

using namespace std;

 

#define mod 1000000007

 

int n,m,cnt,flag1,flag2,s1,s2;

long long k;

char s[2001][2001];

 

long long quickpow(long long base,long long to)

{

	if(to<=0)return 1;

	if(to==1)return base;

	long long mid=quickpow(base,to>>1);

	if(to&1)return mid*mid%mod*base%mod;

	else return mid*mid%mod;

}

 

struct Matrix{

	long long a[3][3];

	Matrix(){memset(a,0,sizeof(a));}

	Matrix operator*(Matrix &m)

	{

		Matrix ans;

		for(int i=1;i<=2;++i)

			for(int j=1;j<=2;++j)

				for(int k=1;k<=2;++k)

					ans.a[i][j]=(ans.a[i][j]+a[i][k]*m.a[k][j]%mod)%mod;

		return ans;

	}

};

 

int main()

{

	scanf("%d%d%lld",&n,&m,&k);

	for(int i=1; i<=n; ++i)

		scanf("%s",s[i]+1);

	for(int i=1; i<=n; ++i)

	{

		for(int j=1; j<=m; ++j)

			if(s[i][j]=='#')

			{

				++cnt;

				s1+=s[i][j-1]=='#';

				s2+=s[i-1][j]=='#';

			}

		if(s[i][1]=='#' && s[i][m]=='#')++flag1;

	}

	for(int i=1;i<=m;++i)if(s[1][i]=='#' && s[n][i]=='#')++flag2;

	if(flag1 && flag2)

	{

		puts("1");

		return 0;

	}

	if(!flag1 && !flag2)

	{

		printf("%lld\n",quickpow(cnt,k-1));

		return 0;

	}

	if(!flag1)swap(flag1,flag2),swap(s1,s2);

	Matrix A;

	A.a[1][1]=cnt;

	A.a[2][1]=s1;

	A.a[2][2]=flag1;

	--k;

	Matrix ANS;

	ANS.a[1][1]=ANS.a[2][2]=1;

	while(k)

	{

		if(k&1)ANS=ANS*A;

		A=A*A;

		k>>=1;

	}

	printf("%lld\n",(ANS.a[1][1]-ANS.a[2][1]+mod)%mod);

}