#include <iostream>

using namespace std;

int main ()

{

	int n,r;

	while(cin>>n>>r)

	{

		int sum;

		if(n<10)

		{

			sum=r+100*(10-n);

			cout<<sum<<endl;

		}

		else

		{

			cout<<r<<endl;

		}

	}

	return 0;

} 