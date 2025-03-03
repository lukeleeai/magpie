#include"stdc++.h"

#define ro(a) (a).begin(),(a).end()

using namespace std;

using ll = long long int;

typedef vector<ll> vi;

ll n,k,sm = 0;

int main()

{

	cin>>n>>k;

	vi vo(n);

	for(ll &i:vo){

		cin>>i;

	}

	sort(ro(vo));

	for(ll i = 0;i<k;i++){

		sm+=vo[i];

	}

	cout<<sm<<"\n";

}