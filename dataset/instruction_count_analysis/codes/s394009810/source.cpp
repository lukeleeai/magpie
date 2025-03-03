#pragma GCC optimize(2)

#include"stdc++.h"

using namespace std;

const int N=100005;

int vis[N];

vector<int>e[N],p1,p2;

deque<int>dq;

int main()

{

	int n,m,a,b,res,k;

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++)

	{

		scanf("%d%d",&a,&b);

		e[a].push_back(b);

		e[b].push_back(a);

	}

	int r=1;

	vis[r]=1;

	dq.push_back(r);

	do

	{

		res=0;

		k=dq.front();

		vis[k]=1;

		p1.push_back(k);

		for(int i=0;i<e[k].size();i++)

		{

			if(!vis[e[k][i]])

			{

				dq.push_front(e[k][i]);

				res=1;

				break;

			}

		}

	}while(res);

	do

	{

		res=0;

		k=dq.back();

		vis[k]=1;

		p2.push_back(k);

		for(int i=0;i<e[k].size();i++)

		{

			if(!vis[e[k][i]])

			{

				dq.push_back(e[k][i]);

				res=1;

				break;

			}

		}

	}while(res);

	printf("%d\n",p1.size()+p2.size()-1);

	for(int i=p1.size()-1;i>=0;i--)

		printf("%d ",p1[i]);

	for(int i=1;i<p2.size();i++)

		printf("%d ",p2[i]);

	printf("\n");

	return 0;

}
