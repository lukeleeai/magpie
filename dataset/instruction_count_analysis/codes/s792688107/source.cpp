#include<iostream>//暴力？

using namespace std;



int main()

{

	long long N, h, n, w;

	long long up, down;

	while (cin >> N)

	{

		w = 0;

		for (h = 1; h <= 3500; h++)

		{

			for (n = 1; n <= 3500; n++)

			{

				up = 4 * h*n - N*h - N*n;

				down = N*h*n;

				if (up > 0 && down%up == 0 && down / up <= 3500)

				{

					w = down / up;

					cout << h << " " << n << " " << w << endl;

				}

				if (w != 0)

				{

					break;

				}

			}

			if (w != 0)

			{

				break;

			}

		}

	}

	return 0;

}