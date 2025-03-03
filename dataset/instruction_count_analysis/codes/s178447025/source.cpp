#include <iostream>

#include <cmath>

#include <complex>

#include <string>

#include <sstream>

#include <limits>

#include <algorithm>

#include <functional>



using namespace std;



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);



	int a, b;

	cin >> a >> b;



	int diff = b - a;

	int value = 0;



	for (int i = 1; i < diff; i++)

	{

		value += i;

	}



	cout << value - a;



	return 0;

}