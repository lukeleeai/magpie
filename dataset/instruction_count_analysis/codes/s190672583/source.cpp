#include <iostream>

#include <cstdio>

#include <algorithm>

#include <map>

#include <string>

using namespace std;

	

map<string,int> mp;

long long sum=0;

int n; 

int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++){

		string ss;

		cin>>ss;

		sort(ss.begin(),ss.end());

		sum+=mp[ss]++; 

	}

	printf("%lld",sum);

	return 0;

} 