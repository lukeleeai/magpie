#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)



#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl

#define ALL(a) (a).begin(),(a).end()



#define CHMIN(a,b) a=min((a),(b))

#define CHMAX(a,b) a=max((a),(b))



// mod

const ll MOD = 1000000007ll;

#define FIX(a) ((a)%MOD+MOD)%MOD



// floating

typedef double Real;

const Real EPS = 1e-11;

#define EQ0(x) (abs(x)<EPS)

#define EQ(a,b) (abs(a-b)<EPS)

typedef complex<Real> P;



int n;

int a[252521];



pii S[425252];

int b;

int tail;

int maxtail;



void add(int x, int c){

  while(tail>0){

    int y = S[tail-1].first;

    int d = S[tail-1].second;

    if(x==y){

      tail--;

      c += d;

      int e = 0;

      while(c>b)e++,c-=b;

      if(e>0){

        add(x-1,e);

      }

    }else if(x > y){

      break;

    }else{

      tail--;

      while(y > x+1){

        // printf("%d,%d\n",y,d);

        int tgt = x+1;

        if(tail>0){

          CHMAX(tgt, S[tail-1].first);

        }

        int sa = y-tgt;

        if(sa>2){

          d = 1;

        }else{

          while(sa--)d=(d+b-1)/b;

        }

        y = tgt;

        if(tail>0 && S[tail-1].first == y){

          d += S[--tail].second;

        }

      }

      // printf("%d,%d\n",y,d);

      int e = 0;

      while(d>b)e++,d-=b;

      if(e>0){

        add(x,e);

      }

    }

  }

  S[tail++] = pii(x,c);

  CHMAX(maxtail, tail);

}



bool check(int _b){

  b = _b;

  tail = 0;

  FORR(i,-1,n){

    add(i==-1 ? 0 : a[i], 1);

    // REP(i,tail)printf("(%d,%d),",S[i].first,S[i].second);

    // puts("");

  }

  // printf("end of %d\n",b);

  return tail==1 && S[0]==pii(0,1);

}



int main(){

  scanf("%d",&n);

  REP(i,n)scanf("%d",a+i);

  // 1 check

  bool ok1 = true;

  REP(i,n-1)if(a[i]>=a[i+1]){

    ok1 = false; break;

  }

  if(ok1){

    puts("1");

    return 0;

  }

  // binary search

  int low = 1, high = n+10;

  // FOR(b,1,10)check(b);

  while(low+1 < high){

    int b = (low+high) / 2;

    if(check(b)){

      high = b;

    }else{

      low = b;

    }

  }

  printf("%d\n",high);

  // printf("mx: %d\n",maxtail);

  return 0;

}
