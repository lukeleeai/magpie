#include "stdc++.h"

#include <boost/multiprecision/cpp_int.hpp>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;



/***** type *****/

using ll = long long;

using ld = long double;

using ml = boost::multiprecision::cpp_int;

using md = boost::multiprecision::cpp_dec_float_100;

template <class T> using vt = vector<T>;

template <class T> using vvt = vector<vector<T>>;

template <class T> using vvvt = vector<vector<vector<T>>>;

template <class T> using uset = unordered_set<T>;

template <class T1, class T2> using umap = unordered_map<T1, T2>;



/***** define *****/

#define all(c) (c).begin(), (c).end()            // begin to end

#define coutld cout << fixed << setprecision(10) // cout long double

#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat

#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse

#define pair NyaaPair                            // nyaa pair

#define first f                                  // pair::first

#define second s                                 // pair::second

/***** const value *****/

#define llong_max 9223372036854775807            // 9 * 10^18

#define ldbl_max 1.79769e+308                    // 1.7 * 10^308

#define pi 3.1415926535897932                    // 3.14 ...

#define loop_end 9223372036854775806             // LLONG_MAX-1

/***** for each macro *****/

#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)

#define each(i, e, c) fori(i, auto& e: c)

#define forir(i, v, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,true)

#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)



/***** lambda *****/

auto Count = [] // long long count value

(auto b, auto e, auto x) { return (ll)count(b, e, x); };

auto CtoL = [] // char to number

(auto c) { return (ll)(c - '0'); };

auto CeilD = [] // long double ceiling div

(auto a, auto b) { return ceil((ld)a / (ld)b); };

auto Fix = [] // fix value

(auto b, auto e, auto fix)

{ for (auto it = b; it != e; ++it) *it += fix; };

auto LtoC = [] // number to char

(auto n) { return (char)('0' + n); };

auto Pow = [] // long long pow

(auto a, auto b) { return (ll)pow(a, b); };

auto Pow2 = [] // long long pow2

(auto n) { return (1LL << n); };

auto Pow10 = [] // long long pow10

(auto n) { return (ll)pow(10, n); };

auto Size = []  // long long collection size

(auto& c) { return (ll)(c).size(); };

auto Sum = [] // long long accumulate

(auto b, auto e) { return accumulate(b, e, 0LL); };



/***** template *****/

template <class T> void MakeVVT

(ll ys, ll xs, vvt<T>& v, T fill = T())

{	// vector<vector<T>> resize + fill

	v.resize(ys); rep(y, 0, ys) v[y].resize(xs, fill);

}

template <class T> void MakeVVVT

(ll zs, ll ys, ll xs, vvvt<T>& v, T fill = T())

{	// vector<vector<vector<T>>> resize + fill

	v.resize(zs); rep(z, 0, zs) MakeVVT(ys, xs, v[z], fill);

}

template <class T> void InputVT

(ll xs, vt<T>& v, T fix = T())

{	// input vector<T> (T != struct) + fix

	v.resize(xs); rep(i, 0, xs) { cin >> v[i]; v[i] += fix; }

}

template <class T> void InputVVT

(ll ys, ll xs, vvt<T>& v, T fix = T())

{	// input vector<vector<T>> (T != struct) + fix

	MakeVVT(ys, xs, v, fix);

	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }

}

template <class T> void InputVVVT

(ll zs, ll ys, ll xs, vvvt<T>& v, T fix = T())

{	// input vector<vector<vector<T>>> (T != struct) + fix

	v.resize(zs); rep(z, 0, zs) InputVVT(ys, xs, v[z], fix);

}

template <class T1, class T2> struct NyaaPair

{	// nyaa pair template

	T1 f; T2 s;

};

template <class T1, class T2> bool

operator < (const NyaaPair<T1, T2>& l, const NyaaPair<T1, T2>& r)

{	// nyaa pair template operator <

	return (l.f != r.f) ? l.f < r.f : l.s < r.s;

}

template <class T1, class T2> bool

operator > (const NyaaPair<T1, T2>& l, const NyaaPair<T1, T2>& r)

{	// nyaa pair template operator >

	return (l.f != r.f) ? l.f > r.f : l.s > r.s;

}



/**************************************/

/********** BEGIN OF NYA LIB **********/

/**************************************/



namespace NyaGadget {}



namespace NyaGadget

{

	/*** クラスカル法ライブラリ ***/



	struct GT_Kruskal

	{

		struct Edge

		{

			long long f = 0; // from vertex

			long long t = 0; // to vertex

			long long cost = 0;

			bool operator < (const Edge& r) { return cost < r.cost; }

		};



		/**

		@brief 最小全域木の最小コストを求める

		@param lg 隣接リスト

		@note

		 計算量 O(ElogV)

		**/

		static long long Run(vector<vector<pair<long long, long long>>>& lg)

