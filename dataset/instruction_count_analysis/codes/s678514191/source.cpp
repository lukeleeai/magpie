//... ...

#include<cstdio>

#include<cstring>

#include<iostream>

using namespace std;

const int M = 1e5 + 7;

int a[M];



int main() {

	int n;

	cin >> n;

	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	int l = a[1] , r = a[1];

	for(int i = 2 ; i <= n ; i++) {

		l = min(a[i] , l);

		r = max(a[i] , r);

	}

	if(r - l > 1) cout << "No" << endl;

	else {

		if(l == r) {

			int gg = n - l;

			if(gg == 1) cout << "Yes" << endl;

			else {

				if(n == 1 || gg >= l) cout << "Yes" << endl;

				else cout << "No" << endl;

			}

		} else {

			int cnt1 = 0 , cnt2 = 0;

			for(int i = 1 ; i <= n ; i++) {

				if(a[i] == l) cnt1++;

				if(a[i] == r) cnt2++;

			}

			if(cnt1 >= r) cout << "No" << endl;

			else {

				int gg = n - r;

				if(gg >= r - cnt1) cout << "Yes" << endl;

				else cout << "No" << endl;

			}

		}

	}

	return 0;

}