#include <stdio.h>

#include <sstream>

#include <iostream>

#include <fstream>

#include <string.h>

#include <vector>

#include <map>

#include <algorithm>

#include <utility>

#include <set>

#include <cctype>

#include <queue>

#include <stack>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <deque>

#include <limits>

#include <iomanip>

#include <ctype.h>

#include <unordered_map>

#include <random>

#include <bitset>



#define _USE_MATH_DEFINES

#include <iostream>

#include <math.h>

#include <complex>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<ll, double> pld;

typedef pair<double, double> pdd;

typedef pair<double, ll> pdl;

typedef pair<int, char> pic;

typedef vector<ll> vl;

typedef vector<int> vi;

typedef complex<double> Point;

typedef priority_queue<ll, vector<ll>, greater<ll>> llgreaterq;

typedef priority_queue<pll, vector<pll>, greater<pll>> pllgreaterq;

typedef priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> plpllgreaterq;

typedef priority_queue<vi, vector<vi>, greater<vi>> vigreaterq;

typedef priority_queue<vl, vector<vl>, greater<vl >> vlgreaterq;

#define bit(x,v) ((ll)x << v)

#define rep(x,v) for(int x=0;x<v;x++)

#define rep2(x,f,v) for(int x=f;x<v;x++)

// 許容する誤差ε

#define EPS (1e-10)

// 2つのスカラーが等しいかどうか

#define EQ(a,b) (abs((a)-(b)) < EPS)

// 2つのベクトルが等しいかどうか

#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

const ll INF = 1000000007;

const int MAX = 2000010;

const int MOD = 1000000007;



long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {

	fac[0] = fac[1] = 1;

	finv[0] = finv[1] = 1;

	inv[1] = 1;

	for (int i = 2; i < MAX; i++) {

		fac[i] = fac[i - 1] * i % MOD;

		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

		finv[i] = finv[i - 1] * inv[i] % MOD;

	}

}



// 二項係数計算

long long COM(int n, int k) {

	if (n < k) return 0;

	if (n < 0 || k < 0) return 0;

	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

}



ll gcd(ll a, ll b) {

	if (b == 0) return a;

	return gcd(b, a % b);

}

int pr[200010];

int lank[200010];

void uini(int n) {

	for (size_t i = 0; i <= n; i++)

	{

		pr[i] = i;

	}

}



int parent(int x) {

	if (x == pr[x]) return x;

	return pr[x] = parent(pr[x]);

}



int same(int x, int y) {

	return parent(x) == parent(y);

}



bool unit(int x, int y) {

	int px = parent(x);

	int py = parent(y);



	if (px == py) return false;

	if (lank[px] < lank[py]) {

		pr[py] = px;

		lank[px] += lank[py] + 1;

	}

	else {

		pr[px] = py;

		lank[py] += lank[px] + 1;

	}

	return true;

}



ll bit[200010];

int max_n = 200000;

int pm = 0;

void add(int x) {



	while (max_n >= x)

	{

		bit[x]++;

		x += x & -x;

	}

}

void sub(int x) {

	while (max_n >= x)

	{

		bit[x]--;

		x += x & -x;

	}

}

ll merge(ll* a, int left, int mid, int right) {

	ll n1 = mid - left;

	ll n2 = right - mid;

	vector<int> L(n1 + 1);

	vector<int> R(n2 + 1);

	for (size_t i = 0; i < n1; i++)

	{

		L[i] = a[left + i];

	}

	for (size_t i = 0; i < n2; i++)

	{

		R[i] = a[mid + i];

	}



	L[n1] = INF;

	R[n2] = INF;

	ll i = 0;

	ll j = 0;

	ll r = 0;

	for (size_t k = left; k < right; k++)

	{

		if (L[i] <= R[j]) {

			a[k] = L[i];

			i++;

		}

		else {

			a[k] = R[j];

			r += n1 - i;

			j++;

		}

	}

	return r;

}

ll merge2(pair<int, char>* a, int left, int mid, int right) {

	ll n1 = mid - left;

	ll n2 = right - mid;

	vector<pair<int, char>> L(n1 + 1);

	vector<pair<int, char>> R(n2 + 1);

	for (size_t i = 0; i < n1; i++)

	{

		L[i] = a[left + i];

	}

	for (size_t i = 0; i < n2; i++)

	{

		R[i] = a[mid + i];

	}



	L[n1] = make_pair(INF, ' ');

	R[n2] = make_pair(INF, ' ');

	ll i = 0;

	ll j = 0;

	ll r = 0;

	for (size_t k = left; k < right; k++)

	{

		if (L[i].first <= R[j].first) {

			a[k] = L[i];

			i++;

		}

		else {

			a[k] = R[j];

			r += n1 - i;

			j++;

		}

	}

	return r;

}

