#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <climits>

#include <cmath>

#include <cassert>

#include <iostream>

#include <sstream>

#include <iomanip>

#include <algorithm>

#include <numeric>

#include <complex>

#include <list>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <bitset>

#include <utility>

#include <functional>

#include <iterator>



using namespace std;



#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)

#define peri(i,a,b) for(int i=int(b);i-->int(a);)

#define rep(i,n) repi(i,0,n)

#define per(i,n) peri(i,0,n)

#define iter(c) __typeof__((c).begin())

#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)

#define all(c) (c).begin(),(c).end()

#define mp make_pair



typedef unsigned int uint;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<double> vd;

typedef vector<vd> vvd;

typedef vector<string> vs;

typedef pair<int,int> pii;



template<typename T>

void chmax(T& a,const T& b)

{

	a=max(a,b);

}



int main()

{

	for(int c,d,w,x;scanf("%d%d%d%d",&c,&d,&w,&x),c|d|w|x;){

		static int e[30][15],f[30][15];

		rep(i,c) rep(j,d) scanf("%d",&e[j][i]);

		rep(i,c) rep(j,d) scanf("%d",&f[j][i]);

		

		static int dp[31][6][201]; // [日][2回以上ライブを行った回数][疲労]

		memset(dp,-1,sizeof dp);

		

		dp[0][0][0]=0;

		rep(i,d) rep(j,x+1) rep(k,w+1){

			if(dp[i][j][k]==-1) continue;

			rep(l,c){

				chmax(dp[i+1][j][k],dp[i][j][k]);

				chmax(dp[i+1][j][k+f[i][l]],dp[i][j][k]+e[i][l]);

			}

			if(j==x) continue;

			rep(l,c){

				if(e[i][l]==0) continue;

				int esum=e[i][l],fsum=f[i][l];

				repi(r,l+1,c){

					if(e[i][r]==0) break;

					esum+=e[i][r];

					fsum+=f[i][r];

					chmax(dp[i+1][j+1][k+fsum],dp[i][j][k]+esum);

				}

			}

		}

		

		int res=0;

		rep(i,x+1) rep(j,w+1)

			chmax(res,dp[d][i][j]);

		printf("%d\n",res);

	}

	

	return 0;

}