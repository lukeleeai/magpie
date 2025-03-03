#include <iostream>

#include <string>

#include <cstdio>

#include <vector>

#include <queue>

#include <list>

#include <cstdlib>

#include <algorithm>

#include <set>

#include <map>

#include <deque>

#include <cstring>

#include <cmath>

//#include"stdc++.h"

using namespace std;



const int SIZE=100005;

const long long INF=1e9;

int n,a,b,h[SIZE];



bool check(long long times){

	long long t=times;

	for(int i=0;i<n;i++){

		if(times*b>=(long long)h[i]);

		else if(times*a>=(long long)h[i]){

			t-=(long long)ceil((double)((double)(h[i]-times*b))/((double)(a-b)));

			if(t<0) return false;

		}

		else return false;

	}

	return true;

}



int main(){

	cin>>n>>a>>b;

	for(int i=0;i<n;i++) cin>>h[i];

	long long lb=-1,rb=INF;

	while(rb-lb>1){

		long long mid=(lb+rb)/(long long)2;

		if(check(mid)){

			rb=mid;

		}

		else{

			lb=mid;

		}

	}

	cout<<rb<<endl;

	return 0;

}