ll mergeSort2(pair<int, char>* a, int left, int right) {

	ll res = 0;

	if (left + 1 < right) {

		int mid = (left + right) / 2;

		res = mergeSort2(a, left, mid);

		res += mergeSort2(a, mid, right);

		res += merge2(a, left, mid, right);

	}

	return res;

}

ll mergeSort(ll* a, int left, int right) {

	ll res = 0;

	if (left + 1 < right) {

		int mid = (left + right) / 2;

		res = mergeSort(a, left, mid);

		res += mergeSort(a, mid, right);

		res += merge(a, left, mid, right);

	}

	return res;

}

int partition(pair<int, char>* a, int p, int r) {

	pair<int, char> x = a[r];

	int i = p - 1;

	for (size_t j = p; j < r; j++)

	{

		if (a[j].first <= x.first) {

			i++;

			swap(a[i], a[j]);

		}

	}

	swap(a[i + 1], a[r]);

	return i + 1;

}

void quick(pair<int, char>* a, int p, int r) {

	if (p < r) {

		int q = partition(a, p, r);

		quick(a, p, q - 1);

		quick(a, q + 1, r);

	}

}



ll n;

int ci = 0;

ll P[1000010];

struct Node {

	int key;

	int priority;

	Node* parent, * left, * right;

	Node(int key, int priority);

	Node() {}

};

Node NIL;

Node::Node(int key, int priority) : key(key), priority(priority) {

	left = &NIL;

	right = &NIL;

}

Node* root = new Node();

void cenrec(Node* k) {

	if (k->key == NIL.key) return;

	cenrec(k->left);

	cout << " " << k->key;

	cenrec(k->right);

}

void fastrec(Node* k)

{

	if (k->key == NIL.key) return;

	cout << " " << k->key;

	fastrec(k->left);

	fastrec(k->right);

}

void insert(Node* v) {

	Node* y = &NIL;

	Node* x = root;

	while (x->key != NIL.key)

	{

		y = x;

		if (v->key < x->key) {

			x = x->left;

		}

		else {

			x = x->right;

		}

	}

	v->parent = y;

	if (y->key == NIL.key) {

		root = v;

	}

	else if (v->key < y->key) {

		y->left = v;

	}

	else {

		y->right = v;

	}



}



Node* find(Node* k, ll v)

{

	if (k->key == NIL.key) return &NIL;

	if (k->key == v) return k;

	if (v < k->key) return find(k->left, v);

	return find(k->right, v);

}

void delp12(Node* x) {

	if (x->key == NIL.key)  return;

	Node* l = x->left;

	Node* r = x->right;

	Node* pr = x->parent;



	if (l->key == NIL.key

		&& r->key == NIL.key) {

		if (pr->left == x) {

			pr->left = &NIL;

		}

		else pr->right = &NIL;

	}

	else if (l->key != NIL.key) {

		if (pr->left == x) {

			pr->left = l;

		}

		else pr->right = l;

		l->parent = pr;

	}

	else if (r->key != NIL.key) {

		if (pr->left == x) {

			pr->left = r;

		}

		else pr->right = r;

		r->parent = pr;

	}

}

Node* get_next(Node* k) {

	if (k->key == NIL.key) return &NIL;

	Node* res = get_next(k->left);

	if (res->key != NIL.key) return res;

	return k;

}

void del(Node* x) {



	if (x->key == NIL.key) return;

	Node* l = x->left;

	Node* r = x->right;

	Node* pr = x->parent;



	if (l->key != NIL.key && r->key != NIL.key) {

		Node* nex = get_next(r);

		x->key = nex->key;

		delp12(nex);

	}

	else {

		delp12(x);

	}

}

Node* rightRotate(Node* t) {

	Node* s = t->left;

	t->left = s->right;

	s->right = t;

	return s;

}

Node* leftRotate(Node* t) {

	Node* s = t->right;

	t->right = s->left;

	s->left = t;

	return s;

}

