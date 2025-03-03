#include <iostream>

#include <cstring>

#include <string>

#include <algorithm>

#include <cstdlib>

#include <cstdio>

#include <map>

#include <set>

#include <cmath>

#include <vector>

#include <ctime>

#include <queue>

#include <sstream>

#include <utility>

#include <bitset>



using namespace std;



#define MP make_pair 

#define PB push_back 

#define INF (1000000007) 

#define eps 1e-8



typedef pair<int,int> pii ;

typedef long long ll ;



int n,m,k,X,Y;

char a[1005][1005];

int d[1005][1005];

int dx[]={0,0,1,0,-1},dy[]={0,1,0,-1,0};

vector<pii> v;

queue<pii> q;



void dfs(int x,int y)

{

	memset(d,-1,sizeof(d));

	d[x][y]=0;

	q.push(MP(x,y));

	while(!q.empty())

	{

		int tx=q.front().first;

		int ty=q.front().second;

		q.pop();

		for(int i=1;i<=4;i++)

		{

			int nx=tx+dx[i],ny=ty+dy[i];

			if(d[nx][ny]!=-1||nx<1||ny<1||nx>n||ny>m||a[nx][ny]!='.') continue;

			d[nx][ny]=d[tx][ty]+1;

			q.push(MP(nx,ny));

		}

	}

}



int main()

{

	cin>>n>>m>>k;

	for(int i=1;i<=n;i++)

	{

		for(int j=1;j<=m;j++)

		{

			cin>>a[i][j];

			if(a[i][j]=='S')

			{

				a[i][j]='.';

				X=i,Y=j;

			}

		}

	}

	dfs(X,Y);

	int mi=INF;

	for(X=1;X<=n;X++)

	{

		for(Y=1;Y<=m;Y++)

		{

//			cout<<d[X][Y]<<" ";

			if(d[X][Y]>k||d[X][Y]==-1) continue;

			mi=min(mi,n-X);

			mi=min(mi,m-Y);

			mi=min(mi,Y-1);

			mi=min(mi,X-1);

		}

//		cout<<endl;

	}

	cout<<1+(mi+k-1)/k;

	return 0;

}