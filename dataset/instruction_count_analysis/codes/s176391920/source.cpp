#include "stdc++.h"

using namespace std;



#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)

const int N = 1e6 + 7, M = 1000000007, inf = INT_MAX;



int freq[N], f2[N];



#define pii pair<int,int>

#define ff first

#define ss second

#define all(v) v.begin(),v.end()



void solve()

{

	int n;

	cin >> n;



	int arr[n], brr[n], res[n];

	memset(res, -1, sizeof res);

	lop(i, 0, n) cin >> arr[i], f2[ arr[i] ]++;

	lop(i, 0, n) cin >> brr[i], freq[ brr[i] ]++;



	auto cmp = [](int a, int b) {



		if ( freq[a] != freq[b] ) return freq[a] > freq[b];

		else return a > b;

	};



	lop(i, 0, n + 1) if ( f2[i] + freq[i] > n )

	{

		cout << "No" << endl;

		return;

	}



	set<int, decltype(cmp)> st(cmp);

	lop(i, 0, N) if ( freq[i] ) st.insert(i);

	int i = 0;

	while ( i < n )

	{

		int x = arr[i], id = i;

		if ( res[id] != -1 )

		{

			i++;

			continue;

		}



		auto it = st.begin();

		int rem = -1;

		if ( *it == x  ) rem = x, st.erase(rem);



		if ( rem != -1 ) it = st.begin();

		if ( it == st.end() ) {

			res[id] = x;

			int found = -1;

			vector<int> v1;

#define pb push_back

			lop(j, 0, n)

			{

				if ( j == id ) continue;

				if ( res[j] != x and res[j] != -1 and arr[j] != x ) found = j, v1.pb(j);

			}

			int sz = v1.size();

			int j = i;

			while ( j < n and arr[j] == x )

			{

				int p = v1.back();

				res[j] = res[ p ]; v1.pop_back();

				res[p] = x;

				j++;

				sz--;

				freq[x]--;

			}

		}

		else

		{

			res[id] = *it;

			int val = *it;

			st.erase(val);

			freq[val]--;

			if (freq[val]) st.insert(val);

		}

		if ( rem != -1 ) st.insert(rem);

		i++;

	}

	cout << "Yes" << endl;

	lop(i, 0, n) cout << res[i] << " "; cout << endl;

}



int32_t main()

{

	ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);



	int test = 1;

	// cin >> test;

	while (test--)solve();





}








































