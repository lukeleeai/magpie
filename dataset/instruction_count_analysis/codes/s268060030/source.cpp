#include"stdc++.h"

using namespace std;

#define int unsigned long long

signed main(){

  int a,b,d,w,f=0;

  int c[1000][1000]={};

  int e[1000]={};

  cin>>a>>b;

  w=b;

  for(int i=0;i<a;i++){

    cin>>b;

    for(int j=0;j<b;j++){

      cin>>d;

      c[i][d]=1;

    }

  }

  for(int i=0;i<=a;i++){

    for(int j=0;j<=w;j++){

      e[j]+=c[i][j];

    }

  }

  for(int i=0;i<=w;i++){

   // cout<<e[i]<<" "<<a<<"\n";

    if(e[i]==a) f++;

  }

  cout<<f<<"\n";

}