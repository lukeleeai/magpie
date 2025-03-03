#include<cstdio>

#include<iostream>

using namespace std;

const int mod=1e9+7;

const int r=(mod+1)>>1;

inline int add(int x)

{

	return x>=mod?x-mod:x;

}

int n,Q;

int a[3050];

int f[3050][3050]; 

int t[3050][3050];

int main()

{

	scanf("%d%d",&n,&Q);

	for(int i=1;i<=n;++i)

	{

		scanf("%d",&a[i]);

	}

	for(int i=1;i<=n;++i)

	{

		for(int j=1;j<=n;++j)

		{

			if(a[i]>a[j]) f[i][j]=1;

		}

	} 

	for(int i=1;i<=Q;++i)

	{

		int x,y; scanf("%d%d",&x,&y);

		for(int j=1;j<=n;++j) if(j!=x)

		{

			t[j][x]=1ll*(f[j][x]+f[j][y])*r%mod;

			t[x][j]=1ll*(f[x][j]+f[y][j])*r%mod;

		}

		for(int j=1;j<=n;++j) if(j!=y)

		{

			t[j][y]=1ll*(f[j][y]+f[j][x])*r%mod;

			t[y][j]=1ll*(f[y][j]+f[x][j])*r%mod;

		}

		t[x][y]=1ll*(f[x][y]+f[y][x])*r%mod;

		t[y][x]=1ll*(f[y][x]+f[x][y])*r%mod;

		for(int j=1;j<=n;++j) if(j!=x)

		{

			f[j][x]=t[j][x];

			f[x][j]=t[x][j];

		}

		for(int j=1;j<=n;++j) if(j!=y)

		{

			f[j][y]=t[j][y];

			f[y][j]=t[y][j];

		}

		f[x][y]=t[x][y];

		f[y][x]=t[y][x];

	}

	int an=0;

	for(int i=1;i<=n;++i)

	{

		for(int j=i+1;j<=n;++j)

		{

			an=add(an+f[i][j]);

		}

	}

	for(int i=1;i<=Q;++i)

	{

		an=add(an<<1);

	}

	printf("%d\n",an);

	return 0;

}