Node* _insert(Node* t, int key, int priority) {

	if (t->key == NIL.key) {

		return new Node(key, priority);

	}

	if (key == t->key) {

		return t;

	}



	if (key < t->key) {

		t->left = _insert(t->left, key, priority);

		if (t->priority < t->left->priority) {

			t = rightRotate(t);

		}

	}

	else {

		t->right = _insert(t->right, key, priority);

		if (t->priority < t->right->priority) {

			t = leftRotate(t);

		}

	}

	return t;

}

Node* delete1(Node* t, int key);

Node* _delete(Node* t, int key) {

	if (t->left->key == NIL.key && t->right->key == NIL.key) {

		return &NIL;

	}

	else if (t->left->key == NIL.key) {

		t = leftRotate(t);

	}

	else if (t->right->key == NIL.key) {

		t = rightRotate(t);

	}

	else

	{

		if (t->left->priority > t->right->priority) {

			t = rightRotate(t);

		}

		else

			t = leftRotate(t);

	}

	return delete1(t, key);

}

Node* delete1(Node* t, int key) {

	if (t->key == NIL.key) {

		return &NIL;

	}

	if (key < t->key) {

		t->left = delete1(t->left, key);

	}

	else if (key > t->key) {

		t->right = delete1(t->right, key);

	}

	else return _delete(t, key);

	return t;

}

int H;

int left(int i) {

	return i * 2 + 1;

}

int right(int i) {

	return i * 2 + 2;

}



// 内積 (dot product) : a・b = |a||b|cosΘ

double dot(Point a, Point b) {

	return (a.real() * b.real() + a.imag() * b.imag());

}



// 外積 (cross product) : a×b = |a||b|sinΘ

double cross(Point a, Point b) {

	return (a.real() * b.imag() - a.imag() * b.real());

}



// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0

int is_orthogonal(Point a1, Point a2, Point b1, Point b2) {

	return EQ(dot(a1 - a2, b1 - b2), 0.0);

}



// 2直線の平行判定 : a//b <=> cross(a, b) = 0

int is_parallel(Point a1, Point a2, Point b1, Point b2) {

	return EQ(cross(a1 - a2, b1 - b2), 0.0);

}



// 点cが直線a,b上にあるかないか

int is_point_on_line(Point a, Point b, Point c) {

	return EQ(cross(b - a, c - a), 0.0);

}



// 点cが線分a,b上にあるかないか(1)

int is_point_on_line1(Point a, Point b, Point c) {

	return EQ(cross(b - a, c - a), 0.0) &&

		(dot(b - a, c - a) > -EPS) &&

		(dot(a - b, c - b) > -EPS);

}



// 点cが線分a,b上にあるかないか(2)

int is_point_on_line2(Point a, Point b, Point c) {

	// |a-c| + |c-b| <= |a-b| なら線分上

	return (abs(a - c) + abs(c - b) < abs(a - b) + EPS);

}



// 点a,bを通る直線と点cとの距離

double distance_l_p(Point a, Point b, Point c) {

	return abs(cross(b - a, c - a)) / abs(b - a);

}



// 点a,bを端点とする線分と点cとの距離

double distance_ls_p(Point a, Point b, Point c) {

	if (dot(b - a, c - a) < EPS) return abs(c - a);

	if (dot(a - b, c - b) < EPS) return abs(c - b);

	return abs(cross(b - a, c - a)) / abs(b - a);

}



// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定

int is_intersected_ls(Point a1, Point a2, Point b1, Point b2) {

	return (cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS) &&

		(cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < EPS);

}



// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算

Point intersection_ls(Point a1, Point a2, Point b1, Point b2) {

	Point b = b2 - b1;

	double d1 = abs(cross(b, a1 - b1));

	double d2 = abs(cross(b, a2 - b1));

	double t = d1 / (d1 + d2);



	return a1 + (a2 - a1) * t;

}



// a1,a2を通る直線とb1,b2を通る直線の交差判定

int is_intersected_l(Point a1, Point a2, Point b1, Point b2) {

	return !EQ(cross(a1 - a2, b1 - b2), 0.0);

}



// a1,a2を通る直線とb1,b2を通る直線の交点計算

Point intersection_l(Point a1, Point a2, Point b1, Point b2) {

	Point a = a2 - a1; Point b = b2 - b1;

	return a1 + a * cross(b, b1 - a1) / cross(b, a);

}



//円の交点

