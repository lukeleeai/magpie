#include"stdc++.h"

#define maxn 605

#define rep(i,j,k) for(int i=(j),LIM=(k);i<=LIM;i++)

#define per(i,j,k) for(int i=(j),LIM=(k);i>=LIM;i--)

#define LL long long

using namespace std;



int n;

int mod;

int f[2][maxn];

int up[maxn],dn[maxn],d[maxn],c[maxn];

bool cmp(const int &u,const int &v){ return d[u] < d[v]; }



int main(){

	scanf("%d%d",&n,&mod);

	rep(i,0,2*n-1) up[i] = min((int)floor(sqrt(4 * n * n - i * i)),2*n-1) , dn[i] = (i <= n ? (int)ceil(sqrt(n * n - i * i)) : 0);

	rep(i,0,n-1) d[i] = dn[i] - 1;

	rep(i,n,2*n-1) d[i] = up[i];

	rep(i,0,2*n-1) c[i] = 2*n-i-1;

	stable_sort(c,c+2*n,cmp);int ans =0 ;

	rep(k,0,n){

		memset(f,0,sizeof f);

		int now = 1, pre = 0 , cntr = 0;

		f[now][0] = 1;

		rep(i,0,2*n-1){

			int u = c[i];

			swap(now,pre);

			rep(j,0,k) if(f[pre][j]){

				if(u >= n){	

					f[now][j] = (f[now][j] + 1ll * f[pre][j] * max(up[u] + 1 - i + (cntr - j), 0)) % mod;

				}

				else{

					f[now][j] = (f[now][j] + 1ll * f[pre][j] * max(up[u] + 1 - n - (k-j) - cntr , 0)) % mod;

					if(j < k) f[now][j+1] = (f[now][j+1] + 1ll * f[pre][j] * max(dn[u] - i + (cntr - j) , 0)) % mod;

				}

				f[pre][j] = 0;

			}

			if(u < n) cntr ++;

		}

		ans = (ans + (k&1?-1ll:1ll) * f[now][k]) % mod;

	}

	printf("%d\n",(ans+mod)%mod);

}