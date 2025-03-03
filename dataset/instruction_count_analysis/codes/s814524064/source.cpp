#include <iostream>

#include <algorithm>

using namespace std;



int main()

{

	string s;

	while (cin >> s) {

		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3])

			cout << "Bad\n";

		else cout << "Good\n";

	}

}