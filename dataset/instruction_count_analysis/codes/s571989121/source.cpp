#include"stdc++.h"

using namespace std;

const int N=100005;

int l[N],r[N],v[N];

vector<int> path[N];

bool bo;

void dfs1(int o,int fa)

{

	if(v[o]>=0) l[o]=r[o]=v[o];

	for(int i=0;i<(int)path[o].size();i++)

	{

		int to=path[o][i];

		if(to==fa) continue;

		dfs1(to,o);

		

		

		

		if(l[to]==INT_MIN) continue;

		

		//cout<<"#"<<o<<" "<<to<<" "<<l[o]<<" "<<r[o]<<" "<<l[to]<<" "<<r[to]<<endl;

		

		if(l[o]==INT_MIN) l[o]=l[to]-1,r[o]=r[to]+1;

		else 

		{

			if(r[o]%2!=(r[to]+1)%2) bo=true;

			l[o]=max(l[o],l[to]-1);

			r[o]=min(r[o],r[to]+1);

		}

		if(l[o]>r[o]) bo=true;

	}

}

void dfs2(int o,int fa)

{

	for(int i=0;i<(int)path[o].size();i++)

	{

		int to=path[o][i];

		if(to==fa) continue;

		if(v[o]-1>=l[to]) v[to]=v[o]-1;

		else v[to]=v[o]+1;

		dfs2(to,o);

	}

}

int main()

{

	memset(v,-1,sizeof(v));

	int n,k,a,b;

	scanf("%d",&n);

	for(int i=1;i<n;i++) 

	{

		scanf("%d%d",&a,&b);

		path[a].push_back(b);

		path[b].push_back(a);

		l[i]=INT_MIN;

		r[i]=INT_MAX;

	}

	l[n]=INT_MIN;

	r[n]=INT_MAX;

	scanf("%d",&k);

	while(k--)

	{

		scanf("%d%d",&a,&b);

		v[a]=b;

	}

	dfs1(1,0);

	if(bo) {puts("No");return 0;}

	puts("Yes");

	v[1]=l[1];

	dfs2(1,0);

	for(int i=1;i<=n;i++) printf("%d\n",v[i]);

	return 0;

}