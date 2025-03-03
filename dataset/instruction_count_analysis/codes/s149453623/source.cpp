#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#include <queue> //priority_queue 优先队列

#include <map>

#include <set> //multiset  

#include <vector>

#include <stack>

#include <cmath>

#include <sstream>

#include <string>

#define mod 1000000007

typedef unsigned long long ull;

typedef long long ll;

typedef double db;

const db eps=1e-6;

const int INF=0x3f3f3f3f;

const int N=2e5+5;

using namespace std;



ll t=1,n,m;

ll s=0;

ll a[N]={0};

int main(){

	cin>>n>>m;

	for(int i=0;i<n;i++){

		cin>>a[i];

		a[i]/=2;

		t=a[i]/__gcd(a[i],t)*t;

	}

	for(int i=0;i<n;i++){

		if(t%(a[i]*2)==0){

			cout<<"0"<<endl;

			return 0;

		}

	}

	printf("%lld\n",(m/t+1)/2);

	return 0;

}