#include<cstdio>

#include<queue>

#include<algorithm>

using namespace std;



char c[1001][1002];

int d[1000001];

int main(){

	int n,m;

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		scanf("%s",c[i]+1);

	queue<int>q;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			if(c[i][j]=='#'){

				q.push((i-1)*m+j);

				d[(i-1)*m+j]=1;

			}

	int ans=0;

	while(!q.empty()){

		int u=q.front();

		q.pop();

		ans=max(ans,d[u]);

		for(int i=0;i<4;i++){

			int v=u;

			if(i==0&&u<=m||i==1&&u%m==1%m||i==2&&u>=(n-1)*m+1||i==3&&u%m==0)

				continue;

			if(i==0)v-=m;

			else if(i==1)v--;

			else if(i==2)v+=m;

			else v++;

			if(!d[v]){

				d[v]=d[u]+1;

				q.push(v);

			}

		}

	}

	printf("%d\n",ans-1);

}