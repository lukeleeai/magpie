#include <iostream>

#include <cstdio>

#include <cmath>

#include <ctime>

#include <cstdlib>

#include <cassert>

#include <vector>

#include <list>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <string>

#include <algorithm>

#include <utility>

#define llint long long

#define inf 1e18

#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)

#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

#define chmin(x, y) (x) = min((x), (y))

#define chmax(x, y) (x) = max((x), (y))

#define mod 1000000007



using namespace std;

typedef pair<llint, llint> P;



llint n;

llint l[200005], r[200005];

vector<P> vec;

multiset<llint> S;



int main(void)

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	

	cin >> n;

	for(int i = 1; i <= n; i++){

		cin >> l[i] >> r[i];

		if(l[i] > r[i]) swap(l[i], r[i]);

		vec.push_back(P(l[i], r[i]));

	}

	sort(vec.begin(), vec.end());

	

	for(int i = 1; i <= n; i++) S.insert(r[i]);

	

	llint lmax = vec.back().first, rmax = *S.rbegin();

	llint lmin = vec.front().first, rmin = *S.begin();

	llint ans = (rmax-rmin) * (lmax-lmin);

	

	llint Rmax = -inf;

	for(int i = 0; i < vec.size(); i++){

		if(vec[i].first > rmin) break;

		if(i > 0){

			llint lmax = vec.back().first;

			ans = min(ans, (max(Rmax,lmax)-vec[i].first)*(rmax-lmin));

		}

		Rmax = max(Rmax, vec[i].second);

		S.erase(S.lower_bound(vec[i].second));

	}

	lmax = vec.back().first;

	ans = min(ans, (max(Rmax,lmax)-rmin)*(rmax-lmin));

	cout << ans << endl;

	

	return 0;

}