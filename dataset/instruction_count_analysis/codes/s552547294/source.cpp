#include <vector>

#include <map>

#include <set>

#include <stack>

#include <queue>

#include <algorithm>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <string>

#include <cstring>

#include <complex>

#include <ctime>

#include <cstdlib>



using namespace std;



inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}

template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}



typedef long long ll;



int main()

{

	int n, T[5001], dp[5001];

	while(cin >> n, n)

	{

		for(int i = 0; i < n; i++)

		{

			cin >> T[i];

		}



		memset(dp, -1, sizeof(dp));



		dp[0] = T[0];



		for(int i = 1; i < n; i++)

		{

			dp[i] = max(dp[i-1] + T[i], T[i]);

		}



		int res = -10000000;

		

		for(int i = 0; i < n; i++)

		{

			res = max(res, dp[i]);

		}



		cout << res << endl;

	}

}