pair<Point, Point> intersection_circle(Point p1, Point p2, double r1, double r2) {

	double d = abs(p2 - p1);

	double th = acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));

	return make_pair(p1 + polar(r1, arg(p2 - p1) + th), polar(r1, arg(p2 - p1) - th));

}



ll heap[2000010];

void maxHeapify(int i) {

	int l = left(i);

	int r = right(i);

	int largest = 0;

	if (l < H && heap[l] > heap[i])

		largest = l;

	else

		largest = i;

	if (r < H && heap[r] > heap[largest])

		largest = r;



	if (largest != i) {

		swap(heap[i], heap[largest]);

		maxHeapify(largest);

	}

}

int pare(int i) {

	return (i - 1) / 2;

}

void raise(int i) {

	int l = pare(i);

	if (l < 0) return;



	if (heap[l] < heap[i]) {

		swap(heap[i], heap[l]);

		raise(l);

	}

}

void minHeapify(int i) {

	int l = left(i);

	int r = right(i);

	int minimam = 0;

	if (l < H && heap[l] < heap[i])

		minimam = l;

	else

		minimam = i;

	if (r < H && heap[r] < heap[minimam])

		minimam = r;



	if (minimam != i) {

		swap(heap[i], heap[minimam]);

		minHeapify(minimam);

	}

}

void buildMaxHeap() {

	for (int i = H / 2; i >= 0; i--)

	{

		maxHeapify(i);

	}

}



int dx[] = { -1,0,1,0 };

int dy[] = { 0,-1,0,1 };

std::vector<int> find_all(const std::string str, const std::string subStr) {

	std::vector<int> result;



	int subStrSize = subStr.size();

	int pos = str.find(subStr);



	while (pos != std::string::npos) {

		result.push_back(pos);

		pos = str.find(subStr, pos + 1);

	}



	return result;

}

//ll memo[100010];

//ll next[100010];

//ll dm[100010];

//int f[100010];

//ll rec(int x) {

//

//	if (~memo[x]) return memo[x];

//	if (x == n) { 

//		dm[n] = 1;

//		return 1; 

//	}

//	ll *res = &memo[x];

//	*res = 0;

//	set<int> st;

//	st.insert(f[x]);

//	for (int i = x + 1; i <= n; i++)

//	{

//		if (~memo[i]) {

//			*res += memo[i] + 1;

//			*res %= INF;

//			break;

//		}

//

//		*res += rec(i);

//		*res %= INF;

//		if (st.find(f[i]) != st.end()) {break; }

//		st.insert(f[i]);

//	}

//

//	return *res;

//}

#define bit(x,v) ((ll)x << v)



class BIT {



	static const int MAX_N = 1000010;

public:

	BIT() { memset(bit, 0, sizeof(bit)); }

	int bit[MAX_N + 1], n;

	int sum(int i) {

		int s = 0;

		while (i > 0)

		{

			s += bit[i];

			i -= i & -i;

		}

		return s;

	}



	void add(int i, int x) {

		while (i <= n)

		{

			bit[i] += x;

			i += i & -i;

		}

	}

	void clear() {

		memset(bit, 0, sizeof(bit));

	}

	int a[MAX_N];

	void bable_swap_count() {

		ll ans = 0;

		for (size_t j = 0; j < n; j++)

		{

			ans += j - sum(a[j]);

			add(a[j], 1);

		}

		printf("%lld\n", ans);

	}



	int search(int s, int x) {



		ll half = (s + x) / 2;

		ll sh = sum(x);



		ll sl = sum(half);



		ll st = sum(s);

		if (sh - sl == 0) {

			return x;

		}

		if (sh - sl < x - half) {

			return search(half, x);

		}



		if (sl - st == 0) {

			return half;

		}



		if (sl - st < half - s) {

			return search(s, half);

		}

		return -1;

	}



	int lankSearch(int lank) {

		return lankSearch(lank, 0, MAX_N);

	}

	int lankSearch(int lank, int s, int t) {



		ll half = (s + t) / 2;



		ll v = sum(half);

		ll v1 = sum(t);

		ll v2 = sum(s);

		if (lank == 1) {

			if (s + 1 >= t) return t;

			else if (v - v2 > 0) {

				return lankSearch(lank, s, half);

			}

			else return lankSearch(lank, half, t);

		}



		if ((v - v2) < lank) {

			return lankSearch(lank - (v - v2), half, t);

		}

		if ((v - v2) >= lank) {

			return lankSearch(lank, s, half);

		}



		return -1;

	}

};



