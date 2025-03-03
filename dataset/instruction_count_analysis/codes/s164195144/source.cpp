#include<cstdio>

const int N=400002;

char s[N];

int n,m,c[N],a,b,i,j,k,p;

int h[N],t[N],v[N],vis[N];

void add(int a,int b){

	t[++k]=h[a];h[a]=k;v[k]=b;

	t[++k]=h[b];h[b]=k;v[k]=a;

}

void init(){

	scanf("%s",s+1);

	while(s[n+1])n++;

	for(i=1;i<=n+1;i++)

		c[i]=s[i]-s[i-1];

	for(i=1,j=n+1;i<j;i++,j--)

		add(i,j);

	scanf("%d",&m);

	while(m--){

		scanf("%d%d",&a,&b);

		add(a,b+1);

	}

}

void dfs(int i){

	vis[i]=1;

	p+=c[i];

	for(int j=h[i];j;j=t[j])

		if(!vis[v[j]])

			dfs(v[j]);

}

void work(){

	dfs(n+1);

	for(i=1;i<=n;i++)

		if(!vis[i]){

			p=0;

			dfs(i);

			if(p%26!=0){

				printf("NO\n");

				return;

			}

		}

	printf("YES\n");

}

int main(){

	init();

	work();

	return 0;

}