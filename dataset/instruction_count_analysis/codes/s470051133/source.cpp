#include <iostream>

#include <string>

#include <set>

#include <map>

using namespace std;



map<string, int> M;

set<string> ans;

string s[222222];



int main(void)

{

	cin.tie(NULL);

	cout.tie(NULL);

	ios::sync_with_stdio(false);



	int n, i;



	cin >> n;

	for (i = 1; i <= n; i++)

	{

		cin >> s[i];

		M[s[i]]++;

	}



	int maxi = -1;

	for (i = 1; i <= n; i++)

		if (maxi < M[s[i]])

			maxi = M[s[i]];



	for (i = 1; i <= n; i++)

		if (maxi == M[s[i]])

			ans.insert(s[i]);



	set<string>::iterator it;

	for (it = ans.begin(); it != ans.end(); ++it)

		cout << *it << endl;

	return 0;

}