#include<cstdio>

#include<algorithm>



#define	rep(i,n)	for(int i=0;i<n;i++)



using namespace std;



int main(){

	for(int n;scanf("%d",&n),n;){

		int a[101]={},r;

		rep(i,n)	scanf("%d",a+i+1);

		double b,v,e,f;	scanf("%lf%d%lf%lf%lf",&b,&r,&v,&e,&f);

		n++;



		static double t[10001];

		rep(x,a[n-1]){

			if(x<r)	t[x+1]=t[x]+1/(v-f*(r-x));

			else	t[x+1]=t[x]+1/(v-e*(x-r));

		}



		static double dp[101][10001];

		rep(i,n)rep(x,a[n-1]+1)	dp[i][x]=1e60;

		dp[0][0]=0;

		for(int i=1;i<n;i++){

			int dis=a[i]-a[i-1];

			for(int x=dis;x<=a[n-1];x++){

				dp[i][x]=min(dp[i][x],dp[i-1][x-dis]+t[x]-t[x-dis]);

				dp[i][0]=min(dp[i][0],dp[i][x]+b);

			}

		}



		printf("%.9f\n",*min_element(dp[n-1],dp[n-1]+a[n-1]+1));

	}



	return 0;

}