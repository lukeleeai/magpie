#include "stdc++.h"

using namespace std;

//

struct Sieve{

  vector<pair<long long,int>>factor(long long x){//素因数分解（素数、何個あるか）

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

  Sieve s;

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