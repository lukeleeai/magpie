#include <iostream>

#include <iomanip>

#include <sstream>

#include <cstdio>

#include <string>

#include <vector>

#include <algorithm>

#include <complex>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <cassert>

#include <climits>

#include <queue>

#include <set>

#include <map>

#include <valarray>

#include <bitset>

#include <stack>

using namespace std;



#define REP(i,n) for(int i=0;i<(int)n;++i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

typedef long long ll;

typedef pair<int,int> pii;

const int INF = 1<<29;

const double PI = acos(-1);

const double EPS = 1e-8;



const int MAX_N = 100001*2;



struct SegMax {

  int data[MAX_N * 2 - 1];

  int datb[MAX_N * 2 - 1];

  int n;

  SegMax(int n) : n(n) {

    REP(i,n) data[i]=datb[i]=0;

  }

  void add(int a, int b, int x) {

    add(a,b,x,0,0,n);

  }

  void add(int a, int b, int x, int k, int l, int r) {

    if (a <= l && r <= b) data[k] += x;

    else if (l<b && a<r) {

      add(a, b, x, k*2+1, l, (l+r)/2);

      add(a, b, x, k*2+2, (l+r)/2, r);

      datb[k] = max(data[k*2+1]+datb[k*2+1], data[k*2+2]+datb[k*2+2]);

    }

  }

  int getmax(int a, int b) {

    return getmax(a,b,0,0,n);

  }

  int getmax(int a, int b, int k, int l, int r) {

    if (b<=l || r<=a) return 0;

    else if (a<=l && r<=b) {

      return data[k] + datb[k];

    } else {

      int res = 0;

      res = max(res, getmax(a, b, k*2+1, l, (l+r)/2));

      res = max(res, getmax(a, b, k*2+2, (l+r)/2, r));

      return res + data[k];

    }

  }

};



int di[100000];

int hi[100000];



int main() {

  int N, H;

  cin >> N >> H;

  REP(i,N-1) {

    scanf("%d%d",di+i,hi+i);

  }

  SegMax st(N);

  priority_queue<pii> Q;

  int now = H;

  ll ans = 0;

  REP(i,N-1) {

    st.add(i,i+1,now);

    Q.push(pii(hi[i], i));

    now -= di[i];

    // cout << i << " ; " << now << endl;

    while(now<=0) {

      pii p = Q.top(); Q.pop();

      int heal = p.first;

      int pos = p.second;

      // cout << "(pos,heal) = " << pos << "," << heal << endl;

      int smax = st.getmax(pos, i+1);

      // cout << "segmax = " << smax << endl;

      if (smax + heal > H) {

        Q.push(pii(H-smax, pos));

        continue;

      }

      int num = min((0-now)/heal+1, (H-smax)/heal);

      now += num*heal;

      ans += num;

      // cout << "num = " << num << endl;

      // cout << "now = " << now << endl;

      st.add(pos, i+1, num*heal);

      Q.push(p);

    }

  }

  cout << ans << endl;

}