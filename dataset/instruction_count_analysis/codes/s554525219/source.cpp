//二维前缀和+子矩阵和+深搜行+枚举列+注意行边界处理+注意列边界处理

#include <cstdio>

#include <algorithm>

using namespace std;

int a[12],sum[12][1010];

int H,W,K,ans=2000;

char s[12][1010];

int judge(int cnt,int la,int j){//num>K 1,num<=K 0

	int i,num;

	a[cnt+1]=H;//此句很关键，事关最后的行边界。

	for(i=1;i<=cnt+1;i++){

		num=sum[a[i]][j]-sum[a[i]][la]-sum[a[i-1]][j]+sum[a[i-1]][la];

		if(num>K) return 1;

	}

	return 0;

}

void solve(int cnt){

	int j,tot,la;

	tot=cnt,la=0;

	for(j=1;j<=W;j++)

		if(judge(cnt,la,j))tot++,la=j-1;

	if(!judge(cnt,W-1,W))ans=min(ans,tot);//此句判断关键，事关最后的列边界

}

void dfs(int step,int cnt){//step代表dfs执行步数，cnt代表对行进行切割的刀数

	if(step==H){

		solve(cnt);

		return;

	}

	//以下写法对应着C(n,0),C(n,1),C(n,2),...,C(n,n-1),C(n,n)等情况

	dfs(step+1,cnt);

	a[cnt+1]=step,dfs(step+1,cnt+1);

	

}

int main(){

	int i,j;

	scanf("%d%d%d",&H,&W,&K);

	for(i=1;i<=H;i++)scanf("%s",s[i]+1);

	for(i=1;i<=H;i++)

		for(j=1;j<=W;j++)

			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+s[i][j]-'0';//二维前缀和

	dfs(1,0);

	printf("%d\n",ans);

	return 0;

}