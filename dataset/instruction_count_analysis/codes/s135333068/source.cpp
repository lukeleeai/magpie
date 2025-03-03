#include <iostream> 

#include <algorithm>

using namespace std;

long long gcd(long long x, long long y)

{

	long long c;

	long long m = x, n = y;

	while (y != 0)

	{

		c = x%y;

		x = y;

		y = c;

	}

	return m / x*n;

}

int main()



{

	int n;

	int i;

	while (cin >> n)

	{

		long long m, s, l;

		cin >> m;

		if (n == 1)

			cout << m << endl;

		else if (n > 1)

		{

			cin >> l;

			s = gcd(l, m);

			for (i = 0; i < n - 2; i++)

			{

				cin >> m;

				s = gcd(s, m);

			}

			cout << s << endl;

		}

	}

	return 0;

}