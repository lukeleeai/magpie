#include<iostream>

#include<algorithm>

#include<cmath>

using namespace std;

int main(){

	long long n,a[200000],i,z=0;

	cin>>n;

	for(i=0;i<n;i++){

		cin>>a[i];

		a[i]-=i;

	}

	sort(a,a+n);

	for(i=0;i<n;i++){

		z+=abs(a[n/2]-a[i]);

	}

	cout<<z;

}