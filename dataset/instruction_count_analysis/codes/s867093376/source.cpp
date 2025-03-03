#include"stdc++.h"

#define rep(i,l,r) for (int i=l;i<=r;i++)

using namespace std;

typedef long long ll;

const int maxn=305;

ll f[maxn][maxn],g[maxn][maxn],c[maxn][maxn],fac[maxn],inv[maxn];

int n,k;

ll mm;

ll dfs(int i,int j);

ll getsum(int i,int j){

	if (~g[i][j]) return g[i][j];

	g[i][j]=0;

	rep(p,j,k) (g[i][j]+=dfs(i,p))%=mm;

	return g[i][j];

}

ll dfs(int i,int j){

	if (~f[i][j]) return f[i][j];

	if (i==1) return f[i][j]=1;

	f[i][j]=0;

	rep(len,1,i-1) {

		(f[i][j]+=getsum(len,j+1)*dfs(i-len,j)%mm*c[i-2][len-1]%mm)%=mm;

	}

	return f[i][j];

}

int main(){

	scanf("%d%d%lld",&n,&k,&mm);

	c[0][0]=1;

	rep(i,1,n) {

		c[i][0]=1; c[i][i]=1;

		rep(j,1,i-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mm;

	}

	memset(f,-1,sizeof(f));

	memset(g,-1,sizeof(g));

	dfs(n+1,0);

	printf("%lld\n",f[n+1][0]);

	return 0;

}