class BIT2 {



	static const int MAX_N = 1000010;

public:

	BIT2() { memset(bit, 0, sizeof(bit)); }

	ll bit[MAX_N + 1], n;

	ll gmax(int i) {

		ll s = 0;

		while (i > 0)

		{

			s = max(bit[i], s);

			i -= i & -i;

		}

		return s;

	}



	void add(int i, ll x) {

		while (i <= n)

		{

			bit[i] = max(bit[i], x);

			i += i & -i;

		}

	}

	void clear() {

		memset(bit, 0, sizeof(bit));

	}



};

vector<ll> getp(ll n) {



	vector<ll> res;

	ll a = 2;

	if (n % 2 == 0) {

		res.push_back(2);

		while (n % 2 == 0)n /= 2;

	}



	for (ll i = 3; i * i <= n; i += 2)

	{

		if (n % i == 0) {

			res.push_back(i);

			while (n % i == 0)n /= i;

		}

	}

	if (n != 1) res.push_back(n);

	return res;

}

vector<ll> getp2(ll n) {



	vector<ll> res;

	ll a = 2;

	if (n % 2 == 0) {



		while (n % 2 == 0) { n /= 2; res.push_back(2); }

	}



	for (ll i = 3; i * i <= n; i += 2)

	{

		if (n % i == 0) {



			while (n % i == 0) { n /= i; res.push_back(i); }

		}

	}

	if (n != 1) res.push_back(n);

	return res;

}

vector<pll> getp3(ll n) {



	vector<pll> res;

	ll a = 2;

	int cnt = 0;

	if (n % 2 == 0) {

		res.push_back(make_pair(2, 0));

		while (n % 2 == 0) { n /= 2; res[cnt].second++; }

		cnt++;

	}



	for (ll i = 3; i * i <= n; i += 2)

	{

		if (n % i == 0) {

			res.push_back(make_pair(n, 0));

			while (n % i == 0) { n /= i; res[cnt].second++; }

			cnt++;

		}

	}

	if (n != 1) res.push_back(make_pair(n, 1));

	return res;

}

vector<ll> getDivisors(ll n) {



	vector<ll> res;

	ll a = 2;

	res.push_back(1);

	for (ll i = 2; i * i <= n; i++)

	{



		if (n % i == 0) {

			res.push_back(i);

			if (n / i != i)

				res.push_back(n / i);

		}

	}

	return res;

}



struct ve {

public:

	vector<ve> child;

	int _t = INF;

	ve(int t) :_t(t) {}

	ve(ve _left, ve _right) {

		_t = _left._t + _right._t;

		child.push_back(_left);

		child.push_back(_right);

	}

	bool operator<(const ve& t) const {

		return _t > t._t;

	}

};



vector<bool> elas(ll n) {

	vector<bool> r(n);

	for (ll i = 3; i < n; i += 2)

	{

		r[i] = 1;

	}

	r[0] = 0;

	r[1] = 0;

	r[2] = 1;

	for (ll i = 3; i * i < n; i += 2)

	{

		if (!r[i]) continue;

		ll ti = i * 2;

		while (ti < n)

		{

			r[ti] = false;

			ti += i;

		}

	}

	return r;

}

bool isprime(ll v) {

	for (ll i = 2; i * i <= v; i++)

	{

		if (v % i == 0) return false;

	}

	return true;

}



ll lcm(vector<ll> v) {

	if (v.size() == 0) return 0;

	ll t = v[0];

	for (size_t i = 1; i < v.size(); i++)

	{

		t = v[i] * t / gcd(v[i], t);

	}

	return t;

}

ll eulerphi(ll n) {

	auto p = getp(n);

	double u = n;

	for (auto v : p) {

		u *= (double)(v - 1) / (double)v;

	}

	return u;

}



double revs(double x) {

	ll dig = 0;

	stringstream st;

	st << std::fixed << setprecision(0) << x;

	string v = st.str();

	reverse(v.begin(), v.end());

	return stod(v);

}

bool chkparindrome(double x) {

	stringstream st;

	st << std::fixed << setprecision(0) << x;

	string p = st.str();

	for (size_t i = 0; i < p.size() / 2; i++)

	{

		if (p[i] != p[p.size() - i - 1]) {

			return false;

		}

	}

	return true;

}

