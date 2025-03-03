#include "stdc++.h"



#define F first

#define S second

#define MP make_pair

#define pb push_back

#define all(a) a.begin(), a.end()

#define lcm( a, b ) (a)/__gcd((a),(b))*(b)

#define endl '\n'



using namespace std;



typedef long long LL;

typedef pair< int, int > P;

typedef pair< LL, LL > LP;



static const int INF = INT_MAX;

static const LL LINF = LLONG_MAX;

static const int MIN = INT_MIN;

static const LL LMIN = LLONG_MIN;

static const int MOD = 1000000007;

static const int SIZE = 200005;



const int dx[] = {0, -1, 1, 0};

const int dy[] = {-1, 0, 0, 1};



LL fac[SIZE], finv[SIZE], inv[SIZE];

void combInit() {

    fac[0] = fac[1] = 1;

    finv[0] = finv[1] = 1;

    inv[1] = 1;

    for( int i = 2; i < SIZE; ++i ) {

        fac[i] = (fac[i - 1] * i) % MOD;

        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

        finv[i] = (finv[i - 1] * inv[i]) % MOD;



    }

}



LL comb(int n, int k) {

    if( n < k ) return 0;

    if( n < 0 || k < 0 ) return 0;

    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;



}



vector< int > Div( int n ) {

    vector< int > ret;

    for( int i = 1; i * i <= n; ++i ) {

        if( n % i == 0 ) {

            ret.pb( i );



            if( i * i != n ) ret.pb( n / i );

        }

    }

    sort( all( ret ) );

    return ret;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    int n, m;

    cin >> n >> m;

    int a[SIZE];

    for( int i = 0; i < SIZE; ++i ) a[i] = -1;



    for( int i = 0; i < m; ++i ) {

        int s, c;

        cin >> s >> c;

        if( s == 1 && c == 0 ) {

            if( n == 1 ) {

                if( a[1] != -1 && a[1] != 0 ) {

                    cout << -1 << endl;

                    return 0;



                }

                a[1] = 0;

                continue;

            }

            cout << -1 << endl;

            return 0;



        }

        if( a[s] != -1 && a[s] != c ) {

            cout << -1 << endl;

            return 0;



        }

        a[s] = c;



    }

    if( m == 0 && n == 1 ) {

        cout << 0 << endl;

        return 0;



    }

    for( int i = 1; i <= n; ++i ) {

        if( a[i] == -1 ) {

            if( i == 1 ) cout << 1;

            else cout << 0;



        } else {

            cout << a[i];



        }

    }

    cout << endl;

    return 0;

}


