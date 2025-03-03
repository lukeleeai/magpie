#pragma GCC optimize("O3")

#include"stdc++.h"

#define ll long long

#define endl '\n'

using namespace std;



int main(){

	ios::sync_with_stdio(0);cin.tie(0);

	ll n,a,b,ans=0;

	cin>>n>>a>>b;

	for(ll i=1;i<=n;i++){

		string str=to_string(i);

		ll cnt=0;

		for(char j:str)	cnt+=j-'0';

		if(a<=cnt&&cnt<=b)	ans+=i;

	}

	cout<<ans<<endl;

	return 0;

}