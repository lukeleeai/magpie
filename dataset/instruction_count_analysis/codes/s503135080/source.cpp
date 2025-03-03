#include"stdc++.h"

using namespace std;



int read(){

	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();

	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;

}



const int _ = 2e5 + 7 , MOD = 998244353 , iv2 = (MOD + 1) / 2;

struct Edge{int end , upEd;}Ed[_ << 1];

int dp[_][3][3] , N , cntEd , head[_];

void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}



int mx , id , pre[_];

void dfs1(int x , int p , int l){

	pre[x] = p; if(l > mx){mx = l; id = x;}

	for(int i = head[x] ; i ; i = Ed[i].upEd)

		if(Ed[i].end != p) dfs1(Ed[i].end , x , l + 1);

}



int mxdep[_];

void dfs2(int x , int p){

	for(int i = head[x] ; i ; i = Ed[i].upEd)

		if(Ed[i].end != p){dfs2(Ed[i].end , x); mxdep[x] = max(mxdep[x] , mxdep[Ed[i].end] + 1);}

}



void DP(int x , int p){

	dp[x][0][0] = 1; bool flg = 0;

	for(int i = head[x] ; i ; i = Ed[i].upEd)

		if(Ed[i].end != p){

			flg = 1; DP(Ed[i].end , x); static int tmp[3][3]; memset(tmp , 0 , sizeof(tmp));

			for(int j = 0 ; j < 3 ; ++j)

				for(int k = 0 ; k < 3 ; ++k)

					for(int p = 0 ; p < 3 ; ++p)

						for(int q = 0 ; q < 3 ; ++q){

							int coef = 3;

							if(mxdep[Ed[i].end] + 1 == mxdep[x]){

								tmp[min(j + p , 2)][k] = (tmp[min(j + p , 2)][k] + 1ll * dp[x][j][k] * dp[Ed[i].end][p][q]) % MOD;

								tmp[j][min(k + q , 2)] = (tmp[j][min(k + q , 2)] + 1ll * dp[x][j][k] * dp[Ed[i].end][p][q]) % MOD;

								coef -= 2;

							}

							tmp[j][k] = (tmp[j][k] + 1ll * coef * dp[x][j][k] * dp[Ed[i].end][p][q]) % MOD;

						}

			memcpy(dp[x] , tmp , sizeof(tmp));

		}

	if(!flg){dp[x][0][0] = 0; dp[x][1][1] = 1;}

}



int main(){

	N = read(); for(int i = 1 ; i < N ; ++i){int x = read() , y = read(); addEd(x , y); addEd(y , x);}

	dfs1(1 , 0 , 0); mx = 0; int t = id; dfs1(t , 0 , 0);

	for(int i = 0 ; i < mx / 2 ; ++i) id = pre[id];

	if(mx & 1){

		dfs2(id , pre[id]); DP(id , pre[id]); dfs2(pre[id] , id); DP(pre[id] , id); int sum = 0;

		for(int i = 0 ; i < 3 ; ++i)

			for(int j = 0 ; j < 3 ; ++j)

				for(int k = 0 ; k < 3 ; ++k)

					for(int l = 0 ; l < 3 ; ++l){

						if(i == 1 && l == 1) sum = (sum + 1ll * dp[id][i][j] * dp[pre[id]][k][l]) % MOD;

						if(j == 1 && k == 1) sum = (sum + 1ll * dp[id][i][j] * dp[pre[id]][k][l]) % MOD;

					}

		printf("%lld\n" , 1ll * sum * iv2 % MOD);

	}else{dfs2(id , 0); DP(id , 0); printf("%lld\n" , 1ll * iv2 * dp[id][1][1] % MOD);}

	return 0;

}
