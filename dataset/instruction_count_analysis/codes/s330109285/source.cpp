#include<iostream>

using namespace std;

int main()

{

	long long N, h, n, w;

	cin >> N;

	int flag = 0;

	for (h = 1; h <= 3500; h++)

	{

		for (n = 1; n <= 3500; n++)

		{

			if ((4 * h*n - N*h - N*n) > 0 && ((N*h*n) % (4 * h*n - N*h - N*n) == 0))

			{

				flag = 1;

				break;

			}

		}

		if (flag == 1)

		{

			cout << h << " " << n << " " << (N*h*n) / (4 * h*n - N*h - N*n) << endl;

			break;

		}

	}

	return 0;

}