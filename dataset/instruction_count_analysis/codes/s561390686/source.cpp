#include <iostream>

#include <string>

#include <iomanip>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <algorithm>



using namespace std;



#define drobucs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



int main() {

	drobucs;



	int n, a, b;

	cin >> n >> a >> b;



	if (a * n > b) {

		cout << b;

	}

	else {

		cout << a * n;

	}



	return 0;

}