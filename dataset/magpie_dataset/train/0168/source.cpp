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



int m, n;

int l;



//i番目が0cmになるまでの時間

int memo[100002];

Array arr;

int dfs(int idx)

{

	if(memo[idx] != -1) return memo[idx];



	int lt = 0, rt = 0;

	if(arr[idx] < arr[idx - 1])

		lt = dfs(idx - 1);

	if(arr[idx] < arr[idx + 1])

		rt = dfs(idx + 1);



	return memo[idx] = max(lt, rt) + (l - arr[idx]);

}



int main(void)

{

	while(cin >> n >> l && n)

	{

		memset(memo, -1, sizeof(memo));

		memo[0] = 0;

		memo[n + 1] = 0;

		arr.resize(n + 2);

		for (int i = 0; i < n; i++)

		{

			cin >> arr[i + 1];

		}



		int ans = 0;

		for (int i = 1; i < n + 1; i++)

		{

			ans = max(ans, dfs(i));

		}

		cout << ans << endl;

	}

	return 0;

}