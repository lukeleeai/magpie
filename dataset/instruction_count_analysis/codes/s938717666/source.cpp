#include<cstdio>

#include<algorithm>

#define N (100005)

#define CM cerr<<(&MOP2-&MOP1)/1024.0/1024.0<<endl

using namespace std;

bool MOP1;

int n,m;

struct node{

	int cost,val;

	bool operator < (const node &a)const{

		return val>a.val;

	}

	void read(){

		scanf("%d%d",&cost,&val);

	}

}A[N];

int f[N];

int find(int x){

	return f[x]==x?x:f[x]=find(f[x]);

}

int ans;

bool MOP2;

int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)A[i].read();

	for(int i=1;i<=m+1;i++)f[i]=i;

	sort(A+1,A+1+n);

	for(int i=1;i<=n;i++){

		int c=A[i].cost;

		int v=A[i].val;

		if(c>m)continue;

		int now=find(f[c]);

		if(now>m)continue;

		ans+=v,f[now]++;

	}

	printf("%d\n",ans);

	return 0;

}








