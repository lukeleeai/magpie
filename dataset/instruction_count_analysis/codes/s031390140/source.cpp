#include <iostream>

#include <string>

#include <algorithm>

#include <iomanip>

#include <vector>

#include <map>

#include <cmath>

#include <queue>

#include <utility>

#include <functional>

#include <deque>

#include <cctype>

#include <stack>

#include <bitset>



using ll = long long;

typedef unsigned long long ull;

typedef std::pair<ll, ll>P;

struct edge { ll to, cost; };

std::vector<edge>v[100010], w[100010];

typedef std::vector<std::vector<int>>ma;



ll min(ll a, ll b) {

	if (a >= b)return b;

	else return a;

}

ll max(ll a, ll b) {

	if (a >= b)return a;

	else return b;

}

ll gcd(ll a, ll b) {

	if (b == 0) return a;

	return gcd(b, a%b);

}

ll lcm(ll a, ll b) {

	ll g = gcd(a, b);

	return a / g * b;

}



const ll Z = 1000000007;

const ll INF = 1 << 30;

const ll INF2 = 9000000000000000000LL;

bool flag = true;

bool fl = true;

bool f = true;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

std::string abc = "abcdefghijklmnopqrstuvwxyz";



int main() {

	int n, a[100000], b[100000], ans = 0, ma = 0, mi = INF;

	std::cin >> n;

	for (int i = 0;i < n;i++) {

		std::cin >> a[i] >> b[i];

		mi = min(b[i], mi);

		if (mi == b[i])ma = a[i];

	}

	std::cout << ma + mi << std::endl;

}