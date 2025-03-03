#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm> //Algorithm

#include <vector>

#include <map>

//#define ll long long



using namespace std;



const int maxn=1000+10;



vector <int>da[200];

int d1[100],d2[100];

int vis[100];

int a,b;

int dfs(int s,int d)

{

	if(s==d)

	{

		

		return 1;

	}

	

	vis[s]=1;

	int mm=da[s].size();

	for(int i=0;i<mm;i++)

	{

		int v=da[s][i];

		if(s==a&&v==b||s==b&&v==a)

			continue;

		if(!vis[v])

		{

			if(dfs(v,d)==1)

			{

				return 1;

			}

		}

	}

	return 0;

}





int main()

{

	int n,m;

	int ans=0;

	int f;

	scanf("%d%d",&n,&m);

	for(int i=0; i<m; i++)

	{

		scanf("%d%d",&a,&b);

		d1[i]=a;

		d2[i]=b;

		da[b].push_back(a);

		da[a].push_back(b);

	}

	for(int i=0; i<m; i++)

	{

		a=d1[i];

		b=d2[i];

		f=0;

		

		for(int s=1; s<=n; s++)

		{

			for(int d=1; d<=n; d++)

			{

				memset(vis,0,sizeof(vis));

				if(dfs(s,d)==0)

				{

					ans++;

					f=1;

					break;

				}

			}

			if(f)

				break;

		}

	}

	cout<<ans<<endl;

	return 0;

}
