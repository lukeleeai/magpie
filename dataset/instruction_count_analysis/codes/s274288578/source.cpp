#include "stdc++.h"

using namespace std;

typedef long long ll;

#define INF 1LL<<62

#define inf 1000000007 



ll a[32][100010];

ll b[100010];

int main() {

	ll n,c;

	cin>>n>>c;

	for(int i=0;i<n;i++){

		ll x,y,z;

		cin>>x>>y>>z;

		z--;

		a[z][x]++;

		a[z][y]--;

	}

	for(int i=0;i<c;i++){

		for(int j=0;j<100010;j++){

			a[i][j+1]=a[i][j]+a[i][j+1];

		}

	}

	for(int i=0;i<100010;i++){

		ll now=0;

		for(int j=0;j<c;j++){

			if(a[j][i]==0&&a[j][i+1]==1){

				now++;

				continue;

			}

			now+=a[j][i];

		}

		b[i]=now;

	}

	ll ans=0;

	for(int i=0;i<100010;i++){

		ans=max(ans,b[i]);

	}

	cout <<ans;

	// your code goes here

	return 0;

}