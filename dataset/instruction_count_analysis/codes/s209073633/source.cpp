#include "stdc++.h"

using namespace std;



string pial[] = {"No", "Yes"};



int main() {

    int a, b;

    cin >> a >> b;

	string s;

	cin >> s;

	int ans = 1, pos = -1;

	for(int i = 0; i < a; i++) {

	    if(s[i] < '0' || s[i] > '9') {

	        ans = 0;

	        break;

	    }

	}

	if(s[a] != '-')

	    ans = 0;

	for(int i = a + 1; i < s.size(); i++) {

	    if(s[i] < '0' || s[i] > '9') {

	        ans = 0;

	        break;

	    }

	}

	cout << pial[ans] << endl;

	

	return 0;

}