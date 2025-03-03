#include<cstdio>

#include<iostream>

#include<algorithm>

#include<stack>

#include<cmath>

using namespace std;

double arr[1005];

int main(){

	int n;

	int t,a;

	cin>>n;

	cin>>t>>a;

	for(int i=0;i<n;i++){

		cin>>arr[i];

		arr[i]=t-arr[i]*0.006;

		arr[i]-=a;

		arr[i]=abs(arr[i]);

	}

	stack<int>s;

	for(int i=0;i<n;i++){

		if(s.empty()||arr[s.top()]>arr[i])

			s.push(i);

	}

	printf("%d",s.top()+1);

}