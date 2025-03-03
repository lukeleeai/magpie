#include <cstdio>

#include <algorithm>

using namespace std;

int n,m,x;

int c[15],a[15][15],b[15],d[15],len,sum=100000000,cost;

void init(){//数据读取

	int i,j;

	scanf("%d%d%d",&n,&m,&x);

	for(i=1;i<=n;i++){

		scanf("%d",&c[i]);

		for(j=1;j<=m;j++)

			scanf("%d",&a[i][j]);

	}

}

void dfs(int step){

	int i,j,k;

	if(step==len+1){//深搜结束条件

		for(k=1;k<=m;k++)d[k]=0;//d[k]表示被选择的书店，在k列位置上的和

		for(j=1;j<=len;j++)

			for(k=1;k<=m;k++)

				d[k]+=a[b[j]][k];//计算被选择的书店，在k列位置上的和

		for(k=1;k<=m;k++)

			if(d[k]<x)return;//不满足条件

		cost=0;

		for(j=1;j<=len;j++)cost+=c[b[j]];//计算花费

		sum=min(sum,cost);//找最小值

		return ;

	}

	for(i=b[step-1]+1;i<=n;i++)//找组合情况，就让后查找的位置越来越大，请注意i=b[step-1]+1

		b[step]=i,dfs(step+1);

}

int main(){

	init();

	for(len=1;len<=n;len++)//len界定选择的书店的数量

		b[0]=0,dfs(1);

	if(sum==100000000)printf("-1\n");//没找到

	else printf("%d\n",sum);

	return 0;

}