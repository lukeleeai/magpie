#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<ctime>

#include<cstdlib>

#define cmax(a,b) (a<(b)?a=(b),1:0)

#define cmin(a,b) (a>(b)?a=(b),1:0)

#define dmin(a,b) ((a)<(b)?(a):(b))

#define dmax(a,b) ((a)>(b)?(a):(b))

#define CL fclose(stdin),fclose(stdout)

namespace io

{

	int F()

	{

		int n=0,F=1;

		char ch;

		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));

		ch=='-'?F=0:n=ch-'0';

		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';

		return F?n:-n;

	}

	long long G()

	{

		long long n=0,F=1;

		char ch;

		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));

		ch=='-'?F=0:n=ch-'0';

		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';

		return F?n:-n;

	}

}

int c[555][555];

int f[555][555];

int g[555][1111];

int main()

{

	//freopen("rabbit.in","r",stdin);

	//freopen("rabbit.out","w",stdout);

	int n=io::F(),M=1000000007;

	for(register int i=0;i<=n;++i)c[i][0]=c[i][i]=1;

	for(register int i=2;i<=n;++i)

		for(register int j=1;j<i;++j)

			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;

	f[1][0]=c[n][1];

	f[1][1]=c[n][1];

	for(register int i=1;i<=n;++i)

	{

		for(register int j=-i;j<=i;++j)

			if(g[i][j+500])

			{

				long long G=g[i][j+500];

				register int y=dmax(j,0);

				if(y+j&1)++y;

				for(;y+i<=n;y+=2)

					f[i+y][abs(j+y)/2]=(f[i+y][abs(j+y)/2]+G*c[n-i][y])%M;

			}

		for(register int j=0;j<=i;++j)

			if(f[i][j])

			{

				long long F=f[i][j];

				for(register int x=1;x+i<=n;++x)

					g[i+x][j-x+500]=(g[i+x][j-x+500]+F*c[n-i][x])%M;

				register int y=1;

				if(y+j&1)++y;

				for(;y+i<=n;y+=2)

				{

					int cnt=y;

					if(cnt<j)continue;

					int ck=j+(cnt-j)/2;

					if(abs(ck)+cnt+i>n)continue; 

					f[i+cnt][ck]=(f[i+cnt][ck]+F*c[n-i][0]%M*c[n-i][y])%M;

				}

			}

	}

	printf("%d\n",f[n][0]);

	return 0;

}