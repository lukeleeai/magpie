#include"stdc++.h"

using namespace std;

int n;

const int N=100010,M=16;

int s[N],cnt[M],ans,f[1000010];

void chkmin(int &x,int y)

{

	if(y<x)x=y;

}

int gi()

{

	int f=0; char ch=getchar();

	while(ch<'0' || ch>'9')ch=getchar();

	while(ch>='0' && ch<='9')f=f*10+ch-48,ch=getchar();

	return f;

}

int main()

{

	n=gi();

	int u,v,w;

	for(int i=1;i<n;i++)

		u=gi(),v=gi(),w=gi(),s[u]^=w,s[v]^=w;

	for(int i=0;i<n;i++)

		cnt[s[i]]++;

	int now=0;

	for(int i=1;i<16;i++)

		ans+=cnt[i]/2,now+=((cnt[i]&1)<<i-1);

	memset(f,127,sizeof(f)); f[now]=0;

	for(int i=(1<<15)-1;i;i--)

		if(f[i]<2000000000)

		{

			for(int j=1;j<=15;j++)

				if(i&(1<<j-1))

					for(int k=1;k<=15;k++)

						if(i&(1<<k-1) && j!=k)

						{

							int l=j^k;

							if(i&(1<<l-1))

								chkmin(f[i-(1<<j-1)-(1<<k-1)-(1<<l-1)],f[i]+2);

							else

								chkmin(f[i-(1<<j-1)-(1<<k-1)+(1<<l-1)],f[i]+1);

						}

		}

	printf("%d\n",f[0]+ans);

	return 0;

}
