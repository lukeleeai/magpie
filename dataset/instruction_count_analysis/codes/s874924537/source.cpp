#include "stdc++.h"

using namespace std;

const int MOD=1e9+7;

inline int add(int a,int b) {return a+=b,a>=MOD?a-MOD:a;}

inline int del(int a,int b) {return a-=b,a<0?a+MOD:a;}

inline int mul(int a,int b) {return 1LL*a*b%MOD;}

const int MAXN=110;

int C[MAXN][MAXN];

inline void initC(int N)

{

	for(int i=0;i<=N;i++) C[i][0]=1;

	for(int i=1;i<=N;i++)

		for(int j=1;j<=i;j++) C[i][j]=add(C[i-1][j-1],C[i-1][j]);

	return;

}

int dp[MAXN][MAXN][MAXN],up[MAXN],sum[MAXN];

inline void solve(int n,int m,int c)

{

	int r=m+(c<<1)-1;

	memset(dp,0,sizeof(dp)),dp[0][0][0]=1;

	for(int i=0;i<m;i++)

		for(int j=0;j<=up[i]&&(j<<1)+r<=n+m;j++)

		{

			int tmp=dp[i][j][0];

			for(int k=1;k<=up[m]&&j+(m-i)*k<=up[m];k++)

			{

				for(int l=1;i+l<=m&&j+k*l<=up[i+l];l++) dp[i+l][j+k*l][k]=add(dp[i+l][j+k*l][k],mul(tmp,C[i+l][l]));

				tmp=add(tmp,dp[i][j][k]);

			}

		}

	for(int i=0;i<=up[m]&&(i<<1)+r<=n+m;i++)

	{

		int tmp=0,tmp_=(i<<1)+r-m;

		for(int j=0;j<=i;j++) tmp=add(tmp,dp[m][i][j]);

		if(!tmp) continue;

		for(int j=0;j<=((m+1)<<1)&&tmp_+j<=n;j++) sum[tmp_+j]=add(sum[tmp_+j],mul(tmp,mul(C[m+c][c],C[(m+1)<<1][j])));

	}

	return;

}

char ch[MAXN];

int q[MAXN],pos[MAXN],vis[MAXN];

int n,k,ans;

int main()

{

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>k>>(ch+1);

	initC(100);

	for(int i=0;(i<<1)<=k;i++)

	{

		memset(vis,0,sizeof(vis));

		int cnt=0,L=1,R=0,s=0,r=1;

		for(int j=1;j<=k&&cnt<i;j++)

			if(ch[j]=='r') q[++R]=j;

			else if(L<=R) vis[q[L++]]=vis[j]=1,pos[++cnt]=j;

		if(cnt<i) continue;

		for(int j=1;j<=k;j++)

			if(!vis[j]&&ch[j]=='r') s++;

		pos[i+1]=k+1,up[i+1]=0;

		for(int j=0;j<=s;j++)

		{

			if(j)

			{

				while(vis[r]||ch[r]!='r') r++;

				vis[r]=1;

			}

			for(int t=i;t>0;t--)

			{

				up[t]=up[t+1];

				for(int t_=pos[t+1]-1;t_>pos[t];t_--)

					if(!vis[t_]) up[t]++;

				up[t]++;

			}

			reverse(up+1,up+i+1),solve(n,i,j);

		}

	}

	for(int i=1;i<=n;i++) ans=add(ans,mul(sum[i],C[n-1][i-1]));

	cout<<ans<<endl;

	return 0;

}