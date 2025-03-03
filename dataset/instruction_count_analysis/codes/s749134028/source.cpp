#include "stdc++.h"

using namespace std;

typedef long long ll;

#define INF 1LL<<62

#define inf 1000000007



int main() {

	ll n,k;

	cin>>n>>k;

	long double p[200010];

	for(ll i=0;i<n;i++){

		long double x;

		cin>>x;

		p[i]=x;

	}

	long double ch[200010]={};

	for(ll i=0;i<n;i++){

		long double now=(p[i]+1.0)/2;

		if(p[i]==1){

			now=1.0;

		}

		ch[i]=now;

		//printf("%.10Lf\n",now);

	}

	long double ans=0;

	for(ll i=0;i<k;i++){

		ans+=ch[i];

	}

	long double now=ans;

	for(ll i=0;i<n-k+1;i++){

	//printf("%.10Lf\n",now);		

		now-=ch[i];

		now+=ch[i+k];

		ans=max(now,ans);

	}

	printf("%.10Lf",ans);

	// your code goes here

	return 0;

}