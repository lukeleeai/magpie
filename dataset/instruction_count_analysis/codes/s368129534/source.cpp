#include "stdc++.h"

#include <ext/pb_ds/detail/standard_policies.hpp>

#define int long long

#define double long double

#define endl "\n"

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb(x) push_back(x)

#define mp(a,b) make_pair(a,b)

#define ms(v,x) memset(v,x,sizeof(v))

#define pii pair<int,int>

#define ff first

#define ss second

#define frr(i,n) for(int i=0;i<n;i++)

#define td(v) v.begin(),v.end()

#define inf 1000000000 // 1e9

#define M   1000000007 // 1e9 + 7

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}

int lcm(int a,int b){return (a*b)/gcd(a,b);}

int exp(int a,int b,int m){

    if(b==0) return 1;

    if(b==1) return mod(a,m);

    int k = mod(exp(a,b/2,m),m);

    if(b&1){

        return mod(a*mod(k*k,m),m);

    }

    else return mod(k*k,m);

}

main(){

    fastio;

    string s;

	cin >> s;

	if(s[0] == s[1] || s[1]==s[2] || s[2]==s[3]){

		cout << "Bad\n";

	}

	else cout << "Good\n";

    

}
