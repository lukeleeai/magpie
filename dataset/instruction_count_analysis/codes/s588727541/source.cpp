#include "stdc++.h"

#define rep(i,n) for(int i=0;i<n;++i)

using namespace std;



int n,m,p;

int a[15][15];



long double dp[1<<14];

long double tmp[1<<14][14];



long double fact[1<<14][14];







int main(void){

	cin >> n >> m >> p;

	rep(i,m){

		int u,v;

		cin >> u >> v;

		a[u-1][v-1]++;

		a[v-1][u-1]++;

	}



	rep(i,n) fact[1<<i][0]=1.0;

	for(int mask=1;mask<(1<<n);++mask){

		for(int smask=(mask-1)&mask;;smask=(smask-1)&mask){

			int tmask=mask^smask;

			if(tmask>smask) break;

			rep(snum,n)rep(tnum,n) if(snum+tnum<n) fact[mask][snum+tnum+1]+=fact[smask][snum]*fact[tmask][tnum];

		}

	}

	

	// cerr << fact[3][1] << endl;

	// cerr << fact[7][2] << endl;

	// cerr << fact[15][3] << endl;



	/*

	for(int i=2;i<n;++i){

		fact[i]=1.0*(i+1)*i/2.0*fact[i-1]; 

		cerr << fact[i] << endl;

	}

	*/



	rep(i,n){

		rep(mask,1<<i)rep(j,i+1) tmp[mask][j]=0.0;



		for(int mask=1;mask<(1<<i);++mask){

			double cur=1.0;

			rep(j,i) if(mask&(1<<j)) rep(loop,a[j][i]) cur*=1.0*p/100.0; 

			tmp[mask][0]=(1.0-cur)*dp[mask];

		}

		

		

		for(int mask=1;mask<(1<<i);++mask){

			for(int smask=(mask-1)&mask;;smask=(smask-1)&mask){

				int tmask=mask^smask;

				if(tmask>smask) break;

				double cur=1.0;

				rep(j,i)rep(k,i) if((smask&(1<<j))&&(tmask&(1<<k))) rep(loop,a[j][k]) cur*=1.0*p/100.0;

				rep(snum,i+1)rep(tnum,i+1) if(snum+tnum<=i) tmp[mask][snum+tnum+1]+=cur*tmp[smask][snum]*tmp[tmask][tnum];

			}

		}



		tmp[0][0]=1.0;

		rep(mask,1<<i){

			for(int num=0;num<=i;++num){

				// cerr << mask << " " << num << " " << tmp[mask][num] << endl;

 				dp[mask|(1<<i)]+=tmp[mask][num]/fact[(1<<(num+1))-1][num];

			}

		}



	}

	cout.precision(20);

	cout << fixed << dp[(1<<n)-1] << endl;

	// rep(mask,1<<n) cerr << mask << " " << dp[mask] << endl;

	return 0;

}