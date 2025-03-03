#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <cmath>

#include <map>

#include <queue>

#include <iomanip>

#include <set>

#include <tuple>

#define mkp make_pair

#define mkt make_tuple

#define rep(i,n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

const ll MOD=1e9+7;



int N;

vector<int> A;



vector<vector<int>> lose;



int dfs(int now){

    int depth=0;

    vector<int> v;

    for(auto nex:lose[now]){

        int val=dfs(nex);

        v.push_back(val);

    }

    sort(v.begin(),v.end());

    reverse(v.begin(),v.end());

    for(int i=0;i<v.size();i++) depth=max(depth,v[i]+i+1);

    return depth;

}



int main(){

  cin>>N;

  A.resize(N+1,0);

  for(int i=2;i<=N;i++) cin>>A[i];



  lose.resize(N+1);

  for(int i=2;i<=N;i++){

      lose[A[i]].push_back(i);

  }



  cout<<dfs(1)<<endl;



  return 0;

}
