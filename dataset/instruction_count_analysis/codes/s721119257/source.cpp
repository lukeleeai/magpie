#include <iostream>

#include <string>

#include <set>

#include <map>

using namespace std;



map<string, int> M;

set<string> ans;

string s;



int main(void)

{

	cin.tie(NULL);

	cout.tie(NULL);

	ios::sync_with_stdio(false);



	int n, i, maxi = 0;



	cin >> n;

	for (i = 1; i <= n; i++)

	{

		cin >> s;

		M[s]++;

        maxi = max(maxi, M[s]);

	}



	for (auto p : M)

        if (p.second == maxi)

			cout << p.first << '\n';

	return 0;

}