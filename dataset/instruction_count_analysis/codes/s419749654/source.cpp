#include "stdc++.h"

using namespace std;

typedef long long ll;

#define INF 1LL<<62

#define inf 1000000007



ll ch[100010];

ll same[32][100010];

int main() {

	ll n,c;

	cin>>n>>c;

	ll sum=0;

	for(ll i=0;i<n;i++){

		ll l,r,z;

		cin>>l>>r>>z;

		ch[l]++;

		ch[r+1]--;

		same[z][l]++;

		same[z][r]++;

		if(same[z][l]==2){

			ch[l]--;

			ch[l+1]++;

		}

		if(same[z][r]==2){

			ch[r]--;

			ch[r+1]++;

		}

	}

	ll ans=ch[0];

	for(ll i=1;i<100010;i++){

		ch[i]=ch[i-1]+ch[i];

		ans=max(ans,ch[i]);

	}

	cout <<ans-sum;

	// your code goes here

	return 0;

}