		{

			vector<Edge> edge;

			for (long long f = 0; f < (long long)lg.size(); f++)

			{	// 辺をコストでソート

				for (auto& e : lg[f])

					edge.push_back({ f, e.first, e.second });

			}

			sort(edge.begin(), edge.end());



			long long res = 0;

			UnionFind uf((long long)lg.size() + 1);

			for (auto& e : edge)

			{

				if (uf.Find(e.f) != uf.Find(e.t))

				{	// 閉路にならなければ追加

					uf.Union(e.f, e.t);

					res += e.cost;

				}

			}

			return res;

		}



		/*** UnionFindライブラリ ***/



		struct UnionFindVertex

		{	// 頂点を表現する構造体

			long long self = 0; // 自分自身のインデックス

			long long root = 0; // 根のインデックス

			long long size = 0; // 自分が属している木のサイズ

		};



		struct UnionFind

		{

			vector<UnionFindVertex> v;



			/**

			@brief コンストラクタ

			@param max 頂点数

			@note

			 [0-max)の素集合データ構造を作成する

			**/

			UnionFind(long long max)

			{	// [0-max]のデータ構造にするため、max+1でリサイズ

				v.resize(max);

				for (long long i = 0; i < max; i++)

				{	// 各頂点の根を自分自身で初期化、木サイズは1

					v[i].self = i;

					v[i].root = i;

					v[i].size = 1;

				}

			}



			/**

			@brief 根を検索する関数

			@param i 根を検索する頂点インデックス

			@note

			 引数で指定された頂点の根を返す。

			**/

			long long Find(long long i)

			{

				if (i == v[i].root) return i;



				// 根の探索をすると同時に次からO(1)で根を参照できるようにする(経路圧縮)

				v[i].root = Find(v[i].root);

				return v[i].root;

			}



			/**

			@brief 頂点を併合する関数

			@param i1 併合する頂点1

			@param i2 併合する頂点2

			@note

			 頂点i1を含む木と頂点i2を含む木を「サイズ優先で」併合する。

			 ただし、i1とi2が既に同じ木に属しているときは何もしない。

			 併合したときtrue、何もしなかったときfalseを返す。

			 サイズによる工夫により、計算量はアッカーマンの逆関数になる。

			**/

			bool Union(long long i1, long long i2)

			{

				long long root1 = Find(i1);

				long long root2 = Find(i2);



				// 既に同じ木に属しているときは何もしない

				if (root1 == root2) return false;



				// サイズの小さい木の根をサイズの大きい木の根に繋いで併合する

				if (v[root1].size < v[root2].size)

				{

					v[root1].root = root2;

					v[root2].size += v[root1].size;

				}

				else

				{

					v[root2].root = root1;

					v[root1].size += v[root2].size;

				}

				return true;

			}



			/**

			@brief 頂点を併合する関数

			@param i1 併合する頂点1

			@param i2 併合する頂点2

			@param p  親指定

			@note

			 頂点i1を含む木と頂点i2を含む木を「pを含む木を親として」併合する。

			 ただし、i1とi2が既に同じ木に属しているときは何もしない。

			 併合したときtrue、何もしなかったときfalseを返す。

			 計算量はO(logN)になり、アッカーマンの逆関数に比べて若干遅くなる。

			**/

			bool Union(long long i1, long long i2, long long p)

			{

				long long root1 = Find(i1);

				long long root2 = Find(i2);

				long long rootp = Find(p);



				// 既に同じ木に属しているときは何もしない

				if (root1 == rootp && root2 == rootp) return false;



				// 子の木を親の木へ併合する

				if (rootp == root1)

				{

					v[root2].root = rootp;

					v[rootp].size += v[root2].size;

				}

				else if (rootp == root2)

				{

					v[root1].root = rootp;

					v[rootp].size += v[root1].size;

				}

				else

				{

					v[root1].root = rootp;

					v[rootp].size += v[root1].size;

					v[root2].root = rootp;

					v[rootp].size += v[root2].size;

				}

				return true;

			}

		};

	};

}



namespace NyaGadget

{	/***** 数え上げライブラリ *****/



	template< typename T > struct NT_Counting

	{	// 引数にModライブラリを渡すことも可能



		static T P(long long n, long long r)

		{

			if (r < 0 || n < r) return 0;



			T res = 1;

			for (long long i = n; n - r < i; i--) res *= i;

			return res;

		}



		static T C(long long n, long long r)

		{

			if (r < 0 || n < r) return 0;



			T res = 1;

			for (long long i = n; n - r < i; i--) res *= i;

			for (long long i = r; 0 < i; i--) res /= i;

			return res;

		}



		static T H(long long n, long long r)

		{

			if (n < 0 || r < 0) return 0;

			return (r == 0) ? 1 : C(n + r - 1, r);

		}



		static T Catalan(long long n)

		{

			return C(2 * n, n) - C(2 * n, n - 1);

		}



		/**

		@brief 累乗の計算

		@note

		 繰り返し自乗法でxのn乗を返す。計算量O(logN)

		**/

		static T Pow(long long x, long long n)

		{

			T res = 1;

			if (0 < n)

			{

				res = Pow(x, n / 2);

				res = res * res;

				if (n % 2 != 0) res *= x;

			}

			return res;

		}

	};

}



