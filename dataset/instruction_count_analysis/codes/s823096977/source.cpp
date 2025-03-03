#include<cstdio>

#include<cstring>

#define retrun return

#define cpnst const

int n,k;

char str[1111];

typedef long long ll;

cpnst ll mod=1e9+7;

ll C[1111][1111],fac[1111];

void precalc()

{

	register int i,ii;

	C[0][0]=1;

	for(i=fac[0]=1;i<=1000;i++)fac[i]=fac[i-1]*i%mod,C[i][0]=C[i][i]=1;

	for(i=1;i<=1000;i++)

		for(ii=1;ii<i;ii++)C[i][ii]=(C[i-1][ii-1]+C[i-1][ii])%mod;

}

ll ans=0;

int siz[1111];

bool vis[1111];

bool eraser()

{for(register int i=1;i<=k;i++)if(!vis[i])if(str[i]=='r')return vis[i]=1;return 0;}

void cover(register int p,int s)

{for(;s;p++)if(!vis[p])vis[p]=1,s--;}

bool elim(int ss)

{

	int R=0;

	int ff=0;

	for(register int i=k;i;i--)

	{

		if(!vis[i])R++;

		if(R>=ss-1)if(!vis[i])if(str[i]=='b')ff=i;

		if(ff)if(!vis[i])if(str[i]=='r')return cover(ff,ss-1),vis[i]=1;

	}return 0;

}

int locatr(int x)

{while(x<=k&&(str[x]!='r'||vis[x]))x++;return x;}

int locatb(int x)

{while(x<=k&&(str[x]!='b'||vis[x]))x++;return x;}

int Rs[11111];

bool valid(int T)

{

	if(!T)return 1;

	register int i;

	for(i=1;i<=k+1;i++)vis[i]=0,Rs[i]=0;

	int cc=0;

	for(i=T;i;i--)

		if(siz[i]>1)cc++;

	int x=locatr(1),y=locatb(x);

	for(i=1;i<=cc;i++)

	{

		if(y==k+1)return 0;

		vis[x]=1,vis[y]=1,Rs[y+1]+=siz[i]-2,x=locatr(x+1),y=locatb(y+1);

		if(y<x)y=locatb(x);

	}for(i=1;i<=T;i++)

		if(siz[i]==1)

			if(!eraser())return 0;

	int ss=0,EE=0;

	for(i=k+1;i;i--)

	{

		ss+=Rs[i];

		if(ss>EE)return 0;

		EE+=!vis[i-1];

	}return 1;

}

ll concen(int T)

{

	register int i,ii;

	ll ret=1,G=T;

	for(i=1;i<=T;i=ii+1)

	{

		for(ii=i;ii<T&&siz[ii]==siz[ii+1];ii++);

		(ret*=C[G][ii-i+1])%=mod,G-=ii-i+1;

	}return ret;

}

ll solve(int T,int res)

{

	if(!T)return 1;

	register int i;

	ll SS=T+1;

	for(i=1;i<=T;i++)SS+=2*siz[i]-1;

	return C[SS+res-1][res]*concen(T);

}

void dfs(int dep=1,int prev=k,int sum=0)

{

	if(sum>n)return;

	if(!valid(dep-1))return;

	(ans+=solve(dep-1,n-sum))%=mod;

	register int i;

	if(dep^1)sum++;

	for(i=prev;i;i--)siz[dep]=i,dfs(dep+1,i,sum+(i<<1)-3+(i==1)*2);

}

int main()

{precalc(),scanf("%d%d%s",&n,&k,str+1),dfs(),printf("%lld\n",ans);}

/*

Just go for it.

*/