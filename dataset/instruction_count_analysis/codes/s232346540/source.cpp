//Littleboy123 Template 1.1



#include "stdc++.h"

using namespace std;



//pragmas

/*

#pragma comment(linker, "/stack:200000000")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC target ("avx2")

#pragma GCC optimization ("Ofast")

#pragma GCC optimization ("unroll-loops")

*/



typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

typedef long long int ll;

typedef unsigned long long int ull;

typedef long double ld;



#define FOR(a,b,c) for(ll (a)=(b);(a)<(c);++(a))

#define FORE(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))

#define FORN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))

#define FORNE(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))

#define COUT(a) cout << (a) << '\n'

#define MEM(a,b) memset((a), (b), sizeof((a)))

#define MAX(a,b) (a) = max((a), (b))

#define MIN(a,b) (a) = min((a), (b))

#define nl '\n'

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define pi acos(-1.0)



void init(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

}



//End of template



int main(){

	init();



	//debug

	/*

	ifstream in("input.in");

	streambuf *cinbuf = std::cin.rdbuf();

	cin.rdbuf(in.rdbuf());



	ofstream out("out.txt");

	streambuf *coutbuf = std::cout.rdbuf();

	cout.rdbuf(out.rdbuf());

	*/

	//end debug



	string s;

	cin >> s;

	cout << "2018" << s.substr(4, s.length()) << nl;

	return 0;

}