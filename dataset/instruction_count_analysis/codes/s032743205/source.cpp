#include "stdc++.h"

using namespace std;



#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)

const int N = 1e6 + 7, M = 1000000007, inf = INT_MAX;



int freq[N], f2[N];





void solve()

{

	int n;

	cin >> n;



	int arr[n], brr[n], res[n];

	lop(i, 0, n) cin >> arr[i], f2[ arr[i] ]++;

	lop(i, 0, n) cin >> brr[i], freq[ brr[i] ]++;



	lop(i, 0, n + 1) if ( f2[i] + freq[i] > n )

	{

		cout << "No" << endl;

		return;

	}



	reverse(brr, brr + n);

	vector<int> pos1, pos2;

	lop(i, 0, n)	if ( arr[i] == brr[i] )  pos1.push_back(i);

	int x = -1;

	if ( pos1.size() ) x = arr[ pos1[0] ];

	lop(i, 0, n)

	{

		if ( arr[i] == brr[i] or arr[i] == x or brr[i] == x )continue;

		pos2.push_back(i);

	}



	for (auto &i : pos1)

	{

		swap( brr[i], brr[ pos2.back() ]);

		pos2.pop_back();

	}

	cout << "Yes" << endl;

	lop(i, 0, n) cout << brr[i] << " "; cout << endl;

}



int32_t main()

{

	ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);



	int test = 1;

	// cin >> test;

	while (test--)solve();





}








































