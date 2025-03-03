#include <iostream>

#include <algorithm>

using namespace std;

#define LL long long

#define MAX_SIZE 1010

int n, m;

LL r, a;

LL x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE], t[MAX_SIZE];



int main()

{

	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)

		cin >> x[i] >> y[i] >> z[i];



	int P[8][3] = { { 1,1,1 },{ 1,1,-1 },{ 1,-1,1 },{ 1,-1,-1 },{ -1,1,1 },{ -1,1,-1 },{ -1,-1,1 },{ -1,-1,-1 } };

	for (int i = 0; i < 8; ++i) {

		for (int j = 0; j < n; ++j)

			t[j] = x[j] * P[i][0] + y[j] * P[i][1] + z[j] * P[i][2];

		sort(t, t + n);

		a = 0;

		for (int k = n - m; k < n; ++k)

			a += t[k];

		if (r < a)

			r = a;

	}

	cout << r << endl;

	return 0;

}