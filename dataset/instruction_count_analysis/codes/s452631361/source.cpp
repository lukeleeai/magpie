#include <iostream>

#include<string>

#include<map>

#include<queue>

using namespace std;

map<string, int> sop;string s;

bool check(int mid)

{

	for (int i =1; i <= s.size() - mid+1; i++) {

		string op = s.substr(i-1, mid);

		if (sop[op])

		{

			if (i - sop[op] >= mid)

				return true;

		}

		else

			sop[op] = i;

	}

	return false;

}

int main()

{

	int n;

	cin >> n;

	cin >> s;

	int l = 0, r = n / 2;

	while (l < r) {

		int mid =(l + r + 1)/2;

		if (check(mid))

			l = mid;

		else

			r = mid - 1;

	}

	cout << l << endl;

	return 0;

}