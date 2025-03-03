#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cmath>

#include<math.h>

#include<string>

#include<string.h>

#include<stack>

#include<queue>

#include<vector>

#include<utility>

#include<set>

#include<map>

#include<stdlib.h>

#include<iomanip>



using namespace std;



#define ll long long

#define ld long double

#define EPS 0.0000000001

#define INF 1e9

#define MOD 1000000007

#define rep(i,n) for(i=0;i<n;i++)

#define loop(i,a,n) for(i=a;i<n;i++)

#define all(in) in.begin(),in.end()

#define shosu(x) fixed<<setprecision(x)



typedef vector<int> vi;

typedef pair<int,int> pii;



int main(void) {

  int i,j;

  int n;

  cin>>n;

  vi a(n),h(n);

  vector<bool> f(n,false);

  rep(i,n)cin>>a[i];//left

  rep(i,n){

    h[i]=a[i];

    if(i==0 || a[i]!=a[i-1])f[i]=true;

  }

  rep(i,n)cin>>a[i];//right

  for(i=n-1;i>=0;i--){

    if(f[i]){

      if(i==n-1 || a[i]!=a[i+1]){

	if(h[i]!=a[i]){

	  cout<<0<<endl;

	  return 0;

	}

      }else{

	if(h[i]>a[i]){

	  cout<<0<<endl;

	  return 0;

	}

      }

    }else{

      if(i==n-1 || a[i]!=a[i+1]){

	if(h[i]<a[i]){

	  cout<<0<<endl;

	  return 0;

	}

	h[i]=a[i];

	f[i]=true; 

      }else{

	if(h[i]>a[i])h[i]=a[i];

      }

    } 

  }



  ll ans=1;

  rep(i,n)if(f[i]==false)ans=(ans*h[i])%MOD;

  cout<<ans<<endl;



}
