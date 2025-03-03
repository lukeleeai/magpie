#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)

#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)

#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)

#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)



/*

上から順に決めれる

O(NlogN)版

*/



bool ok=true;

ll n,a[200010];

vector<ll> ans;



void init(){

	cin>>n;

	reg(i,1,n)cin>>a[i];

}



int main(void){

	init();

	ireg(i,1,n){

		for(int j=2;i*j<=n;j++)a[i]^=a[j*i];

		if(a[i]==1){

			ans.push_back(i);

		}

	}

	cout<<ans.size()<<endl;

	rep(i,ans.size())cout<<ans[i]<<" ";

	cout<<endl;

	return 0;

}