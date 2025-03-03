#include "stdc++.h"

using namespace std;



#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )

template <typename Arg1>

void __f( const char* name , Arg1&& arg1 ) {

        cerr << name << " : " << arg1 << "\n";

}

template <typename Arg1, typename... Args>

void __f( const char* na , Arg1&& arg1 , Args&&... args ) {

        const char* c = strchr( na + 1 , ',' );

        cerr.write( na , c - na ) << " : " << arg1 << " , ";

        __f( c + 1 , args... );

}

#define endl "\n"

#define all(V) V.begin(),V.end()

#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int LL;

typedef pair <int,int> pii;

const int MOD = 1e9 + 7;

const int inf = 1e9;

const double EPS = 1e-9;

const double PI = acos(-1.0);

const long long INF = 1e18;

const int N = 1e5 + 5;



int a[ N ];



int main( ) {

        IO;

        #ifdef LOCAL

            //freopen( "input.txt" , "r" , stdin );

        #endif // LOCAL

        int n;

        cin >> n;

        for( int i = 1; i <= n; i++ ) cin >> a[i];

        sort( a + 1 , a + n + 1 );

        int ans = 0;

        for( int i = 1; i <= 1e5; i++ ) {

                int lo = 1 , hi = n , ret = 0 , key = i;

                while( lo <= hi ) {

                        int mid = ( lo + hi ) >> 1;

                        if( a[mid] >= key ) ret = mid , hi = mid - 1;

                        else if( a[mid] < key ) lo = mid + 1;

                }

                int big = n - ret + 1;

                int small = n - big;

                if( big == small ) ans++;

        }

        cout << ans << endl;

        return 0;

}
















