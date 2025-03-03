#include<cstdio>

int to[200001],nxt[200001],n,h[100001],a,b,l,cnt,siz[100001],r1,r2,maxs[100001],fa[100001];

long long len[200001],ans;

void ins(int x,int y,int z){to[++cnt]=y;len[cnt]=z;nxt[cnt]=h[x];h[x]=cnt;}

int Max(int x,int y){return x>y?x:y;}

int Min(int x,int y){return x<y?x:y;}

void dfs(int x){

	for(int i=h[x];i;i=nxt[i])if(to[i]!=fa[x]){

		fa[to[i]]=x;dfs(to[i]);

		siz[x]+=siz[to[i]];

		maxs[x]=Max(maxs[x],siz[to[i]]);

	}

	maxs[x]=Max(maxs[x],n-(++siz[x]));

	if(maxs[x]<maxs[r1])r1=x;

	else if(maxs[x]==maxs[r1])r2=x;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;++i)scanf("%d%d%d",&a,&b,&l),ins(a,b,l),ins(b,a,l);

	maxs[0]=n;dfs(1);

	for(int i=1;i<=n;++i)for(int j=h[i];j;j=nxt[j])if(to[j]!=fa[i])ans+=Min(siz[to[j]],n-siz[to[j]])*len[j];\

	ans*=2;

	if(maxs[r1]==maxs[r2]){

		for(int j=h[r1];j;j=nxt[j])if(to[j]==r2)ans-=len[j];

		printf("%lld\n",ans);

	}

	else{

		r2=2147483647;for(int j=h[r1];j;j=nxt[j])r2=Min(r2,len[j]);

		printf("%lld\n",ans-r2);

	}

	return 0;

}