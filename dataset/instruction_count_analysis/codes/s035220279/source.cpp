#include<iostream>

#include<iomanip>

using namespace std;

int main()

{

	int n;

	double x;

	cin>>n;

	if(n%2==1) x=(n+1)/2.0/n;

	else x=n/2.0/n;

	cout<<fixed<<setprecision(10);

	cout<<x<<endl;

	return 0;

} 