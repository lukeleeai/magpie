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

typedef std::pair<ll, ll>p;

struct edge { int to, cost; };

std::vector<int>G[100000];

std::vector<int>I[100000];



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

bool fl = false;

bool f = false;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };



int main() {

	ll n, ans = 0;

	std::cin >> n;

	std::string s, t;

	s = std::to_string(n);

	t = s;

	for (int i = 0;i < s.size()-1;i++) {

		if (flag) {

			if (s[i + 1] - '0' != 9) {

				int a = s[i] - '0' - 1;

				s[i] = a + '0';

				s[i + 1] = '9';

			}

			else s[i + 1] = '9';

		}

		else s[i + 1] = '9';

		if (s < t)flag = false;

	}

	for (int i = 0;i < s.size();i++) {

		ans += s[i] - '0';

	}

	std::cout << ans << std::endl;

}