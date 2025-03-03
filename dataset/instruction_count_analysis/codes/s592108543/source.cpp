#include <iostream>

#include <cmath>

using namespace std;

int y[50],r,n;



bool check(double cy){

  double x=sqrt(r*r-cy*cy);

  if(cy>=0)x=r;

  int L=-x-0.9999,R=x+0.9999,hb[101]={};



  for(int i=L+25;i<R+25;i++){

    int x1=i-24-i/25;

    double y1=y[i]-cy;

    if(x1*x1+y1*y1>=r*r)hb[i]++;

  }

  for(int i=L+25;i<R+25;i++)if(!hb[i])return 0;

  return 1;

}



int main(){

  while(1){

    cin>>r>>n;

    if(!r&&!n)break;

    for(int i=0;i<50;i++)y[i]=0;



    for(int i=0;i<n;i++){

      int x1,x2,h;

      cin>>x1>>x2>>h;

      for(int j=x1;j<x2;j++) y[j+25]=max(y[j+25],h);

    }

    double ans=0;

    while(check(ans-r))ans+=0.0009;

    cout << ans<<endl;

  }

  return 0;

}