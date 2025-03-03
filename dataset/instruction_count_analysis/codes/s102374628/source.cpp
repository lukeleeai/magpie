#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<map>

#include<cmath>

using namespace std;

double cnt;

double p,t;

int K; 

double e;

double ll,rr;

double dfs(double l,double r,int k,double tl,double tr)

{

     double mid=(l+r)/2.00;

     if(l>tl-1e-12&&r<tr+1e-12)

     return 1.0;

     if(r<tl+1e-12||l>tr-1e-12)

     return 0.0;

    if(k==K)

    {

     if(mid<tr+1e-12&&mid>tl-1e-12)

      return 1.0;

     else return 0.0;

    }

    double pp;

    if(mid>=t-1e-12) pp=1.00-p;

    else pp=p;

    return pp*dfs(l,mid,k+1,tl,tr)+(1-pp)*dfs(mid,r,k+1,tl,tr);

    

}

int main()

{

  //freopen("aaa.txt","r",stdin);

  //freopen("bbb.txt","w",stdout);

  while(cin>>K>>ll>>rr)

  {    

    cin>>p>>e>>t;   

    double kk=dfs(ll,rr,0,t-e,t+e);

    printf("%.12lf\n",kk);

  }

}