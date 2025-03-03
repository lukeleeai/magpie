#include <cstdio>

#include <algorithm>

using namespace std;

int n,m,x;

int c[15],a[15][15],b[15],d[15],len,sum=100000000,cost;

void dfs(int step){

	int i,j,k;

	if(step==len+1){

		for(k=1;k<=m;k++)d[k]=0;

		for(j=1;j<=len;j++)

			for(k=1;k<=m;k++)

				d[k]+=a[b[j]][k];

		for(k=1;k<=m;k++)

			if(d[k]<x)return;

		cost=0;

		for(j=1;j<=len;j++)cost+=c[b[j]];

		sum=min(sum,cost);

		return ;

	}

	for(i=b[step-1]+1;i<=n;i++)

		b[step]=i,dfs(step+1);

}

int main(){

	int i,j;

	scanf("%d%d%d",&n,&m,&x);

	for(i=1;i<=n;i++)

	{

		scanf("%d",&c[i]);

		for(j=1;j<=m;j++)

			scanf("%d",&a[i][j]);

	}

	for(len=1;len<=n;len++)

		b[0]=0,dfs(1);

	if(sum==100000000)printf("-1\n");

	else printf("%d\n",sum);

	return 0;

}