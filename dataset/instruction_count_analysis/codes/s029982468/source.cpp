#include<iostream>

using namespace std;



typedef long long ll;



ll gcd(ll a,ll b){

  return (!b)?a:gcd(b,a%b);

}



int main(){

  int n;

  ll d[10],v[10],t[10];



  for(;;){

    cin >> n;

    if(!n)break;



    for(int i=0;i<n;i++)cin >> d[i] >> v[i];

    t[0] = 1;

    for(int i=1;i<n;i++){

      t[i] = t[i-1]*d[i-1]*v[i];

      for(int j=0;j<i;j++)t[j] *= d[i]*v[i-1];

      ll T = t[0];

      for(int j=1;j<=i;j++)T = gcd(T,t[j]);

      for(int j=0;j<=i;j++)t[j]/=T;

    }



    for(int i=0;i<n;i++)cout << t[i] << endl;

  }

}