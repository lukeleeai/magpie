#include "stdc++.h"

#define int long long

#define mod 1000000007

using namespace std;

typedef long long ll;

int N,K;

int C[1005][1005], fac[1005], inv[1005];

int L[75];

int tot;

queue<int> Q;

int nextt[75], que[75];

int vis[75];



int qpow(int a, int b) {

	int res = 1;

	while(b) {

		if(b&1) res=res*a%mod;

		b>>=1;

		a=a*a%mod;

	}

	return res;

}

void init() {

	C[0][0] = 1;

	for(int i = 1 ; i <= 1000 ; i++) {

		C[i][0] = 1;

		for(int j = 1 ; j <= i ; j++) {

			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

			C[i][j] %= mod;

		}

	}

	fac[0] = 1;

	for(int i = 1 ; i <= 1000 ; i++) fac[i] = fac[i - 1]*i%mod;

	inv[1000] = qpow(fac[1000],mod-2);

	for(int i = 999 ; i >= 0 ; i--) inv[i] = inv[i + 1]*(i + 1)%mod;

}



bool check(int cnt) {

	if(tot < cnt) return false;

	int sum[75];

	memset(sum,0,sizeof(sum));

	int p = 1;

	for(int i = cnt ; i >= 1 ; i--) {

		sum[que[i]]++;

		if(L[p] >= 2) {

			if(nextt[que[i]]==0) return false;

			sum[nextt[que[i]]] += L[p] - 1;

		}

		p++;

	}

	for(int i = K ; i >= 1 ; i--) {

		sum[i] += sum[i + 1];

	}

	for(int i = K; i >= 1; i--) {

		if(sum[i] > K - i + 1) return false;

	}

	return true;

}



int ans=0;

bool dfs(int pre,int dep,int len) {

	if(len > N) return false;

	if(!check(dep)) return false;

	

	int k = dep + 1;

	for(int i = 1 ; i <= dep ; i++) {

		if(L[i] == 1) k++;

		else k += 2 * L[i] - 1;

	}

	int cnt = C[N + k - len  - 1][k - 1] * fac[dep]%mod;

	

	int count = 1;

	

	for(int i = 2 ; i <= dep ; i++) {

		if(L[i] != L[i - 1]) {

			cnt = cnt * inv[count] % mod;

			count = 0;

		}

		count++;

	}

	

	cnt = cnt * inv[count]%mod;

	ans += cnt;

	ans %= mod;

	ans = (ans + mod)%mod;

	

	

	if(dep >= tot) return true;

	for(int i = pre ; i <= 70 ; i++) {

		int tmp = len;

		if(dep != 0) tmp++;

		if(i == 1 || i == 2) tmp++;

		else tmp += 2 * i - 3;

		L[dep + 1] = i;

		if(!dfs(i,dep + 1,tmp)) break;

	}

	return true;

}



char s[75];

signed main() {

	init();

	cin >> N >> K;

	scanf("%s",s + 1);

	tot = 0;

	for(int i = 1 ; i <= K ; i++) {

		if(s[i] == 'r') {

			que[++tot] = i;

			for(int j = i ; j <= K ; j++) {

				if(s[j] == 'b' && !vis[j]) {

					nextt[i] = j;

					vis[j] = 1;

					break;

				}

			}

		}

	}

	dfs(1,0,0);

	cout << ans << endl;

	return 0;

}