#include <iostream>

#include <cmath>

using namespace std;

int y[101],r,n;



bool check(double cy){

  double x=sqrt(r*r-cy*cy);

  if(cy>=0)x=r;

  int L=(-x-0.9999),R=(x+0.9999),hb[101]={};



  for(int i=L+50;i<R+50;i++){

    int x1=i-49-i/50;

    double y1=y[i]-cy;

    if(sqrt(x1*x1+y1*y1)>=r)hb[i]++;

  }

  for(int i=L+50;i<R+50;i++)if(!hb[i])return 0;

  return 1;

}



int main(){

  while(1){

    cin>>r>>n;

    if(!r&&!n)break;

    for(int i=0;i<100;i++)y[i]=0;



    for(int i=0;i<n;i++){

      int x1,x2,h;

      cin>>x1>>x2>>h;

      for(int j=x1;j<x2;j++) y[j+50]=max(y[j+50],h);

    }

    double ans=0;

    while(check(ans-r))ans+=0.0005;

    cout << ans-0.0005<<endl;

  }

  return 0;

}