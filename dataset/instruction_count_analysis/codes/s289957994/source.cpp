#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

#define x first

#define y second

#define mp make_pair

#define pb push_back

template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}

template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}

template <typename TYPE> void readint(TYPE &x)

{

    x=0;int f=1;char c;

    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;

    for(;isdigit(c);c=getchar())x=x*10+c-'0';

    x*=f;

}

const int MAXN=2005;



int n,a[MAXN*2],col[MAXN*2],pos[2][MAXN],pre[MAXN*2][2][MAXN],f[MAXN][MAXN];



int main()

{

	char str[2];

	readint(n);

	for(int i=1;i<=2*n;++i)

		scanf("%s",str),col[i]=(str[0]=='B'),readint(a[i]),pos[col[i]][a[i]]=i;

	for(int i=1;i<=2*n;++i)

	{

		for(int j=1;j<=i;++j)++pre[i][col[j]][a[j]];

		for(int k=0;k<=1;++k)for(int j=1;j<=n;++j)pre[i][k][j]+=pre[i][k][j-1];

	}

	for(int i=1;i<=n;++i)

		f[i][0]=f[i-1][0]+pos[0][i]-pre[pos[0][i]][0][i],

		f[0][i]=f[0][i-1]+pos[1][i]-pre[pos[1][i]][1][i];

	for(int i=1;i<=n;++i)

		for(int j=1;j<=n;++j)

			f[i][j]=min(f[i-1][j]+pos[0][i]-pre[pos[0][i]][0][i]-pre[pos[0][i]][1][j],

				f[i][j-1]+pos[1][j]-pre[pos[1][j]][0][i]-pre[pos[1][j]][1][j]);

	printf("%d\n",f[n][n]);

	return 0;

}