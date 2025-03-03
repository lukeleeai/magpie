#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

vector<long long> a;

int main(){

	int n,k;

	cin>>n>>k;

	long long count=0;

	for(int i=0;i<n;i++){

		long long h;

		cin>>h;

		a.push_back(h);

	}

	if(k>=n){

		cout<<0;

		return 0;

	}

	sort(a.begin(),a.end());

	for(int i=n-k-1;i>=0;i--){

		count+=a[i];

	}

	cout<<count;



} 