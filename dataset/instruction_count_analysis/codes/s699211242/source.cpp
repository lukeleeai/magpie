#include<iostream>

#include<algorithm>

#include<string>

#include<cstring>

#include<queue>

#include<stack>

#include<cmath>

#include<set>

#include<vector>

#include<map>

#include<unordered_map>

#include<iomanip>

#define ll long long

#define pll pair<ll,ll>



using namespace  std;

ll gcd(ll a, ll b) {

	return b == 0 ? a : gcd(b, a%b);

}

ll qpow(ll a, ll b, ll modd) {

	ll ans = 1, base = a;

	while (b) {

		if (b & 1) {

			ans = (ans*base) % modd;

		}

		base = (base*base) % modd;

		b >>= 1;

	}

	return ans;

}



/*A*/

//ll modd = 1000000007;

//const int N = 1e5 + 5;

//const int M = 2e5 + 10;

//ll fact[M];

//ll exgcd(ll a,ll b,ll &x,ll &y) {

//	if (b == 0) return x = 1, y = 0, a;

//	ll d = exgcd(b, a%b, y, x);

//	y -= (a / b)*x;

//	return d;

//}

//ll inv(ll a, ll p) {

//	ll x, y, d;

//	d = exgcd(a, p, x, y);

//	return d == 1 ? (x%p + p) % p : -1;

//}

//void fac() {

//	fact[0] = fact[1] = 1;

//	for (int i = 2; i <= M - 5; ++i) {

//		fact[i] = (fact[i - 1] * i) % modd;

//	}

//}

//ll C(ll n, ll m) {

//	return (fact[n] * inv(fact[m],modd) % modd)*inv(fact[n - m],modd) % modd;

//}

//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	ll n, m; cin >> n >> m;

//	fac();

//	cout <<C(n+m-4,m-2) ;

//}



//****************************************************************************

/*B*/

//int mp[1005][1005];

//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	while (1) {

//		int n, m; cin >> n >> m;

//		if (n == 0 && m == 0) {

//			break;

//		}

//		for (int i = 1; i <= m; ++i) {

//			int u, v, w;

//			cin >> u >> v >> w;

//			mp[u][v] = mp[v][u] = w;

//		}

//

//	}

//	

//}



//****************************************************************************

/*C*/

//int xx[20], yy[20];

//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	while (1) {

//		int n; cin >> n;

//		if (!n) {

//			break;

//		}

//		for (int i = 1; i <= n; ++i) {

//			cin >> xx[i] >> yy[i];

//		}

//

//	}

//

//

//}



//****************************************************************************

/*D*/

//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	string str;

//	while (cin >> str) {

//		string s1 = str.substr(0,6), s2 = str.substr(6,6) ;

//		int t = 0, flag = 0;

//		for (int i = 0; i < 3; ++i) {

//			for (int j = 0; j < 6; ++j) {

//				if (s1[i] == s2[j] && s1[5 - i] == s2[5 - j]) {

//					t++;

//					s1[i] = s2[j] = s1[5 - i] = s2[5 - j] = ' ';

//					break;

//				}

//				

//			}

//			//if (t == 3) {

//			//	flag = 1; break;

//			//}

//		}

//		if (t==3) {

//			cout << "TRUE" << '\n';

//		}

//		else {

//			cout << "FALSE" << '\n';

//		}

//	}

//

//}



//****************************************************************************

/*E*/

//int f[10] = { 1,0,0,0,1,0,1,0,2,1 };

//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	int t; cin >> t;

//	while (t--) {

//		int x, k; cin >> x >> k;

//		int flag = 0;

//		while (k--) {

//			int sum = 0;

//			if (x > 0) {

//				while (x) {

//					sum += f[x % 10];

//					x /= 10;

//				}

//			}

//			else {

//				sum = 1;

//			}

//			x = sum;

//			if (x == 0 ) {

//				if (k % 2)

//				{

//					flag = 1; cout << 1 << '\n';

//				}

//				else {

//					flag = 1; cout << 0 << '\n';

//				}

//				break;

//			}

//			if (x == 1 ) {

//				if (k % 2)

//				{

//					flag = 1; cout << 0 << '\n';

//				}

//				else {

//					flag = 1; cout << 1 << '\n';

//				}

//				break;

//			}

//		}

//		if (flag) {

//			continue;

//		}

//		else {

//			cout << x << '\n';

//		}

//	}

//}



//****************************************************************************

/*F*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	int t; cin >> t;

//	while (t--) {

//		ll n, k; cin >> n >> k;

//		string s; cin >> s;

//		ll u_cnt = 0,cntl=0,cntr=0,cntu=0,cntd=0;

//		ll step = 0,maxstep = 0;

//		ll xx = 0, yy = 0;

//		for (int i = 0; i < n; ++i) {

//			if (s[i] == 'L') {

//				cntl++;

//			}

//			else if (s[i] == 'R') {

//				cntr++;

//			}

//			else if (s[i] == 'U') {

//				cntu++;

//			}

//			else if (s[i] == 'D') {

//				cntd++;

//			}

//			step = abs(cntl - cntr) + abs(cntu - cntd);

//			maxstep = max(step, maxstep);

//		}

//		xx = cntl - cntr;

//		yy = cntu - cntd;

//		xx *= (k - 1); yy *= (k - 1);

//		for (int i = 0; i < n; ++i) {

//			if (s[i] == 'L') {

//				xx++;

//			}

//			else if (s[i] == 'R') {

//				xx--;

//			}

//			else if (s[i] == 'U') {

//				yy++;

//			}

//			else if (s[i] == 'D') {

//				yy--;

//			}

//			step = abs(xx) + abs(yy);

//			maxstep = max(step, maxstep);

//		}

//		cout << maxstep << '\n';

//		

//	}

//}





//****************************************************************************

/*G*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	

//

//}



//****************************************************************************

/*H*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);



//}



//****************************************************************************

/*I*/



int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	ll s; cin >> s;

	if (s == 1000000000000000000) {

		cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 0 << " " << 1000000000; return 0;

	}

	ll x3 = 1000000000 - (s % 1000000000);

	ll y3 = s / 1000000000 + 1;

	cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << x3 << " " << y3;

}



//****************************************************************************



/*J*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);

//	string x11;

//	double x1,y1, x2, y2, x3, y3;

//	while (1) {

//		cin >> x11;

//		if (x11.compare("END")) {

//			break;

//		}

//		x1 = stod(x11);

//		cin >> y1 >> x2 >> y2 >> x3 >> y3;

//

//	}

//}



//****************************************************************************



/*K*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);



//}



//****************************************************************************



/*L*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);



//

//}



//****************************************************************************



/*M*/



//int main() {

//	ios::sync_with_stdio(0); cin.tie(0);



//}



//****************************************************************************