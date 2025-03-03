#include<iostream>

#include<cmath>



using namespace std;



int main()

{

	long long a[200005];

	int n,i;

	long long s(0),min;

	cin>>n;

	a[0]=0;

	for (i=1;i<=n;i++)

	{

		cin>>a[i];

		s+=a[i];

	    a[i]+=a[i-1];

	}

	min=fabs(2*a[1]-s);

	for (i=2;i<n;i++)

	  if (fabs(2*a[i]-s)<min) min=fabs(2*a[i]-s);

	cout<<min<<endl;

	return 0;

}