#include<cstdio>

#include<vector>

#include<algorithm>

#include<iostream>

using namespace std;



typedef long long ll;



ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a,ll b){return a/gcd(a,b)*b;}



int main(){

  double ans;

  ll n,m,p[20];



  while(scanf("%lld %lld",&n,&m) && (n||m)){

    for(int i=0;i<m;i++)scanf("%lld",&p[i]);



    sort(p,p+m);

    ans = ( (n+1)*n ) / 2;



    ll num = 0;

    for(int i=1;i<(1<<m);i++){

      int bit = 0;

      for(int j=i;j!=0;j>>=1)bit += j&1;

      ll tmp = 1;

      for(int j=0;j<m;j++)

	if(i>>j & 1)tmp = lcm(tmp,p[j]);



      if(bit&1){

	num += n/tmp;

	ans -= (n/tmp+1)*n/2;

      }else{

	num -= n/tmp;

	ans += (n/tmp+1)*n/2;

      }

    }



    if(num==n)printf("0.00000000\n");

    else printf("%.8lf\n",ans/(n-num));

  }

}