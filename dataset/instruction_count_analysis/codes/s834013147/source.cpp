#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <map>

#include <sstream>

#include <functional>

#include <numeric>

#include <cmath>

#include <cstring>

#include <cstdio>

#include <queue>

#include <stack>

#include <set>



using namespace std;



#define ALL(co) co.begin(), co.end()

#define tpl(...) make_tuple(__VA_ARGS__)



typedef long long LL;

typedef pair<int, int> P; typedef pair<int, P> IP; typedef pair<P, P> PP;

typedef vector<int> Array; typedef vector<vector<int> > Array2;

typedef vector<LL> LArray; typedef vector<P> PArray; typedef vector<string> SArray;



const int INF = 1 << 29;

const LL LINF = 1LL << 60;



inline int getInt() { int itiv; return (cin >> itiv, itiv); }

template <typename T> void readAll(vector<T>& vec) { for (int i = 0, size = vec.size(); i < size; i++) cin >> vec[i]; }

template <typename T, typename U> void readAll(vector<pair<T, U> >& vec) { for (int i = 0, size = vec.size(); i < size; i++) cin >> vec[i].first >> vec[i].second; }

template < typename T > inline string toString( const T &a ){ ostringstream oss; oss << a; return oss.str(); };

inline bool between(int min, int max, int n) { return min <= n && n <= max; }

inline bool inRange(int begin, int end, int n) { return begin <= n && n < end; }

inline bool inRange(int size, int n) { return 0 <= n && n < size; }



int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };



int n, l;

vector<int> turara;

vector<int> memo;



int dfs(int now)

{

	if(memo[now] != -1) return memo[now];



	int ret = 0;

	if(turara[now - 1] > turara[now])

	{

		ret = dfs(now - 1);

	}

	if(turara[now + 1] > turara[now])

	{

		ret = max(ret, dfs(now + 1));

	}

	ret += l - turara[now];



	return memo[now] = ret;

}



int main(void)

{

	ios::sync_with_stdio(false);

	while(cin >> n >> l && n)

	{

		turara.resize(n + 2);

		memo = Array(n + 2, -1);

		memo[0] = memo[n + 1] = 0;

		turara[0] = turara[n + 1] = 0;

		for (int i = 0; i < n; i++)

		{

			cin >> turara[i + 1];

		}



		int ans = 0;

		for (int i = 1; i <= n; i++)

		{

			ans = max(ans, dfs(i));

		}



		cout << ans << endl;

	}

	return 0;

}