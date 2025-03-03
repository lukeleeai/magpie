#pragma GCC optimize("03")

#include "stdc++.h"

#define endl '\n'

#define ll long long 

using namespace std;

int f[200000];

int find(int x){

	if(f[x]==x)

		return x;

	else

		return f[x]=find(f[x]);

}

void merge(int c,int d){

	f[d]=c;

}

int main()

{

    ios::sync_with_stdio(0);cin .tie(NULL);

    ll a,b,num;

   	cin >> a >> b;

   	for(int i=0;i<a;i++)

	f[i]=i;

    for(int i=0;i<b;i++)

    {

    	ll c,d;

    	cin >> c >> d;

    	c=find(c);

    	d=find(d);

   		merge(c,d);

	}

	cin >> num;

	for(int i=0;i<num;i++)

	{

		ll e,g;

		cin >> e >> g;

		if(find(e)==find(g))

			cout << "yes" << endl;

		else

			cout << "no" << endl;

	}

}
