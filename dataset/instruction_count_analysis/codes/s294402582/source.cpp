#include <map>

#include <math.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <iostream>

#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f







int main()

{

	long long n, m, sum;

	std::ios::sync_with_stdio(false);

	while (cin >> n >> m)

	{

		sum = 0;

		if (2 * n <= m)

		{

			sum += n;

			m -= 2 * n;

			sum += m / 4;

		}

		else if (2 * n > m)

			sum = m / 2;

		cout << sum << endl;

	}



	return 0;

}
