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

#define sz(c) (int)(c).size()

#define all(c) (c).begin(),(c).end()



typedef long long ll;

typedef pair <int , int> ii;

typedef pair <ii , ll> iii;

typedef vector <int> vi;

typedef vector <ii> vii;

typedef vector <iii> viii;

typedef vector <vi> vvi;

typedef vector <vii> vvii;





const int mod = 998244353;

//const db eps = 1e-13;

const ll oo = 1e18;

const int MAX = 1e6+6;

// basic operations

int mul( int a , int b ) {

    return (1ll*a*b)%mod;

}

int add( int a , int b ) {

    return (a+b)%mod;

}

int sub( int a , int b ) {

    return (a-b+mod)%mod;

}

void addSelf( int& a, int b, int m ) {

    a += b;

    b %= m;

}



int exp( int a, int b ) {



    int res = 1;

    while( b ) {



        if ( b % 2 ) {

            res = mul( res, a );

        }

        a = mul(a, a);

        b >>= 1;



    }

    return res;

}



//ll gcd[500005][20], A[500005], N, Q, a, b, r;

//void process2() {

//        int i, j;

//        for (i = 0; i < N; i++)

//                gcd[i][0] = i;

//        for (j = 1; 1 << j <= N; j++)

//                for (i = 0; i + (1 << j) - 1 < N; i++)

//                        gcd[i][j] = __gcd(gcd[i][j - 1], gcd[i + (1 << (j - 1))][j - 1]);

//}

//int RMQ(int a, int b) {

//        int k = (int) log2(b - a + 1);

//        return __gcd(gcd[a][k], gcd[b - (1 << k) + 1][k]);

//}



int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);

    int A, B;

    cin>>A>>B;

    for( int i = 0; i <= 1000000; i++ ) {



        if( (int)(0.08*i) == A && (int)(0.10*i) == B ) {

            cout<<i<<"\n";

            return 0;

        }



    }

    cout<<"-1\n";





}