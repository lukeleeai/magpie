#include "bits/stdc++.h"

using namespace std;



int main() {

	int K, i=1;

	string s;

	set<string> S;



	cin >> s >> K;



	for (int i = 0; i < s.size(); i++) {

		for (int j = 1; j <= K; j++) {

			S.insert(s.substr(i, j));

		}

	}



	for (set<string>::iterator it = S.begin(); it != S.end(); it++) {

		if(i == K)

			cout << (*it) << " ";

		i++;

	}

	cout << endl;



	return 0;

}