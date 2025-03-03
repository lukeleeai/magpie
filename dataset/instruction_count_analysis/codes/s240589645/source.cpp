#include "stdc++.h"

using namespace std;



#define endl '\n'



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(0);



	int n;

	cin >> n;



	set<int> I;

	vector<int> ord(n);

	for(int i = 0; i < n; ++i)

	{

		cin >> ord[i];

		if(i & 1)

			I.insert(ord[i]);

	}



	sort(ord.begin(), ord.end());

	for(int i = 1; i < n; i += 2)

		I.erase(ord[i]);



	cout << I.size() << endl;



	return 0;

}