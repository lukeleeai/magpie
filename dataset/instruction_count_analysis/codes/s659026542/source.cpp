#include<iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<stack>

#include<queue>

#include<map>

#include<functional>

#include<math.h>



#define rep(i,n) for(ll i=0;i<(n);i++)

typedef long long ll;

using namespace std;



int main() {

	int a, b;

	cin >> a >> b;



	for (int i = 1; i < 10000;i++) {

		int zei8 = i * 0.08;

		int zei10 = i * 0.1;

		if (zei8 == a && zei10 == b) {

			cout << i << endl;

			return 0;

		}

	}

	cout << -1 << endl;



	return 0;

}