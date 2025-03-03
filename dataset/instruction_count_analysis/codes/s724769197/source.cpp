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



int main2() {

  int N = nextInt();

  ll K = nextLong();

  vector<int> A(N);

  REP(i, N) A[i] = nextInt();



  ll P = N * K;



  const int L = 40;

  vector<ll> nxt[L];

  REP(i, L) nxt[i] = vector<ll>(N);



  map<int, int> last;

  for (int i = 2*N-1; i >= 0; i--) {

    if (i < N) {

      nxt[0][i] = last[A[i]] - i + 1;

    }

    last[A[i%N]] = i;

  }



  for (int l = 1; l < L; l++) {

    REP(i, N) {

      nxt[l][i] = nxt[l-1][ (i + nxt[l-1][i]) % N ] + nxt[l-1][i];

    }

  }



  ll pos = 0;

  for (;;) {

    int l = L-1;

    while (l >= 0 && nxt[l][pos % N] + pos > P) l--;

    if (l == -1) break;

    pos += nxt[l][pos % N];

  }



  vector<int> stack;

  set<int> in;

  for (; pos < P; pos++) {

    if (in.count(A[pos % N])) {

      do {

        in.erase(stack.back());

        stack.pop_back();

      } while (in.count(A[pos % N]));

    } else {

      stack.push_back(A[pos % N]);

      in.insert(A[pos % N]);

    }

  }

  pv(ALL(stack));



  return 0;

}



int main() {



#ifdef LOCAL

  for (;!cin.eof();cin>>ws)

#endif

    main2();

  return 0;

}