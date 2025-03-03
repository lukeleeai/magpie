#include "stdc++.h"

#define F first

#define S second



using namespace std;



int dis[105][105];

int n,m;

pair< pair<int,int> , int> ed[1005];



int main()

{

	cin >> n >> m;

	memset(dis,'?',sizeof dis);

	for(int i=0;i<m;i++)

	{

		cin >> ed[i].F.F >> ed[i].F.S >> ed[i].S;

		dis[ed[i].F.F][ed[i].F.S]=ed[i].S;

		dis[ed[i].F.S][ed[i].F.F]=ed[i].S;

	}

	for(int i=1;i<=n;i++) dis[i][i]=0;

	for(int k=1;k<=n;k++)

		for(int i=1;i<=n;i++)

			for(int j=1;j<=n;j++)

				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);

			int ans=0;

			for(int i=0;i<m;i++)

				ans+=dis[ed[i].F.F][ed[i].F.S]<ed[i].S;

			cout << ans << endl;

}