#include <iostream>

#include <cmath>



using namespace std;



int len=0;



int get_length(int x)

{

	while(x)

	{

		x/=10;

		len++;

	}

	return len;

}



int main()

{

	int a,b;

	double result,number;

	while(cin>>a>>b)

	{

		len=get_length(b);

		number=a*pow(10,len)+b;

		result=sqrt(number);

		if(abs(round(result)-result)<1e-8)

			cout<<"Yes";

		else

			cout<<"No";

	}

	return 0;

}