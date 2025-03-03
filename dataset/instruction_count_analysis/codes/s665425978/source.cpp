#include "stdc++.h"



using namespace std;



// Header files, namespaces,

// macros as defined above

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;



#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>





#define f first

#define s second

#define db long double

#define pb push_back

#define sz(c) (c).size()

#define all(c) (c).begin(),(c).end()



typedef long long ll;

typedef pair <int , int> ii;

typedef pair <ii , int> iii;

typedef vector <int> vi;

typedef vector <ii> vii;

typedef vector <iii> viii;

typedef vector <vi> vvi;

typedef vector <vii> vvii;



const ll mod = 1e9+7;

const int MAXN = 1e4+5;

const int MAXK = 1e2+5;

const db eps = 1e-13;



int memo[MAXN][MAXK], n , k;

string num;

int dp( int pos , int sum , int d , bool ok ) {



    if( !ok && (d > (num[pos]-48)) )

        return 0;



    if( pos == (n-1) ) {

        return sum==0;

    }





    ok |= (d < (num[pos]-48));

    int &res = memo[pos][sum];



    if( ok && res != -1 )

        return res;



    res = 0;



    for( int dig = 0; dig < 10 ; dig++ ) {

        res = ( res + dp( pos+1, (sum + dig)%k , dig , ok ) ) % mod;

    }



    return res;

}





int main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

    cout<<setprecision(11)<<fixed;

    memset( memo , -1 , sizeof memo );

    cin>>num;

    n = sz(num);

    cin>>k;



    int ans = 0;

    for( int dig = 0 ; dig < 10 ; dig++ )

        ans = ( ans + dp( 0 , dig%k , dig , false ) )%mod;

    cout<<( ans - 1 + mod ) % mod<<"\n";

}

/*

10

8 5

10 8

6 5

1 5

4 8

2 10

3 6

9 2

1 7

*/