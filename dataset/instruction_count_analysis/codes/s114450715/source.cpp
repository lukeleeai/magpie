#include "stdc++.h"

using namespace std;



typedef long long ll;

#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)

#define ALL(v) (v).begin(),(v).end()

#define CLR(t,v) memset(t,(v),sizeof(t))

template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}

template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}

template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}

template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}



int nextInt() { int x; scanf("%d", &x); return x;}

ll nextLong() { ll x; scanf("%lld", &x); return x;}



const int MAX_N = 212345;

const int MAX_A = 212345;

int A[MAX_N * 2];

int nxt[MAX_N * 2];

int inc[MAX_N * 2];

int last[MAX_A];

ll vis[MAX_N * 2];

bool isin[MAX_A];



int main2() {

  int N = nextInt();

  ll K = nextLong();

  REP(i, N) A[i] = nextInt();

  REP(i, N) A[i + N] = A[i];



  CLR(last, -1);

  CLR(inc, 0);



  REP(i, 2 * N) {

    if (last[A[i]] >= 0) {

      nxt[ last[A[i]] ] = (i + 1) % N;

      inc[ last[A[i]] ] = (i + 1) / N;

    }

    last[A[i]] = i;

  }

  // pv(A, A+N);

  // pv(nxt, nxt + N);

  // pv(inc, inc + N);



  CLR(vis, -1);

  ll k = 0;

  int pos = 0;

  while (vis[pos] == -1) {

    vis[pos] = k;

    k += inc[pos];

    pos = nxt[pos];

  }



  ll L = k - vis[pos];

  // cout << "L=" << L << endl;

  // cout << "k=" << k << endl;

  if (K - k >= 2) {

    k += (K - k - 1) / L * L;

  } else {

    k = 0;

    pos = 0;

  }

  // cout << "k=" << k << endl;



  while (k < K - 1) {

    k += inc[pos];

    pos = nxt[pos];

  }



  CLR(isin, 0);

  vector<int> stack;



  // cout << "k=" << k << endl;

  // cout << "pos=" << pos << endl;

  for (; k < K && pos < N; pos++) {

    const int v = A[pos];

    if (isin[v]) {

      while (isin[v]) {

        isin[stack.back()] = false;

        stack.pop_back();

      }

    } else {

      stack.push_back(v);

      isin[v] = true;

    }

  }



  REP(i, stack.size()) {

    if (i > 0) cout << " ";

    cout << stack[i];

  }

  cout << endl;

  return 0;

}



int main() {



#ifdef LOCAL

  for (;!cin.eof();cin>>ws)

#endif

    main2();

  return 0;

}
