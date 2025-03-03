#include"stdc++.h"

#define ll long long

#define pb push_back

using namespace std;



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	int n;

	cin >> n;

	string str;

	cin >> str;

	if(n%2 != 0)

	  cout << "No";

	else

	{

		string str1 = str.substr(0,n/2);

		string str2 = str.substr(n/2,n/2);

		if(str1 == str2)

		   cout << "Yes";

		else

		   cout << "No";

	}

	return 0;

}
