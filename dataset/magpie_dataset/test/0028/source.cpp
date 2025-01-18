#include "stdc++.h"

using namespace std;

int n,k,tinggi,ayy=0;

int main () {

cin  >> n >> k;

for (int i=1; i<=n; i++) {

	cin >> tinggi;

		if (tinggi >= k) {

			ayy++;

		}

}

	cout << ayy << endl;

}
