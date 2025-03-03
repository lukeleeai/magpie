#include<iostream>

#include <vector>

using namespace std;

bool Nsided(int n, vector<int> side)

{

	int i = side.size();

	int sum = 0, maxside = 0;

	for (int j = 0; j < i; j++)

	{

		if (side[j] > maxside)

		{

			sum += maxside;

			maxside = side[j];

		}

		else

			sum += side[j];

	}

	return maxside < sum;

}

int main()

{

	int N;

	int x;

	vector <int> LI;

	cin >> N;

	while (cin >> x)

		LI.push_back(x);

	if (N >= 3 && N <= 10 && x >= 1 && x <= 100)

	{

		if (Nsided(N, LI))

			cout << "Yes" << endl;

		else

			cout << "No" << endl;

	}

	else

		cout << "please enter N between three and ten,Li between one and hundred" << endl;

	return 0;

}
