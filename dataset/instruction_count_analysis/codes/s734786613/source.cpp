#include <iostream>

#include <vector>

#include <string>

#include <stack>

#include <queue>

#include <deque>

#include <set>

#include <map>

#include <algorithm>	// require sort next_permutation count __gcd reverse etc.

#include <cstdlib>	// require abs exit atof atoi 

#include <cstdio>		// require scanf printf

#include <functional>

#include <numeric>	// require accumulate

#include <cmath>		// require fabs

#include <climits>

#include <limits>

#include <cfloat>

#include <iomanip>	// require setw

#include <sstream>	// require stringstream 

#include <cstring>	// require memset

#include <cctype>		// require tolower, toupper

#include <fstream>	// require freopen

#include <ctime>		// require srand

#define rep(i,n) for(int i=0;i<(n);i++)

#define ALL(A) A.begin(), A.end()



using namespace std;



typedef long long ll;

typedef pair<int, int> P;



const string keyword[] = {"that", "this" };



int affine (int a, int b, int x )

{

	return ((a*x + b ) % 26 );

}



int main()

{

//	cut here before submit 

//	freopen ("testcase.AC", "r", stdin );

	int n;

	string sn = "";

	getline (cin, sn );

	stringstream ssn (sn );

	ssn >> n;

//	scanf ("%d", &n );

	rep (i, n ){

		string str = "";

		getline (cin, str );

		int m = str.length();

		string res = "";

		for (int a = 1; a <= 26; a++ ){

			if (__gcd (a, 26 ) != 1 ) continue;

			for (int b = 0; b <= 26; b++ ){

				string s = str;

				rep (i, m ){

					if (isalpha(s[i] ) ){

						char c = (char)(affine (a, b, (int)(s[i] - 'a') ) + 'a' );

						if (isalpha (c ) ){

							s[i] = c;

						} // end if

					} // end if

				} // end rep

//				cerr << "s: " << s << endl;

				rep (i, 2 ){

					if (s.find (keyword[i] ) != string::npos ){

						res = s;

						break;

					} // end if

				} // end rep

				if (!res.empty() ) break;

			} // end for

			if (!res.empty() ) break;

		} // end for

		cout << res << endl;

	} // end loop

		

	return 0;

}