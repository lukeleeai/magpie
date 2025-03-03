#include<iostream>

#include<vector>

#include<cmath>

#include<algorithm>

#include<iomanip>

#include<cassert>

#include<sstream>

#include<complex>

#include<cstdio>

#include<climits>

#include<cstdlib>

#include<deque>

#include<queue>

#include<stack>

#include<map>

#include<set>

#include<ctime>

#include<cctype>

#define REP(i,s,n) for(int i=s;i<n;i++)

#define rep(i,n) REP(i,0,n)

#define inf (2147483647)

#define EPS 1e-10

#define equals(a,b) (fabs((a)-(b)) < EPS) 

#define MAX_N 500010

 

using namespace std;

 

template<class T>

class RMQ{

private:

  int n;

  T dat[2*MAX_N-1];

public:

  void init(int n_){

    n = 1;

    while(n<n_)n*=2;

    for(int i=0;i<2*n-1;i++)dat[i] = inf;//

  }

  

// k????????????(0-indexed)???a?????????´

  void update(int k,T a){

    k += n-1;

    dat[k] = a;

    while(k > 0){

      k = (k-1)/2;

      dat[k] = min(dat[k*2+1],dat[k*2+2]);

    }

  }

  

  T query(int a,int b,int k,int l,int r){

    if(r<=a || b<=l)return inf;

    else if(a<=l && r<=b)return dat[k];

      

      T vl = query(a,b,k*2+1,l,(l+r)/2);

      T vr = query(a,b,k*2+2,(l+r)/2,r);

      return min(vl,vr);

  }

 

//n????????????§?????????????????????????\??????????£????????????¨ 

  T _query(int a,int b){

    return query(a,b,0,0,n);

  }

};

 

 

int main()

{

  int n,q,com,x,y;

  //scanf("%d%d",&n,&q);

  cin >> n >> q;

  RMQ<int> rmq;

  rmq.init(n+1);

  rep(i,q)

    {

      //scanf("%d%d%d",&com,&x,&y);

      cin >> com >> x >> y;

      if(com == 0)rmq.update(x,y);

      else        cout << rmq._query(x,y+1) << endl;

    }

 

  return 0;

}