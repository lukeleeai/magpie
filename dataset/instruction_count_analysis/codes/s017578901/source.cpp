#include"stdc++.h"          

using namespace std;

 

#define rep(i,n) for(int i=0;i<(n);++i)

#define reps(i,n) for(int i=1;i<=(n);++i)

#define all(x) (x).begin(),(x).end()

#define int long long

#define mk_p(a,b)	make_pair((a),(b))

using pii = pair<int,int>;

constexpr int INF  = 0x3f3f3f3f;

constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;



int gcd(int a,int b){return b ? gcd(b,a%b) : a;}

int lcm(int a,int b){return a/gcd(a,b)*b;}



vector<int> a(100500);

signed main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	int n,k;

	cin >> n >> k;

	int minv = INF;

	int pnt = 0;

	reps(i,n){

		cin >> a[i];

		if(a[i] == 1) pnt = i;

	}

	int cnt = 0;

	cnt = (n + k - 1) / k;

	cout << ((n - 1) + (k - 1) - 1)/ (k - 1) << '\n';

	return 0;

}
