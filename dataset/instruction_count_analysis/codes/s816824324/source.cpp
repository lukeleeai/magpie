#include "stdc++.h"

#define rep(i, m, n) for(int i = m; i < (n); i++)

#define print(x) cout << (x) << endl;

#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 

#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;

#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}

#define INF (1e9)

typedef long long ll;

typedef struct{

    int x;

    int y;

} P;

ll my_gcd( ll m, ll n )

{

	// 引数に０がある場合は０を返す

	if ( ( 0 == m ) || ( 0 == n ) )

		return 0;

	

	// ユークリッドの方法

	while( m != n )

	{

		if ( m > n ) m = m - n;

		else         n = n - m;

	}

	return m;

}//gcd



using namespace std;



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    int N,X;

    ll x[100010];

    cin >> N >> X;

    rep(i,0,N){

        cin >> x[i];

    }

    ll d[100010] = {};

    rep(i,0,N){

        d[i] = abs(X - x[i]);

    }

    ll ans = d[0];

    ll d_tmp[100010] = {};

    if(N % 2 == 0){

        rep(j,0,N/2){

            d_tmp[j] = my_gcd(d[2*j],d[2*j+1]);

        }

        rep(j,0,N/2){

            ans = my_gcd(ans, d_tmp[j]);

        }

    }else{

        rep(j,0,(N-1)/2){

            d_tmp[j] = my_gcd(d[2*j],d[2*j+1]);

        }

        rep(j,0,(N-1)/2){

            ans = my_gcd(ans, d_tmp[j]);

        }

        ans = my_gcd(ans, d[N-1]);



    }

    print(ans);







}