namespace NyaGadget

{

	/***** UnionFindライブラリ *****/



	struct UnionFindVertex

	{	// 頂点を表現する構造体

		long long self = 0; // 自分自身のインデックス

		long long root = 0; // 根のインデックス

		long long size = 0; // 自分が属している木のサイズ

	};



	struct NT_UnionFind

	{

		vector<UnionFindVertex> v;



		/**

		@brief コンストラクタ

		@param max 頂点数

		@note

		 [0-max)の素集合データ構造を作成する

		**/

		NT_UnionFind(long long max)

		{	// [0-max]のデータ構造にするため、max+1でリサイズ

			v.resize(max);

			for (long long i = 0; i < max; i++)

			{	// 各頂点の根を自分自身で初期化、木サイズは1

				v[i].self = i;

				v[i].root = i;

				v[i].size = 1;

			}

		}



		/**

		@brief 根を検索する関数

		@note

		 頂点iの根を返す。

		**/

		long long Find(long long i)

		{

			if (i == v[i].root) return i;



			// 根の探索をすると同時に次からO(1)で根を参照できるようにする(経路圧縮)

			v[i].root = Find(v[i].root);

			return v[i].root;

		}



		/**

		@brief 頂点が所属する木サイズを取得する関数

		@note

		 頂点iが所属する木サイズを返す。

		**/

		long long Size(long long i)

		{

			return v[Find(i)].size;

		}



		/**

		@brief 頂点を併合する関数

		@param a 併合する頂点a

		@param b 併合する頂点b

		@note

		 頂点aを含む木と頂点bを含む木を「サイズ優先で」併合する。

		 ただし、aとbが既に同じ木に属しているときは何もしない。

		 併合したときtrue、何もしなかったときfalseを返す。

		 サイズによる工夫により、計算量はアッカーマンの逆関数になる。

		**/

		bool Union(long long a, long long b)

		{

			long long root1 = Find(a);

			long long root2 = Find(b);



			// 既に同じ木に属しているときは何もしない

			if (root1 == root2) return false;



			// サイズの小さい木の根をサイズの大きい木の根に繋いで併合する

			if (v[root1].size < v[root2].size)

			{

				v[root1].root = root2;

				v[root2].size += v[root1].size;

			}

			else

			{

				v[root2].root = root1;

				v[root1].size += v[root2].size;

			}

			return true;

		}



		/**

		@brief 頂点を併合する関数

		@param a 併合する頂点1

		@param b 併合する頂点2

		@param p  親指定

		@note

		 頂点aを含む木と頂点bを含む木を「pを含む木を親として」併合する。

		 ただし、aとbが既に同じ木に属しているときは何もしない。

		 併合したときtrue、何もしなかったときfalseを返す。

		 計算量はO(logN)になり、アッカーマンの逆関数に比べて若干遅くなる。

		**/

		bool Union(long long a, long long b, long long p)

		{

			long long root1 = Find(a);

			long long root2 = Find(b);

			long long rootp = Find(p);



			// 既に同じ木に属しているときは何もしない

			if (root1 == rootp && root2 == rootp) return false;



			// 子の木を親の木へ併合する

			if (rootp == root1)

			{

				v[root2].root = rootp;

				v[rootp].size += v[root2].size;

			}

			else if (rootp == root2)

			{

				v[root1].root = rootp;

				v[rootp].size += v[root1].size;

			}

			else

			{

				v[root1].root = rootp;

				v[rootp].size += v[root1].size;

				v[root2].root = rootp;

				v[rootp].size += v[root2].size;

			}

			return true;

		}

	};

}





/**************************************/

/*********** END OF NYA LIB ***********/

/**************************************/



using namespace NyaGadget;

//using mll = ModLL< 1000000007 >;

//using mll = ModLL< 998244353 >;



struct Nya

{

	ll id = 0;

	ll x = 0;

	ll y = 0;

};



auto NyaaSortX = [](const Nya& l, const Nya& r)

{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる

	return l.x < r.x;

};



auto NyaaSortY = [](const Nya& l, const Nya& r)

{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる

	return l.y < r.y;

};





int main(void)

{

	ll N, M; cin >> N >> M;

	vt<pair<ll, ll>> edge(M);

	each(i, e, edge)

	{

		cin >> e.f >> e.s;

		e.f--, e.s--;

	}

	reverse(all(edge));



	vt<ll> ans; ans.push_back(NT_Counting<ll>::C(N, 2));

	NT_UnionFind uf(Pow10(5) + 1);

	each(i, e, edge)

	{

		if (uf.Find(e.f) == uf.Find(e.s)) ans.push_back(ans.back());

		else ans.push_back(ans.back() - uf.Size(e.f) * uf.Size(e.s));

		uf.Union(e.f, e.s);

	}

	reverse(all(ans));



	rep(i, 1, Size(ans))

	{

		if (ans[i] < 0) cout << 0 << endl;

		else cout << ans[i] << endl;

	}

	return 0;

}
