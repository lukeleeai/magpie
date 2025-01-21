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

const int N = 50;

const int M = 1e5+10;

/*=================================================================================*/



int n, a[N][N], con[N];

ll ans, dp[M], tmp[M];



int main() {

   scanf("%d", &n);

   for0(i, n) for0(j, n) scanf("%d", &a[i][j]);



   for0(now, (1<<n)) {

      int cnt = 0;

      for0(i, 16)

         if(now & (1<<i)) {

            con[cnt++] = i;

         }

      ll sum = 0;

      for0(i, cnt) for(int j = i + 1; j < cnt; ++j) {

         sum += a[con[i]][con[j]];

      }

      dp[now] = tmp[now] = sum;

   }



   for0(now, (1<<n)) for(int last = now; last; last = (last-1) & now) {

      dp[now] = max(dp[now], dp[now ^ last] + tmp[last]);

   }



   cout<<dp[(1<<n) - 1]<<endl;

   return 0;

}