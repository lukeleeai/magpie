#include<iostream>

using namespace std;

int main()

{

	long int n,k;

	cin>>n>>k;

	long int t=0;

	if(k==10)

	{

		while(n!=0)

		{

			n=n/10;

			t++;

		}

	}

	else{

		t=1;

		while(n>=k)

		{

			n=n/k;

			t++;

		}

	}

	cout<<t<<endl;

	return 0;

}