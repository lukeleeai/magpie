#include "stdc++.h"

using namespace std;

//動画解説写し

struct Sieve{

  int n;

  vector<int>f,primes;

  Sieve(int n=1):n(n),f(n+1){

  /*  f[0]=f[1]=-1;

    for(long long i=2;i<=n;++i){

      if(f[i])continue;

      primes.push_back(i);

      f[i]=i;

      for(long long j=i*i;j<=n;j+=i){

        if(!f[j])f[j]=i;

      }

    }*/

  }

vector<pair<long long,int>>factor(long long x){

  vector<pair<long long,int>>res;

  for(long long i=2;i*i<=x;++i){

    int y=0;

    while(x%i==0){

      x/=i;

      ++y;

    }

    if(y!=0)res.emplace_back(x,y);

  }

  if(x!=1)res.emplace_back(x,1);

  return res;

}

};

int main(){

  long long n;

  cin>>n;

  Sieve s(1000005);

  auto fs=s.factor(n);

  int ans=0;

  for(auto p:fs){

    int x=p.second;

    int b=1;

    while(b<=x){

      x-=b;

      b++;

      ++ans;

    }

  }

  cout<<ans<<endl;

  return 0;

}