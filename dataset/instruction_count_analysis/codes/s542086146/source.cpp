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



		static double dp[101][101];

		rep(i,n)rep(j,n)	dp[i][j]=1e60;

		dp[0][0]=0;

		for(int i=1;i<n;i++){

			rep(j,i){

				int dis=a[i]-a[j];

				dp[i][j]=min(dp[i][j],dp[j][j]+t[dis]);

				dp[i][i]=min(dp[i][i],dp[i][j]+b);

			}

		}



		printf("%.9f\n",*min_element(dp[n-1],dp[n-1]+n));

	}



	return 0;

}