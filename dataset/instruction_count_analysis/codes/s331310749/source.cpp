# include <iostream>

# include <algorithm>

# include <vector>

# include <string>

# include <set>

# include <map>

# include <cmath>

# include <iomanip>

# include <functional>

# include <utility>

# include <stack>

# include <queue>

# include <list>

# include <bitset>

# include <complex>

#include<limits.h>

#include<unordered_map>

#include<unordered_set>

#include<deque>

#include<cstdio>

typedef long long int ll;

#define rep(i,n) for(int i=0;i<n;++i)

#define ALL(x) x.begin(),x.end();

#define pp pair<ll,ll>

const int INF = 1LL << 30;

const ll LLINF = 1LL << 60;

using namespace std;

vector<pp> pps[200010];

int main() {

	int a, b, c, x,ct=0;

	cin >> a >> b >> c >> x;

	rep(i, a+1)rep(j, b+1)rep(w, c+1) {

		if (500 * i + 100 * j + 50 * w == x)++ct;

	}

	cout << ct << endl;

	return 0;

}
