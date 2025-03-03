#include<cstdio>

#include<vector>

#include<algorithm>

#define MAXN 200006

using namespace std;

int d[MAXN],n,a,b;

vector<int> road[MAXN];

void DFS(int x,int fa)

{

	int ok=0;

	for(int i=0;i<(int)road[x].size();i++)

	{

		int nex=road[x][i];

		if(nex==fa) continue;

		DFS(nex,x);

		if(d[nex]==0)

		{

			if(ok==0) ok=1;

			else d[x]++;

		}

		else d[x]+=d[nex];

	}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		scanf("%d%d",&a,&b);

		a++;

		b++;

		road[a].push_back(b);

		road[b].push_back(a);

	}

	int st=0;

	for(int i=1;i<=n;i++)

	{

		if(road[i].size()>=3)

		{

			st=i;

			break;

		}

	}

	if(st==0) printf("1");

	else 

	{

		DFS(st,0);

		printf("%d",d[st]);

	}

}