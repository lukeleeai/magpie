#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

//#include <set>

//#include <map>

//#include <ctime>

//#include <cmath>

//#include <utility>



using namespace std;

typedef long long ll;

typedef vector<int> vi;

#define ii InputInteger( );

#define f for(int i=0; i<n; i++)

int InputInteger( ){ int x; cin >> x; return x; }

const int Inf = 2147483647;

const char e = '\n';



void iv( vi& p ){ for( int& x: p ) cin >> x; }

void sa( vi& p ){ sort( p.begin(), p.end() ); }

void sd( vi& p ){ sort( p.begin(), p.end(), [](int a, int b){ return a > b; } ); }

void pv( const vi& p ){ for( int x: p ) cout << x << ' '; cout << e; }



int main()

{

	ios_base::sync_with_stdio( false );

	cin.tie( nullptr );

	ll h;

	while( cin >> h )

	{

	    int n = ii;

	    ll sum = 0;

	    vector <int> a(n);

	    f

	    {

	        cin >> a[i];

	        sum += a[i];

	    }

	    if(sum >= h) cout << "Yes";

	    else cout << "No";

	    cout << e;

	}

	return 0;

}



// Kafe's Grandmaster Template 14th


