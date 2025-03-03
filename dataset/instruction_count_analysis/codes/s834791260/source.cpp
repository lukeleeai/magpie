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



ll gcd(ll a, ll b) {

	if (b == 0) return a;

	return gcd(b, a%b);

}

ll lcm(ll a, ll b) {

	ll g = gcd(a, b);

	return a / g * b;

}



const ll mod = 1000000007;

const ll INF = 1 << 30;

const ll INF2 = 9000000000000000000LL;

bool fl = true;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

std::string abc = "abcdefghijklmnopqrstuvwxyz";

struct edge { ll to, cost; };

struct edge1 { ll from, to, cost; };

double pai = 3.141592653589793;

std::vector<P>v[100010];



int main() {

	ll h, w, ans = INF2;

	std::cin >> h >> w;

	if (h % 3 == 0 || w % 3 == 0) {

		std::cout << 0 << std::endl;

		exit(0);

	}

	if (h == 2 && w == 2)ans = 1;

	for (int i = 1;i < w - 1;i++) {

		ll a, b, c, max = 0, min = INF;

		a = h*i;

		b = h*((w - i) / 2);

		c = h*(w - (i + (w - i) / 2));

		max = std::max(a, std::max(b, c));

		min = std::min(a, std::min(b, c));

		ans = std::min(max - min, ans);

	}

	for (int i = 1;i < w-1;i++) {

		ll a, b, c, max = 0, min = INF;

		a = h*i;

		b = (w-i)*(h / 2);

		c = (w-i)*(h - h / 2);

		max = std::max(a, std::max(b, c));

		min = std::min(a, std::min(b, c));

		ans = std::min(max - min, ans);

	}

	for (int i = 1;i < h-1;i++) {

		ll a, b, c, max = 0, min = INF;

		a = w*i;

		b = w*((h - i) / 2);

		c = w*(h - (i + (h - i) / 2));

		max = std::max(a, std::max(b, c));

		min = std::min(a, std::min(b, c));

		ans = std::min(max - min, ans);

	}

	for (int i = 1;i < h - 1;i++) {

		ll a, b, c, max = 0, min = INF;

		a = w*i;

		b = (h-i)*(w / 2);

		c = (h-i)*(w - w / 2);

		max = std::max(a, std::max(b, c));

		min = std::min(a, std::min(b, c));

		ans = std::min(max - min, ans);

	}

	std::cout << ans << std::endl;

}