#include"stdc++.h"

using namespace std;



int main() {

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;

	string s;

	cin>>n>>s;

	string t;

	for(int i=0; i<(int)s.size(); ++i) {

		int c = (int)s[i] - 'A';

		c = (c+n)%(26);

		t += (char)c+'A';

	}

	cout<<t;

}
