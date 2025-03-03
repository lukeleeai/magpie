#include "stdc++.h"

#define ll long long

using namespace std;



int main()

{

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++)

	{

		if (str[i] == '7')

		{

			cout << "Yes" << "\n";

			return 0;

		}

	}

	cout << "No" << "\n";

	return 0;

}