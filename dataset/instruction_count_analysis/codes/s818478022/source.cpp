/*Lucky_Glass*/

#include<cstdio>

#include<cstring>

#include<algorithm>

//#include<iostream>

#include<cmath>

#include<vector>

#include<queue>

using namespace std;

const int MAXN=1e5;

int n_pnt,n_edg;

struct NODE{

	int p,val;//val+p*x>0

	NODE(){}

	NODE(int a,int b){p=a;val=b;}

};

struct QUEUE{

	int u,p;//val+p*x>0

	long long val;

	QUEUE(){}

	QUEUE(int a,int b,long long c){u=a;p=b;val=c;}

};

vector<pair<int,int> > lnk[MAXN+5];

long long vis[2][MAXN+5];//vis[0][i]-x>0 && vis[1][i]+x>0 -> x<vis[0] && x>-vis[1]

inline int G(int p){return p==1;}

long long MIN=-1e15,MAX=1e15;

int main()

{

	fill(vis[0],vis[0]+MAXN+5,1e15);

	fill(vis[1],vis[1]+MAXN+5,1e15);

	scanf("%d%d",&n_pnt,&n_edg);

	for(int i=0,u,v,l;i<n_edg;i++)

		scanf("%d%d%d",&u,&v,&l),

		lnk[u].push_back(make_pair(v,l)),lnk[v].push_back(make_pair(u,l));

	queue<QUEUE> que;

	que.push(QUEUE(1,1,0));

	while(!que.empty())

	{

		QUEUE fro=que.front();que.pop();

		for(int i=0;i<lnk[fro.u].size();i++)

		{

			int v=lnk[fro.u][i].first,l=lnk[fro.u][i].second;

			long long val=l-fro.val;int p=fro.p==1? -1:1;

			if(vis[G(p)][v]!=1e15)

			{

				if(val!=vis[G(p)][v])

				{

					printf("%d\n",0);

					return 0;

				}

				else

					continue;

			}

			vis[G(p)][v]=val;

			if(G(p))

				MIN=max(MIN,max((long long)0,-vis[1][v]));

			else

				MAX=min(MAX,vis[0][v]);

			que.push(QUEUE(v,p,val));

		}

	}

	long long ans=-1;

	for(int i=1;i<=n_pnt;i++)

		if(vis[0][i]!=1e15 && vis[1][i]!=1e15)

		{

			int res=(vis[0][i]-vis[1][i])/2;

			if(res<0) {printf("0\n");return 0;}

			if(ans==-1) ans=res;

			if(ans!=res) {printf("0\n");return 0;}

		}

	if(ans!=-1)

	{

		if(MIN<ans && ans<MAX)

			printf("%d\n",1);

		else

			printf("%d\n",0);

		return 0;

	}

	if(MAX-MIN-1<0) printf("%d\n",0);

	else printf("%lld\n",MAX-MIN-1);

	return 0;

}

/*

2 1

1 2 3

*/
