#include<iostream>

#include<iomanip>

using namespace std;

int main()

{

	int n;

	int k;

	cin>>n>>k;

	double ans=0.0;

	for(int i=1;i<=n;++i)

	{

		double res=(double)(1.0/n);

		int sum=i;

		while(sum<k)

		{

			sum*=2;

			res*=0.5;

		}

		ans+=res;

	}

	cout<<fixed<<setprecision(12)<<ans<<endl;

	return 0;

}