#include "stdc++.h"

using namespace std;



#define fi first

#define se second

#define pb push_back

#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))

#define forn(i,a,b) for(int i = a; i < b; i++)

#define forr(i,a,b) for(int i = a; i >= b; i--)

#define all(x) (x).begin(), (x).end()



typedef long long ll;

typedef long double ld;

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;



const int oo = 1<<29;

int n;

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	int res = oo;

	forn(i,1,n){

		int a = i;

		int b = n-i;

		string _a = to_string(a);

		string _b = to_string(b);

		int act = 0;

		forn(j,0,_a.size()) act += _a[j]-'0';

		forn(j,0,_b.size()) act += _b[j]-'0';

		res = min(res,act);

 	}

	cout << res << '\n';

	return 0;

}
