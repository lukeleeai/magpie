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

#include <set>



using namespace std;

using ll = long long;

typedef unsigned long long ull;

typedef pair<ll, ll> P;

typedef pair<ll, pair<ll, ll>> PP;



const ll MOD = 1e9 + 7;

const ll INF = 1 << 30;

const ll INF2 = 9e18;

const double INF3 = 9e14;

const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

#define ALL(x) (x).begin(),(x).end()

#define pb push_back

#define fr first

#define sc second







int main() {

	ll sum = 0;

	string s;

	cin >> s;

	for (int i = 0;i < s.size();i++) {

		sum += s[i] - '0';

	}

	cout << max(sum, (ll)(s[0] - '0' - 1 + (s.size() - 1) * 9)) << endl;

	return 0;

}