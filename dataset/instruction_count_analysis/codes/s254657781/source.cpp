#include<cstdio>

using namespace std;

typedef long long ll;



ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}



int main(){

  int n,i,j;

  ll d[10],v[10],t[10];



  for(;;){

    scanf("%d",&n);

    if(!n)break;



    for(i=0;i<n;i++)scanf("%lld %lld",&d[i],&v[i]);

    t[0] = 1;

    for(i=1;i<n;i++){

      t[i] = t[i-1]*d[i-1]*v[i];

      for(j=0;j<i;j++)t[j] *= d[i]*v[i-1];

      ll T = t[0];

      for(j=1;j<=i;j++)T = gcd(T,t[j]);

      for(j=0;j<=i;j++)t[j]/=T;

    }



    for(i=0;i<n;i++)printf("%lld\n",t[i]);

  }

}