//#include "stdc++.h"

//using namespace std;

//#define SZ(a) ((int)(a).size())

//#define PB push_back

//#define MP make_pair

//const int maxn = 200009;

//const int MOD = 1e9 + 7;

//vector<int> V[maxn];

//int64_t SUM[maxn << 2], LZ[maxn << 2];

//void upd(int rt, int l, int r, int ll, int rr, int v) {

  //if (ll <= l && rr >= r) {

    //LZ[rt] += v;

    //SUM[rt] += (r - l + 1) * v;

    //return;

  //}

  //int mid = (l + r) >> 1;

  //if (LZ[rt]) {

    //LZ[rt << 1 | 1] += LZ[rt];

    //LZ[rt << 1] += LZ[rt];

    //SUM[rt << 1] += (mid - l + 1) * LZ[rt];

    //SUM[rt << 1 | 1] += (r - mid) * LZ[rt];

    //LZ[rt] = 0;

  //}

  //if (ll <= mid) upd(rt << 1, l, mid, ll, rr, v);

  //if (rr > mid) upd(rt << 1 | 1, mid + 1, r, ll, rr, v);

  //SUM[rt] = SUM[rt << 1 | 1] + SUM[rt << 1];

//}

//int64_t query(int rt, int l, int r, int ll, int rr) {

  //if (ll <= l && rr >= r) {

    //return SUM[rt];

  //}

  //int mid = (l + r) >> 1;

  //if (LZ[rt]) {

    //LZ[rt << 1 | 1] += LZ[rt];

    //LZ[rt << 1] += LZ[rt];

    //SUM[rt << 1] += (mid - l + 1) * LZ[rt];

    //SUM[rt << 1 | 1] += (r - mid) * LZ[rt];

    //LZ[rt] = 0;

  //}

  //int64_t res = 0;

  //if (ll <= mid) res += query(rt << 1, l, mid, ll, rr);

  //if (rr > mid) res += query(rt << 1 | 1, mid + 1, r, ll, rr);

  //return res;

//}

//int main() {

//#ifdef LOCAL

  //freopen("a.in", "r", stdin);

//#endif

  //ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);

  //int n;

  //cin >> n;

  //for (int i = 1; i < n; ++i) {

    //int u, v;

    //cin >> u >> v;

    //V[u].PB(v);

    //V[v].PB(u);

  //}

  //for (int i = 1; i <= n; ++i) {

    //int q = 1;

    //for (int v : V[i])

      //if (v <= i) q--;

    //upd(1, 1, n, i, n, q);

  //}

  //int64_t ans = 0;

  //for (int i = 1; i <= n; ++i) {

    //ans += query(1, 1, n, i, n);

    //for (int v : V[i])

      //if (v > i) {

        //upd(1, 1, n, v, n, 1);

      //}

    //upd(1, 1, n, i, n, -1);

  //}

  //cout << ans << "\n";



  //return 0;

//}

////2020.07.05 23:20:13



#include "stdc++.h"

using namespace std;

#define SZ(a) ((int)(a).size())

#define PB push_back

#define MP make_pair

const int maxn = 200009;

const int MOD = 1e9 + 7;

int main(){

#ifdef LOCAL

  freopen("a.in", "r", stdin);

#endif

  ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0);

  int64_t N;

  cin>>N;

  int64_t res=N*(N+1)*(N+2)/6;

  for(int i=1;i<N;++i){

    int64_t u,v;cin>>u>>v;

    if(u>v)swap(u,v);

    res-=u*(N-v+1);

  }

  cout<<res<<"\n";

  

  return 0;

}

//2020.07.06 19:37:43
