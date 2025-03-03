#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);++i)

int main(){

	ll n,a,b,ans=0;cin>>n>>a>>b;

	vector<ll> x(n);

	rep(i,n)cin>>x[i];

	rep(i,n-1)ans+=min(a*(x[i+1]-x[i]),b);

	cout<<ans<<endl;

    return 0;

}