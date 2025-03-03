#include <iostream>

#include <cmath>

#include <complex>

#include <string>

#include <sstream>

#include <limits>

#include <algorithm>

#include <functional>



#include <vector>



using namespace std;



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);



	int a, b;

	cin >> a >> b;



	vector<int> value_list(1000, 0);



	for (int i = 1; i < 1000; i++)

	{

		value_list[i] = i + value_list[i - 1];

	}



	for (int i = 1; i < 499500; i++)

	{

		for (int j = 1; j < 1000 - 1; j++)

		{

			if (value_list[j] - i == a && value_list[j + 1] - i == b)

			{

				cout << i;

				return 0;

			}

		}

	}



	return 0;

}