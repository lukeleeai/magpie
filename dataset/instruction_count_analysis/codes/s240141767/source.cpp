#include "stdc++.h"

#define rep(i,n)for(long long i=0;i<(n);i++)

using namespace std;

typedef long long ll;

const int MOD=1e9+7;

const int MAX = 1000000;

const int INF = 1e9;

const double pi=acos(-1);

using namespace std;



int main(){

  string s;

  cin >> s;

  int n=s.size();

  vector<int>a(n+1,0);

  rep(i,n){

    if(s[i]=='<'){

      a[i+1]=max(a[i+1],a[i]+1);

    }

  }

  rep(i,n){

    if(s[n-1-i]=='>'){

      a[n-1-i]=max(a[n-1-i],a[n-i]+1);

    }

  }

  ll sum=0;

  rep(i,n+1)sum+=a[i];

  

  cout <<sum<<endl;

  

  return 0;

}