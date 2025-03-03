#include<cstdio>

#include<iostream>

#include<vector>

#include<string>

#include<queue>

#include<complex>

#include<set>

#include<map>

#include<algorithm>



using namespace std;



#define reps(i,f,n) for(int i=f;i<int(n);i++)

#define rep(i,n) reps(i,0,n)



const int R = 22;

const int N = 101;

const int INF = 1000000000;

const int M = N*222;



int n,m,r,s,g;



int cost[R][M];

int dplen[R][N][N];

int dpcost[N][N];



void init(){

	reps(i,1,r+1){

		reps(j,1,n+1)reps(k,1,n+1)dplen[i][j][k]=INF;

		reps(j,1,n+1)dplen[i][j][j]=0;

	}

	reps(i,1,n+1)reps(j,1,n+1)dpcost[i][j]=INF;

}



void wf_length(){

	reps(p,1,r+1){

		reps(k,1,n+1){

			reps(i,1,n+1){

				reps(j,1,n+1){

					dplen[p][i][j] = min(dplen[p][i][j], dplen[p][i][k] + dplen[p][k][j]);

				}

			}

		}

	}

}



void wf_cost(){

	reps(k,1,r+1){

		reps(i,1,n+1){

			reps(j,1,n+1){

				if(dplen[k][i][j]==INF)continue;

				dpcost[i][j] = min(dpcost[i][j], cost[k][dplen[k][i][j]]);

			}

		}

	}

	

	reps(k,1,n+1){

		reps(i,1,n+1){

			reps(j,1,n+1){

				dpcost[i][j] = min(dpcost[i][j], dpcost[i][k]+dpcost[k][j]);

			}

		}

	}

}

int solve(){

	init();

	

	rep(i,m){

		int a,b,c,d;

		cin>>a>>b>>c>>d;

		dplen[d][a][b] = min(dplen[d][a][b],c);

		dplen[d][b][a] = min(dplen[d][b][a],c);

	}

	

	

	int p[R];

	reps(i,1,r+1)cin>>p[i];

	reps(i,1,r+1){

		int change[55];

		int c[55];

		rep(j,p[i]-1)cin>>change[j];

		rep(j,p[i])cin>>c[j];

		

		int pos = 0;

		reps(j,1,M){

			cost[i][j] = cost[i][j-1]+c[pos];

			if(pos!=p[i]-1 && j==change[pos])pos++;

		}

	}

	

	wf_length();

	wf_cost();

	

	int ans = dpcost[s][g];

	if(ans==INF)return -1;

	return ans;

}



int main(){

	while(1){

		cin>>n>>m>>r>>s>>g;

		if(n==0 && m==0)break;

		printf("%d\n",solve());

		//break;

	}

}