#include<cstdio>

const int N=100005;

int n,v[N],he[N],to[N*2],nx[N*2],d[N],fa[N];

inline void wk(int w,int x,int y)

{to[w]=y,nx[w]=he[x],he[x]=w;}

inline int imx(int x,int y){return x>y?x:y;}

int dfs(int x)

{

	int a=0,b=0,c=0;

	for(int i=he[x],y;i;i=nx[i])if((y=to[i])!=fa[x])

	{c=1,fa[y]=x;if(!dfs(y))return 0;a+=v[y],b=imx(b,v[y]);}

	if(!c)return 1;

	if(v[x]>a||v[x]<a-v[x]||a-v[x]>a-b)return 0;//

	v[x]-=a-v[x];return 1;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;++i)

		scanf("%d",&v[i]);

	for(int i=1,x,y;i<n;++i)

		scanf("%d%d",&x,&y),++d[x],++d[y],

		wk(i*2,x,y),wk(i*2+1,y,x);

	if(n==2){v[1]==v[2]?printf("YES"):printf("NO");return 0;}

	for(int i=1;i<=n;++i)if(d[i]==1)

	{dfs(i)?printf("YES"):printf("NO");return 0;}

	return 0;

}