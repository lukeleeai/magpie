#include "stdc++.h"

using namespace std;

int n, nn;

set<string> res;

void f(string s) {

	if(s.length() > 0 && stoi(s) <= nn){

		set<char> st;

		for(int i=0; i<s.length(); ++i) {

			st.insert(s[i]);

		}

		if(st.size() == 3)

		  res.insert(s);

	} 

	if(s.length() == n) {

		return;

	}

	f(s + '3');

	f(s + '5');

	f(s + '7');

}



int main() {

	cin >> nn;

	n = to_string(nn).length();

	f("");

	cout << res.size() << "\n";

	return 0;

}