ll digitC(double x) {

	stringstream st;

	st << fixed << setprecision(0) << x;

	return st.str().size();

}

ll digitSum(double x) {

	stringstream st;

	st << std::fixed << x;

	string p = st.str();

	ll rs = 0;

	for (size_t i = 0; i < p.size(); i++)

	{

		if (p[i] == '.') break;

		rs += p[i] - '0';

	}

	return rs;

}

pdd recs(int x) {



	if (x == 0) return make_pair(1, 2);

	pdd d = recs(x - 1);

	auto nu = d.second * 2.0 + d.first;

	auto de = d.second;

	return make_pair(de, nu);

}

ll caldig(ll a) {

	ll r = 0;

	while (a > 0) { a /= 10; r++; }

	return r;

}

int chav(char v) {

	if (v <= 'Z') return v - 'A';

	return v - 'a' + 26;

}

char itoch(int i) {

	if (i < 26) return i + 'A';

	return (i - 26) + 'a';

}

int crmp[1000][1000];

int countR(ll base, ll x, ll y, int deep) {



	if (~crmp[x][y]) {

		return deep - crmp[x][y];

	}

	crmp[x][y] = deep;

	double nu = sqrt(base) + x;

	double de = (base - (x * x)) / y;

	ll u = nu / de;

	ll nx = x - (u * de);

	return countR(base, -nx, de, deep + 1);

}



bool isPermutation(ll x, ll y) {

	int c1[10];

	int c2[10];

	memset(c1, 0, sizeof(c1));

	memset(c2, 0, sizeof(c2));

	while (x > 0)

	{

		c1[x % 10]++;

		x /= 10;

	}

	while (y > 0)

	{

		c2[y % 10]++;

		y /= 10;

	}



	for (size_t i = 0; i < 10; i++)

	{

		if (c1[i] != c2[i]) return false;

	}

	return true;

}



double heron(ll a, ll b, ll c) {

	double s = (double)(a + b + c) / 2.0;

	return sqrt(s * (s - a) * (s - b) * (s - c));

}



double calcThreePS(double x1, double y1, double x2, double y2, double x3, double y3) {

	return abs((x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.0);

}

typedef vector<vl> mat;

class Matrix1 {



public:

	static const int M = INF;

	int n;

	mat mul(mat& A, mat& B) {

		mat C(A.size(), vl(B[0].size()));

		for (size_t i = 0; i < A.size(); i++)

		{

			for (size_t k = 0; k < B.size(); k++)

			{

				for (size_t j = 0; j < B[0].size(); j++)

				{

					C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;

				}

			}

		}

		return C;

	}



	mat pow(mat A, ll n) {

		mat B(A.size(), vl(A.size()));

		for (size_t i = 0; i < A.size(); i++)

		{

			B[i][i] = 1;

		}

		while (n > 0) {

			if (n & 1) B = mul(B, A);

			A = mul(A, A);

			n >>= 1;

		}





		return B;

	}



};

ll m;

ll stringDivRm(string s, ll k) {



	ll v = 0;

	

	for (size_t i = 0; i < s.size(); i++)

	{

		v *= 10;

		v += s[i] - '0';

		v %= k;

	}

	return v;

}



ll repPow(ll b, ll x) {

	ll res = 1;

	ll v = b;



	while (x > 0)

	{

		if (x & 1) {

			res *= v;

			res %= INF;

		}

		v *= v;

		v %= INF;

		x >>= 1;

	}



	return res;

}

void solv() {



	cin >> n;

	int p[10],q[10];



	for (size_t i = 0; i < n; i++)

	{

		cin >> p[i];

	}

	for (size_t i = 0; i < n; i++)

	{

		cin >> q[i];

	}

	int tr[10];

	for (size_t i = 0; i < n; i++)

	{

		tr[i] = i + 1;

	}

	int a = 0;

	int b = 0;

	int u = 1;

	do {

		bool ok = true;

		for (size_t i = 0; i < n && ok; i++)

		{

			if (tr[i] != p[i]) ok = false;

		}

		if (ok)a = u;

		ok = true;

		for (size_t i = 0; i < n && ok; i++)

		{

			if (tr[i] != q[i]) ok = false;

		}

		if (ok) b = u;

		u++;

	} while (next_permutation(tr, tr + n));

	cout << abs(a - b) << endl;

}









int main() {

	//COMinit();

	solv();

	return 0;

}
