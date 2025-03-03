#include <cstdio>

#include <queue>

#include <map>

using namespace std;

#define N 2005

#define V 40005

#define Inf (1<<30) 

int n,m;

int a[N];

bool b[N][N];

int ans[N];

bool inAns[N];

int ansSz;

int lastNotCoprime[N];

int minOnSuff[N];

int comp[V];

vector<int> g[V];

int C;

int bestForCol[N];

map<int,int> primeId;

int gcd(int a,int b){

	if(b==0){

		return a;

	}

	return gcd(b,a%b);

}

int getId(int p){

	if(primeId.count(p)>0){

		return primeId[p];

	}

	primeId[p]=m;

	return m++;

}

void dfs(int v){

	comp[v]=C;

	int u;

	for(int i=0;i<(int)g[v].size();i++){

		u=g[v][i];

		if(comp[u]!=-1){

			continue;

		}

		if(u<n&&inAns[u]){

			continue;

		}

		dfs(u);

	}

}

void colors(){

	for(int i=0;i<m;i++){

		comp[i]=-1;

	}

	C=0;

	for(int i=0;i<n;i++){

		if(inAns[i]){

			continue;

		}

		if(comp[i]!=-1){

			continue;

		}

		dfs(i);

		C++;

	}

}

int mn(int a,int b){

	return a<b?a:b;

}

int main(){

	scanf("%d",&n);

	m=n;

	int x,id;

	for(int i=0;i<n;i++){

		scanf("%d",&a[i]);

		x=a[i];

		for(int j=2;j*j<=x;j++){

			if(x%j!=0){

				continue;

			}

			id=getId(j);

			g[i].push_back(id);

			g[id].push_back(i);

			while(x%j==0){

				x/=j;

			}

		}

		if(x>1){

			id=getId(x);

			g[i].push_back(id);

			g[id].push_back(i);

		}

	}

	for(int i=0;i<n;i++){

		for(int j=i+1;j<n;j++){

			if(gcd(a[i],a[j])>1){

				b[i][j]=b[j][i]=1;

			}

		}

	}

	for(int i=0;i<n;i++){

		lastNotCoprime[i]=-1;

	}

	for(int i=0;i<n;i++){

		minOnSuff[i]=Inf;

	}

	while(ansSz<n){

		colors();

		for(int i=0;i<C;i++){

			bestForCol[i]=-1;

		}

		for(int i=0;i<n;i++){

			if(inAns[i]){

				continue;

			}

			if(minOnSuff[lastNotCoprime[i]+1]<a[i]){

				continue;

			}

			if(bestForCol[comp[i]]==-1||a[bestForCol[comp[i]]]>a[i]){

				bestForCol[comp[i]]=i;

			}

		}

		id=-1;

		for(int i=0;i<C;i++){

			if(bestForCol[i]==-1){

				continue;

			}

			if(id==-1||a[id]<a[bestForCol[i]]){

				id=bestForCol[i];

			}

		}

		inAns[id]=1;

		ans[ansSz++]=a[id];

		for(int i=0;i<ansSz;i++){

			minOnSuff[i]=mn(minOnSuff[i],a[id]);

		}

		for(int i=0;i<n;i++){

			if(b[id][i]){

				lastNotCoprime[i]=ansSz-1;

			}

		}

	}

	for(int i=0;i<n;i++){

		printf("%d ",ans[i]);

	}

	puts("");

	return 0;

}
