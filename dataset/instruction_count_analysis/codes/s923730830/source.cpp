#include "stdc++.h"

using namespace std;

typedef long long ll;

#define INF 1LL<<62

#define inf 1000000007



int main() {

	ll n,k;

	cin>>n>>k;

	long double ch[200010];

	for(ll i=0;i<n;i++){

		cin>>ch[i];

	}

	long double ans=0;

	for(ll i=0;i<k;i++){

		long double now=ch[i];

		now=(now+1)/2;

		ans+=now;

	}

	long double cnt=ans;

	for(ll i=k;i<n;i++){

		long double now1=ch[i];

		now1=(now1+1)/2;

		long double now2=ch[i-k];

		now2=(now2+1)/2;

		cnt+=now1-now2;

		ans=max(ans,cnt);

	}

	printf("%.10Lf",ans);

	// your code goes here

	return 0;

}