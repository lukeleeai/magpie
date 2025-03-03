#include<iostream>

using namespace std;

int sum=0, n, a[53], b[53];

int main()

{

	cin>>n;

	for(int i=0;i<n;i++){

		cin>>a[i];

		b[i+1]=b[i]+a[i];

	}

	for(int i=0;i<n;i++){

		sum+=(a[i]*b[i]);

	}

	cout<<sum<<endl;

	return 0;

}