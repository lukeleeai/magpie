#include"stdc++.h"

using namespace std;

const int N = 2e5 + 3;

int n, a[N];

vector<int> occ[N]; // occurrence vectors

int main() {

  	cin >> n;

  	for (int i = 0; i < n; ++i) {

      	cin >> a[i];

    	occ[a[i]].push_back(i);

    }

  	int prev = -1, taken = 0;

  	for (int val = 1; val <= n; ++val) {

  		bool found = false;

    	for (auto idx: occ[val]) {

        	if (idx > prev) {

             	prev = idx; 

              	taken++;

              	found = true;

             	break;

            }

        }

        if (!found)

        	break;

    }

  	if (taken == 0)

      	cout << -1 << endl;

	else

  		cout << n - taken << endl;

 	return 0;

}
