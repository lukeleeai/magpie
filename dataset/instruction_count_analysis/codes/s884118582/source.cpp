#include<cstdio>

#include<cstring>

#include<vector>

using namespace std;

const int N=400002;

int n,m,i,a,b,c[N],vis[N],sum,tmp;

char s[N];

vector<int>e[N];

void Link(int x,int y){

	e[x].push_back(y);

	e[y].push_back(x);

}

void init(){

	scanf("%s%d",s+1,&m);

	n=strlen(s+1);

	for(i=0;i<=n;i++)

		c[i]=s[i+1]-s[i];

	for(i=0;i<n-i;i++)

		Link(i,n-i);

	while(m--){

		scanf("%d%d",&a,&b);

		Link(a-1,b);

	}	

}

void dfs(int i){

	vis[i]=1;

	sum+=c[i];

	for(int j=0;j<e[i].size();j++)

		if(!vis[e[i][j]])

			dfs(e[i][j]);

}

void work(){

	tmp=1;

	dfs(0);

	sum=0;

	for(i=1;i<n;i++)

		if(!vis[i]){

			dfs(i);

			if(sum%26)

				tmp=0;

		}

	printf("%s\n",tmp?"YES":"NO");

}

int main(){

	init();

	work();

	return 0;

}