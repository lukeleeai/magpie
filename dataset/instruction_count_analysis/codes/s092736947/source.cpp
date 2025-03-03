//Be Name Khoda

#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

const int MOD = (int)1e9 + 7;

const int MAXN = (int)1e6 + 7;

bool f(string s)

{

	if(s.size() < 7)

		return false;

	if(s[0] == 'd' and s[1] == 'r' and s[2] == 'e' and s[3] == 'a' and s[4] == 'm' and s[5] == 'e' and s[6] == 'r')

		return true;

	return false;

}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0); cout.tie(0);

	int n;

	cin >> n;

	while(n)

	{

		if((n % 10) == 9)

			return cout << "Yes", 0;

		n /= 10;

	}

	cout << "No";

}