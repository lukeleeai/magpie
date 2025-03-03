#include "stdc++.h"

#define rep(i,n)for(long long i=0;i<(n);i++)

using namespace std;

typedef long long ll;

typedef pair<int,int> P;

 

const int MOD=1000000007;

const int INF=0x3f3f3f3f;

const ll INFL=0x3f3f3f3f3f3f3f3f;

ll gcd(ll x, ll y){

  if(y==0) return x;

  else return gcd(y, x%y);

}

ll lcm(ll x,ll y){

  ll g=gcd(x,y);

  return x/g*y;

}



int main(){

  string s;

  cin >> s;

  ll n=s.size();

  queue<ll>a;

  queue<ll>b;

  ll up=0;

  ll down=0;

  rep(i,n){

    if(i==0 &&s[0]=='>'){

      a.push(0);

      down++;

    }

    if(i!=0 &&s[i]=='>'){

      if(up){

        a.push(up);

        up=0;

      }

      down++;

    }

    if(s[i]=='<'){

      if(down){

        b.push(down);

        down=0;

      }

      up++;

    }

    if(i==n-1){

      if(up)a.push(up);

      b.push(down);

    }

  }  

  b.push(0);

    

  vector<ll>c(500010);

  c[0]=0;

  rep(i,500010) c[i+1]=c[i]+i+1;

  

  ll ans=0;

  while(!a.empty()){

    if(a.front()>=b.front()){

      ans+=c[a.front()]+c[max(b.front()-1,0ll)];

      a.pop();

      b.pop();

    }

    else{

      ans+=c[max(0ll,a.front()-1)]+c[b.front()];

      a.pop();

      b.pop();

    }

  }

  cout<<ans<<endl;

}
