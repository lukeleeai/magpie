#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

#define MAXN 1010

#define MO 1000000007

#define LL long long

int cnt,s1,s2,f1,f2,n,m;

LL k;

char s[MAXN][MAXN];

LL PowMod(LL a,LL b)

{

	b%=(MO-1);

	LL ret=1;

	while(b)

	{

		if(b&1) ret=ret*a%MO;

		a=a*a%MO;

		b>>=1;

	}

	return ret;

}

struct maz

{

	LL a[2][2];

	maz(){memset(a,0,sizeof a);};

	maz operator*(maz &m)

	{

		maz ret;

		for(int i=0;i<2;i++)

			for(int j=0;j<2;j++)

				for(int k=0;k<2;k++)

					ret.a[i][j]=(ret.a[i][j]+a[i][k]*m.a[k][j]%MO)%MO;

		return ret;

	}

};

int main()

{

	scanf("%d%d%lld",&n,&m,&k);

	for(int i=1;i<=n;i++)

	{

		scanf("%s",s[i]+1);

		for(int j=1;j<=m;j++)

			if(s[i][j]=='#')

			{

				cnt++;

				s1+=(s[i-1][j]=='#');

				s2+=(s[i][j-1]=='#');

			}

		if(s[i][1]=='#'&&s[i][m]=='#') f2++;

		if(i==n)

		{

			for(int j=1;j<=m;j++)

				if(s[1][j]=='#'&&s[n][j]=='#') f1++;

		}

	}

	if((f1&&f2)||k==0)

	{

		printf("1\n");

		return 0;

	}

	else if(f1==0&&f2==0)

	{

		printf("%lld\n",PowMod(cnt,k-1));

		return 0;

	}

	if(f1==0)

	{

		swap(f1,f2);

		swap(s1,s2);

	}

	maz A,ans;

	A.a[0][0]=cnt,A.a[1][0]=s1,A.a[1][1]=f1;

	ans.a[0][0]=ans.a[1][1]=1;

	k--;

	while(k)

	{

		if(k&1) ans=ans*A;

		A=A*A;

		k>>=1;

	}

	printf("%lld\n",(ans.a[0][0]-ans.a[1][0]+MO)%MO);

}