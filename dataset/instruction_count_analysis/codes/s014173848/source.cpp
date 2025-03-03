#include"stdc++.h"

#define INF 1000000000

using namespace std;

int dp(int i,int bits);

int n,m;

vector<int>vec[100009];

int p[1009];



int main(){

  cin>>n>>m;

  for(int i=0;i<m;i++){

    int k;

    cin>>k;

    for(int j=0;j<k;j++){

      int s;

      cin>>s;

      vec[i].push_back(s);

    }

  }

  for(int i=0;i<m;i++){

    cin>>p[i];

  }

  cout<<dp(0,0)<<endl;

  return(0);

}



int dp(int i,int bits){

  int rec=0;

  if(i==n){

    int t=0;

    for(int j=0;j<m;j++){

      int cnt=0;

      for(int k=0;k<vec[j].size();k++){

	cnt+=(bits>>(vec[j][k]-1))&1;

      }

      if(cnt%2==p[j])t++;

    }

    if(t==m)return 1;

    else return 0;

  }

  rec+=dp(i+1,bits);

  rec+=dp(i+1,bits|(1<<i));

  return rec;

}
