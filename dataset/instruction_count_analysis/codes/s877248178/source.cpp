#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <math.h>

#define MOD 1000000007

typedef long long ll;

using namespace std;



vector<int> v[100010];

int n;

int h=0;



int dfs(int x){



  int ma=0;

  vector<int> d;

  for(int i=0;i<v[x].size();i++){

    int tmp=dfs(v[x][i]);

    d.push_back(tmp);

  }

  sort(d.begin(),d.end());

  reverse(d.begin(),d.end());

  for(int i=0;i<d.size();i++){

    ma=max(ma,d[i]+i+1);

  }

  //cout<<x<<" "<<ma<<endl;

  return ma;

}



int main(){

  //int n;

  cin>>n;

  //vector<int> v[n+1];



  for(int i=2;i<=n;i++){

    int a;

    cin>>a;

    v[a].push_back(i);

  }



  cout<<dfs(1)<<endl;

  return 0;

}
