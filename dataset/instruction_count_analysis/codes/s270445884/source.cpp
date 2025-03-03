#include<iostream>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

//deque/functional/iterator/list/map/memory/numeric/queue/set/stack/utility/vector

//#include"stdc++.h"

#define ll long long

using namespace std;





int main() {

	ios::sync_with_stdio(false);

	ll a,b,c,d;

	cin>>a;

	string s;

	cin>>s;

	ll sum=0;

	ll max1=0;

	for(int i=0; i<a; i++) {

		if(s[i]=='I') {

			sum++;

		} else {

			sum--;

		}

		max1=max(sum,max1);

	}

	cout<<max1<<endl;

	return 0;

}