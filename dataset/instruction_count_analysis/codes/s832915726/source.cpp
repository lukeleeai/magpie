#include <iostream>

#include <vector>

#include <algorithm>

#include <set>



using namespace std;





int main() {

	char s;

	multiset<char> k;

	set<char> k2;

	for (int i = 0; i < 4; i++) {

		cin >> s;

		k2.insert(s);

		k.insert(s);

	}

	//cout << k2.size() << ' ' << k.count(s) << ' ' << s;

	if (k2.size() == 2 & k.count(s) == 2)

		cout << "Yes";

	else

		cout << "No";

}