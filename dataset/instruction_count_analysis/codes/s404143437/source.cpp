#include<iostream>

#include<string.h>

#include<string>

using namespace std;

int main()

{

	long long n;

	while (cin >> n)

	{

		long long m=0;

		n++;

		while (n > 9)

		{

			m += 9;

			n = n / 10;

		}

		cout << m + n - 1 << endl;

	}

	return 0;

}