#include "stdc++.h"

using namespace std;



int main(void)

{

	string s;

	cin >> s;



	vector<int> v(26, 0);

	for(int i = 0; i < s.length(); i++)

		v[s[i] - 'a']++;



	bool b = 1;

	for(int i = 0; i < 26; i++){

		if(v[i] & 1){

			b = 0;

			cout << "No" << endl;

			break;

		}

	}

	if(b)

		cout << "Yes" << endl;



	return 0;

}
