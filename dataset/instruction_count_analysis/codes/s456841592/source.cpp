#include "stdc++.h"

using namespace std;



#define int long long



const int N = 2e5 + 10;

int n;



struct TMP {

	int x, indx, ans;

	

	TMP() {

		x = indx = ans = 0;

	}

} ar[N];



int32_t main() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	

	cin >> n;

	for (int i = 0; i < n; i++)

		cin >> ar[i].x, ar[i].indx = i;

	sort(ar, ar + n, [&] (TMP a, TMP b) { return a.x < b.x; });

	

	for (int i = 0; i < n; i++)

		if (i < n / 2)

			ar[i].ans = ar[n / 2].x;

		else

			ar[i].ans = ar[n / 2 - 1].x;

	sort(ar, ar + n, [&] (TMP a, TMP b) { return a.indx < b.indx; });

	

	for (int i = 0; i < n; i++)

		cout << ar[i].ans << '\n';

}