#include"stdc++.h"

using namespace std;

deque<int>d;

int n,ans,a;

int main() {

	ios::sync_with_stdio(false);

	cin >> n;

	for(int i = 1; i <= n; i++) {

		cin >> a;

		if(i & 1)

			d.push_back(a);

		else

			d.push_front(a);

	}

	if(n & 1)

		reverse(d.begin(),d.end());

	deque<int>::iterator it;

	for(it = d.begin(); it != d.end(); it++)

		cout << *it << " ";

	cout << endl;

	return 0;

}