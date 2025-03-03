#include <iostream>



bool solve(int i, int m);

int n, q, A[2000], m[2000];



int main()

{

	using namespace std;

	cin >> n;

	for (int i = 0; i < n; i++)

	{

		cin >> A[i];

	}

	cin >> q;

	for (int i = 0; i < q; i++)

	{

		cin >> m[i];

	}

	for (int i = 0; i < q; i++)

	{

		if (solve(0, m[i]))

		{

			cout << "yes\n";

		}

		else

		{

			cout << "no\n";

		}

	}

	return 0;

}



bool solve(int i, int m)

{

	if (m == 0)

	{

		return true;

	}

	if (i >= n)

	{

		return false;

	}

	return solve(i + 1, m) || solve(i + 1, m - A[i]);

}
