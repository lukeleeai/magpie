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

  vi a(n);

  rep(i,n)cin>>a[i],a[i]--;

  int ans=0;

  rep(i,n)if(a[a[i]]==i)ans++;

  cout<<ans/2<<endl;

}
