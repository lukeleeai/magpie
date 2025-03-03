#include"stdc++.h"

using namespace std;

const int N=305;

int a[N][N];

bool b[N];

queue<int>f[N];

int n,m;

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			scanf("%d",&a[i][j]);

	for(int i=1;i<=n;i++)

		f[a[i][1]].push(i),a[i][0]=1;

	memset(b,true,sizeof(b));

	int ret=0;

	for(int i=1;i<=m;i++)

		if(f[i].size()>ret)ret=f[i].size();

	int ans=ret;

	while(1){

		int k=-1;

		for(int i=1;i<=m;i++)

			if(k==-1||f[i].size()>f[k].size())k=i;

		if(k==-1)break;

		b[k]=false;

		while(!f[k].empty()){

			int i=f[k].front();

			f[k].pop();

			while(!b[a[i][a[i][0]]])a[i][0]++;

			f[a[i][a[i][0]]].push(i);

		}

		int ret=0;

		for(int i=1;i<=m;i++)

			if(f[i].size()>ret)ret=f[i].size();

		if(ret==0)break;

		ans=min(ans,ret);

	}

	printf("%d",ans);

	return 0;

}