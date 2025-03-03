#include "stdc++.h"

using namespace std;



int N;



bool same(vector<int> a,vector<int> b){

  for(int i=0;i<N;i++){

    if(a[i]!=b[i]) return false;

  }

  return true;

}

int kaijo(int N){

  int ans=1;

  for(int i=1;i<=N;i++){

    ans*=i;

  }

  return ans;

}

int main() {



  cin>>N;

  vector<int> d(N);

  for(int i=0;i<N;i++) d[i]=i+1;

  vector<int> a(N);

  vector<int> b(N);

  for(int i=0;i<N;i++) cin>>a[i];

  for(int i=0;i<N;i++) cin>>b[i];





  int da=0,db=0;

  for(int i=0;i<kaijo(N);i++){

    if(same(a,d)) da=i;

    if(same(b,d)) db=i;

    next_permutation(d.begin(),d.end());

  }

  cout<<abs(da-db)<<endl;





  }
