#include "stdc++.h"

using namespace std;



int main(void)

{

	string s;



	getline(cin, s);

	stringstream ss(s);

	string a;



	string o = "";

	while(ss >> a)

		o += toupper(a[0]);



	cout << o << endl;



	return 0;

}