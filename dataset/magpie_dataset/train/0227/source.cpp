#include <iostream>

#include <vector>



using namespace std;



typedef vector<int> vi;

typedef vector<vi> vvi;



const int INFTY=1<<29;



int main()

{

	for(int h,w;cin>>h>>w,h|w;){

		int n=h*w;

		vvi dist(n,vi(n,INFTY));

		vi hearts;

		for(int i=0;i<h;i++){

			for(int j=0;j<w;j++){

				int x; cin>>x;

				if(x==1)

					hearts.push_back(i*w+j);

				

				dist[i*w+j][i*w+j]=0;

				int di[]={-1,1,0,0},dj[]={0,0,-1,1};

				for(int k=0;k<4;k++){

					int ii=i+di[k],jj=j+dj[k];

					if(0<=ii && ii<h && 0<=jj && jj<w)

						dist[i*w+j][ii*w+jj]=dist[ii*w+jj][i*w+j]=1;

				}

			}

		}

		

		for(int k=0;k<n;k++)

			for(int i=0;i<n;i++)

				for(int j=0;j<n;j++)

					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

		

		int hsize=hearts.size();

		vvi dp(1<<hsize,vi(n,INFTY));

		for(int i=0;i<hsize;i++)

			for(int j=0;j<n;j++)

				dp[1<<i][j]=dist[hearts[i]][j];

		

		for(int i=0;i<(1<<hsize);i++){

			for(int j=i;j;j=(j-1)&i)

				for(int k=0;k<n;k++)

					dp[i][k]=min(dp[i][k],dp[j][k]+dp[i^j][k]);

			for(int j=0;j<n;j++)

				for(int k=0;k<n;k++)

					dp[i][j]=min(dp[i][j],dp[i][k]+dist[k][j]);

		}

		

		int res=INFTY;

		for(int i=0;i<n;i++)

			res=min(res,dp[(1<<hsize)-1][i]);

		cout<<n-(res+1)<<endl;

	}

	

	return 0;

}