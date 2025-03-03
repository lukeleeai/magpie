#include "stdc++.h"

//---------------------------

using namespace std;

//---------------------------

#define REP(i,n) for(int i = 0; i < (n); i++)



long long N,W,sm=0;

long long w[200];

long long v[200];

vector<long long> v1,v2,v3,v4;

int i,j,k,l,con;

int cnt[4];



int main(){

  std::ios::sync_with_stdio(false);

  std::cin.tie(0);



  cin >> N >> W;



  REP(i,N){

    cin >> w[i] >> v[i];

    if(i == 0){

      v1.push_back(v[i]);

    }

    if(i>=1){

      con=w[i]-w[0];

      if(con==0)v1.push_back(v[i]);

      if(con==1)v2.push_back(v[i]);

      if(con==2)v3.push_back(v[i]);

      if(con==3)v4.push_back(v[i]);

    }

  }

  sort(v1.begin(), v1.end());

  sort(v2.begin(), v2.end());

  sort(v3.begin(), v3.end());

  sort(v4.begin(), v4.end());



  reverse(v1.begin(), v1.end());

  reverse(v2.begin(), v2.end());

  reverse(v3.begin(), v3.end());

  reverse(v4.begin(), v4.end());



  for(i=0;i<(int)v1.size();i++){

    if(i+1==(int)v1.size())continue;

    v1[i+1]+=v1[i];

  }

  for(i=0;i<(int)v2.size();i++){

    if(i+1==(int)v2.size())continue;

    v2[i+1]+=v2[i];

  }

  for(i=0;i<(int)v3.size();i++){

    if(i+1==(int)v3.size())continue;

    v3[i+1]+=v3[i];

  }

  for(i=0;i<(int)v4.size();i++){

    if(i+1==(int)v4.size())continue;

    v4[i+1]+=v4[i];

  }

  v1.insert(v1.begin(), 0);

  v2.insert(v2.begin(), 0);

  v3.insert(v3.begin(), 0);

  v4.insert(v4.begin(), 0);



  REP(i, (int)v1.size()){

    REP(j, (int)v2.size()){

      REP(k, (int)v3.size()){

        REP(l, (int)v4.size()){

          if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3) <= W){

            sm = max(sm, v1[i]+v2[j]+v3[k]+v4[l]);

          }

        }

      }

    }

  }

  cout << sm << endl;

  return 0;

}
