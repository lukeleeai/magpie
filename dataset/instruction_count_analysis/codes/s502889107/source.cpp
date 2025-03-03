#include "stdc++.h"

using namespace std;

typedef long long ll;

#define INF 1LL<<62

#define inf 1000000007



ll a[25];

int main() {

	ll n;

	cin>>n;

	a[0]=1;

	for(ll i=0;i<n;i++){

		ll x;

		cin>>x;

		a[x]++;

	}

	ll ans=24;ll now=0;

	bool ch=true;

	for(ll i=0;i<=12;i++){

		if(i!=0&&i!=12){

			if(a[i]==2){

				a[i]--;

				a[24-i]++;

			}

			else if(a[i]==1){

				if(ch){

					a[i]--;

					a[24-i]++;

					ch=false;

				}

				else{

					ch=true;

				}

			}

		}

	}

	for(ll i=0;i<24;i++){

		if(a[i]>1){

			cout << 0;

			return 0;

		}

		if(a[i]==1&&i!=0){

			ans=min(ans,i-now);

			now=i;

			continue;

		}

		if(i==23){

			ans=min(ans,24-now);

		}

	}

	cout <<ans;

	// your code goes here

	return 0;

}