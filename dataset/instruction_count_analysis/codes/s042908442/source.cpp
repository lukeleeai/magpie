#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <cmath>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <algorithm>

#include <complex>

#include <unordered_map>



using namespace std;

typedef long long int ll;

typedef pair<ll, ll> P;



int main()

{

	ll x; int k;

	cin>>x>>k;

	ll r[100001], ra[100001];

	r[0]=0; ra[0]=0;

	for(int i=1; i<=k; i++){

		cin>>r[i];

		if(i%2) ra[i]=ra[i-1]+r[i]-r[i-1];

		else ra[i]=ra[i-1]-r[i]+r[i-1];

	}

	int q;

	cin>>q;

	ll a[100000];

	ll t[100000];

	for(int i=0; i<q; i++){

		cin>>t[i]>>a[i];

	}

	ll x1=0, x2=x;

	ll ans0=-1;

	int j=0;

	for(int i=0; i<=k; i++){

		while(j<q && (i==k || t[j]<r[i+1])){

			ll t1=t[j]-r[i], ans;

			if(ans0>=0){

				if(i%2) ans=min(x, ans0+t1);

				else ans=max(0ll, ans0-t1);

			}else if(x1>a[j]){

				if(i%2) ans=min(x, x1-ra[i]+t1);

				else ans=max(0ll, x1-ra[i]-t1);

			}else if(x2<a[j]){

				if(i%2) ans=min(x, x2-ra[i]+t1);

				else ans=max(0ll, x2-ra[i]-t1);

			}else{

				if(i%2) ans=min(x, a[j]-ra[i]+t1);

				else ans=max(0ll, a[j]-ra[i]-t1);

			}

          cout<<ans<<endl;

			j++;

		}

		if(i==k) break;

		if(ans0>=0){

			if(i%2) ans0=min(x, ans0+r[i+1]-r[i]);

			else ans0=max(0ll, ans0-r[i+1]+r[i]);

		}else if(i%2){

			if(x+ra[i+1]<x2){

				x2=x+ra[i+1];

			}

			if(x1>=x2){

				ans0=x;

			}

		}else{

			if(ra[i+1]>x1){

				x1=ra[i+1];

			}

			if(x1>=x2){

				ans0=0;

			}

		}

	}

    return 0;

}