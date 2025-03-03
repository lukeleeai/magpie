#include<cstdio>

#include<algorithm>

#define int long long

const int N=200003;

int x[N],ans[N],g[N],n,m,k,used[N],siz;

signed main(){

	scanf("%lld",&n);

	for(int i=1;i<=n;i++)scanf("%lld",x+i),g[i]=i;

	for(int i=n;i;i--)x[i]-=x[i-1];

	scanf("%lld%lld",&m,&k);

	for(int i,j=1;j<=m;j++)scanf("%lld",&i),std::swap(g[i],g[i+1]);

	for(int i=1,j,v;i<=n;i++)if(!used[i]){

	  siz=1;

	  for(j=g[i];j!=i;j=g[j])

		siz++;

	  j=i;

	  for(int id=1;id<=k%siz;id++)j=g[j];

	  ans[i]=x[j],used[j]=1;

	  for(j=g[j],v=g[i];!used[j];j=g[j],v=g[v])

		ans[v]=x[j],used[j]=1;

	}

	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]+=ans[i-1]);

	return 0;

}