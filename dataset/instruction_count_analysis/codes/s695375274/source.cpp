#pragma GCC diagnostic ignored "-Wunused-variable" 

#include "stdc++.h"

using namespace std;



#define BOOST

#ifdef BOOST

#include <boost/multiprecision/cpp_int.hpp>

#include <boost/multiprecision/cpp_dec_float.hpp>

#include <boost/range/adaptor/reversed.hpp>

using namespace boost;

using ml = boost::multiprecision::cpp_int;

using md = boost::multiprecision::cpp_dec_float_100;

#define forir(i, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,1)

#define eachr(i, e, c) forir(i, auto &&e: adaptors::reverse(c))

#endif



/***** type *****/

using ll = long long;

using ld = long double;

using pll = pair<long long, long long>;

template <class T> using vt = vector<T>;

template <class T> using vvt = vector<vector<T>>;

template <class T> using vvvt = vector<vector<vector<T>>>;

/***** define *****/

#define all(c) (c).begin(), (c).end()            // begin to end

#define coutld cout << fixed << setprecision(10) // cout double

#define output(x) do{cout<<x<<endl;exit(0);}while(0)

#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat

#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse

#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)

#define each(i, e, c) fori (i, auto&& e: c)      // for each

/***** const value *****/

#define llong_max 9223372036854775807            // 9 * 10^18

#define ldbl_max 1.79769e+308                    // 1.7 * 10^308

#define pi 3.1415926535897932                    // 3.14 ...

/***** lambda *****/

auto Ceil = [] // if (a % b != 0) return a / b + 1;

(auto x) { return (ll)ceil(x); };

auto Count = [] // long long count value

(auto b, auto e, auto x) { return (ll)count(b, e, x); };

auto CtoL = [] // char to number

(auto c) { return (ll)c - (ll)'0'; };

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



/**************************************/

/********** BEGIN OF NYA LIB **********/

/**************************************/



namespace NyaGadget {}



namespace NyaGadget

{

	/***** UnionFindライブラリ *****/



	struct UnionFindVertex

	{	// 頂点を表現する構造体

		long long self = 0; // 自分自身のインデックス

		long long root = 0; // 根のインデックス

		long long size = 0; // 自分が属している木のサイズ

	};



	struct DS_UnionFind

	{	// 木構造で粗集合データを実現させる

		std::vector<UnionFindVertex> v;



		/**

		@brief コンストラクタ

		@param max 最大値

		@note

		 [0-max]の素集合データ構造を作成する

		**/

		DS_UnionFind(long long max)

		{	// [0-max]のデータ構造にするため、max+1でリサイズ

			v.resize(max + 1);

			for (long long i = 0; i < max + 1; i++)

			{	// 各頂点の根を自分自身で初期化、木サイズは1

				v[i].self = i;

				v[i].root = i;

				v[i].size = 1;

			}

		}



		/**

		@brief 要素xの根を検索する関数

		**/

		long long Find(long long x)

		{

			if (x == v[x].root) return x;

			// 根の探索をすると同時に次からO(1)で根を参照できるようにする(経路圧縮)

			v[x].root = Find(v[x].root);

			return v[x].root;

		}



		long long Size(long long x)

		{	// 要素xが属する集合のサイズを取得する

			return v[Find(x)].size;

		}



		bool Same(long long x, long long y)

		{	// 要素xと要素yが同じ集合かどうか調べる

			return Find(x) == Find(y);

		}



		/**

		@brief 要素を併合する関数

		@param x 併合する要素x

		@param y 併合する要素y

		@note

		 要素xを含む木と要素yを含む木を「サイズ優先で」併合する。

		 ただし、xとyが既に同じ木に属しているときは何もしない。

		 併合したときtrue、何もしなかったときfalseを返す。

		 サイズによる工夫により、計算量はアッカーマンの逆関数になる。

		**/

		bool Union(long long x, long long y)

		{

			long long root1 = Find(x);

			long long root2 = Find(y);



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

		@brief 要素を併合する関数

		@param x 併合する要素1

		@param y 併合する要素2

		@param p  親指定

		@note

		 要素xを含む木と要素yを含む木を「pを含む木を親として」併合する。

		 ただし、xとyが既に同じ木に属しているときは何もしない。

		 併合したときtrue、何もしなかったときfalseを返す。

		 計算量はO(logN)になり、アッカーマンの逆関数に比べて若干遅くなる。

		**/

		bool Union(long long x, long long y, long long p)

		{

			long long root1 = Find(x);

			long long root2 = Find(y);

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

//using mll = NT_ModLL< 1000000007 >;

//using mll = ModLL< 998244353 >;



int main(void)

{

	ll N, M; cin >> N >> M;

	vt<pll> edge(M); each(i, e, edge) cin >> e.first >> e.second;

	each(i, e, edge) --e.first, --e.second;

	reverse(all(edge));



	vt<ll> ans;

	DS_UnionFind uf(N+1);

	ll test = N * (N - 1) / 2;

	each(i, e, edge)

	{

		ans.push_back(test);

		if (uf.Find(e.first) != uf.Find(e.second)) test -= uf.Size(e.first) * uf.Size(e.second);

		uf.Union(e.first, e.second);

	}

	reverse(all(ans));

	each(i, e, ans)

	{

		if (e < 0) cout << e << endl;

		cout << e << endl;

	}

	return 0;

}


