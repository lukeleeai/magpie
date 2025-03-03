#include "stdc++.h"

#define eps 1e-3

#define pi acos(-1.0)

#define inf 0x3f

#define INF 0x3f3f3f3f

#define pb push_back

#define debug1 cout<<"&&";

#define debug2 cout<<"**";

#define ms(a, x) memset(a, x, sizeof(a))

#define for0(i, n) for(int i = 0; i < n; ++i)

#define for1(i, n) for(int i = 1; i <= n; ++i)

using namespace std;

typedef double db;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> pii;

typedef pair<long long, int> pli;

typedef pair<long long, long long> pll;

const int mod = 1e9 + 7;

const int N = 1e5+10;

const int M = 1e6+10;

/*=================================================================================*/



int n, tot, head[N], ver[N<<2], nex[N<<2];

ll dp[N][2];



void add(int x, int y) {

   ver[++tot] = y;

   nex[tot] = head[x];

   head[x] = tot;

}



void dfs(int x, int fa) {

   ll a = 1, b = 1;

   if(nex[head[x]] == 0 && ver[head[x]] == fa) {

      dp[x][0] = dp[x][1] = 1;

      return;

   }

   for(int i = head[x]; i; i = nex[i]) {

      int y = ver[i];

      if(y == fa) continue;

      dfs(y, x);

      a = (a * ((dp[y][0] + dp[y][1]) % mod)) % mod;

      b = (b * dp[y][0]) % mod;

   }

   dp[x][0] = a, dp[x][1] = b;

}



int main() {

   cin>>n;

   for0(i, n-1) {

      int x, y;

      scanf("%d %d", &x, &y);

      add(x, y), add(y, x);

   }

   dfs(1, 0);

   cout << (dp[1][0] + dp[1][1]) % mod << endl;

   return 0;

}