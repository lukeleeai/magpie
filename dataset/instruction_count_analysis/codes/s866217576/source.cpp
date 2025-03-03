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

const int N = 2e5+10;

const int M = 1e6+10;

/*=================================================================================*/



int n, m;

ll sum[N<<2], tag[N<<2];

struct node {

   int l, r, a;

}b[N];



bool cmp(node x, node y) {

   return x.r < y.r;

}



void add(int rt, int L, int R, int x, int y, ll val) {

   if(x <= L && y >= R) {

      sum[rt] += val, tag[rt] += val;

      return;

   }

   int mid = (L + R) >> 1;

   if(x <= mid) add(rt<<1, L, mid, x, y, val);

   if(y > mid) add(rt << 1 | 1, mid+1, R, x, y, val);

   sum[rt] = max(sum[rt<<1], sum[rt<<1|1]) + tag[rt];

}



int main() {

   scanf("%d %d", &n, &m);

   for1(i, m) {

      scanf("%d %d %d", &b[i].l, &b[i].r, &b[i].a);   

   }

   sort(b+1, b+1+m, cmp);

   int idx = 1;

   for1(i, n) {

      add(1, 1, n, i, i, sum[1]);

      while(b[idx].r == i) {

         // debug1 printf("%d %d %d\n", b[idx].l, b[idx].r, b[i].a);

         add(1, 1, n, b[idx].l, i, b[idx].a);

         idx++;

      }

   }

   cout << max(sum[1], (ll)0) << endl;

   return 0;

}