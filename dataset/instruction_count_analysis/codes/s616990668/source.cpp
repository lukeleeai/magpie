#include<iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<stack>

#include<queue>

#include<map>

#include<math.h>



#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;



int main() {

	int a, b; cin >> a >> b;



	for (int i = 0; i <= 1114514; i++)

	{

		int m = i * 0.08;

		int n = i * 0.1;

		if (m == a && n == b) {

			cout << i << endl;

			return 0;

		}

	}

	cout << -1 << endl;

	return 0;

}