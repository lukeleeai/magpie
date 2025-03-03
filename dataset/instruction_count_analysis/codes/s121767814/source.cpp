  ///====================== khela STARTS HERE =====================///

#include "bits/stdc++.h"

const int inf = 1000000005;

const long long INF = 3e18;

const double pi = 2 * acos ( 0.0 );

typedef long long ll;

#define pii pair<int, int>

#define pb push_back

#define pf push_front

#define all(v) v.begin(), v.end()

#define maximum *max_element

#define minimum *min_element

#define MEMSET(v, x) memset(v, x, sizeof(v))

#define ABS(x) ((x)<0?-(x):(x))

#define white 1

#define grey 2

#define black 3

#define bug cout << "ei porjonto thikase" << endl;

#define fastread ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int gcd (int a, int b ) {

    a =  abs( a ); b = abs( b );

    while ( b ) { a = a % b; swap ( a, b ); } return a;}

int modInverse(int a, int m)

{int m0 = m;int y = 0, x = 1;if (m == 1)return 0;

while (a > 1){int q = a / m;int t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}

int lcm(int a, int b)

{int temp = gcd(a, b);return temp ? (a / temp * b) : 0;}

///====================== khela end1s HERE =====================///

const int maxn = 55;

int arr[maxn];

ll dp[maxn][101*101], p, n;

ll call(int i, int ammount){

	if(i>=n){

		if(ammount%2 == p)return 1;

		else{

			return 0;

		}

	}

	if(dp[i][ammount] == -1){

		ll ret1 = 0, ret2 = 0;

		ret1 = call(i+1, arr[i]+ammount);

		ret2 = call(i+1, ammount);

		dp[i][ammount] = ret1 + ret2;

	}

	return dp[i][ammount];

}



int main(int argc, char const *argv[])

{

	cin >> n >> p;

	for(int i=0; i<n; i++)cin >> arr[i];

	MEMSET(dp, -1);

	cout << call(0, 0) << endl;

}