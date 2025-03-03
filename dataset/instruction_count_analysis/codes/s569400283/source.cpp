#include <stdio.h>

#include <sstream>

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

#include <numeric>

#include <iostream>

#include <array>



#define _USE_MATH_DEFINES

#include <iostream>

#include <math.h>

using namespace std;

#define REP(x,n) for(int x = 0;x < n;x++)

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<int, char> pic;

int dx[] = { -1,0,1,0 };

int dy[] = { 0,-1,0,1 };

#define bit(x,v) ((ll)x << v)



const ll INF = 1000000007;

const int MAX = 1000010;

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

int pr[100010];

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

	if (px < py) {

		pr[py] = px;

	}

	else {

		pr[px] = py;

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

struct edge {

	int from, to;

	ll val;

	edge(int from, int to, ll val) : from(from), to(to), val(val) {}

};

int k;

int _rank[1010];

int temp[1010];

bool compare_sa(int i, int j) {

	if (_rank[i] != _rank[j]) return _rank[i] < _rank[j];

	else {

		int ri = i + k <= n ? _rank[i + k] : -1;

		int rj = j + k <= n ? _rank[j + k] : -1;

		return ri < rj;

	}

}

void construct_sa(string S, int* sa) {

	n = S.length();



	for (size_t i = 0; i <= n; i++)

	{

		sa[i] = i;

		_rank[i] = i < n ? S[i] : -1;

	}



	for (k = 1; k <= n; k *= 2)

	{

		sort(sa, sa + n + 1, compare_sa);



		// saはソート後の接尾辞の並びになっている、rankは元の位置のindexを保持したまま、更新されている。

		// ピンとこなかった部分

		temp[sa[0]] = 0;

		for (size_t i = 1; i <= n; i++)

		{

			temp[sa[i]] = temp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);

		}

		for (size_t i = 0; i <= n; i++)

		{

			_rank[i] = temp[i];

		}

	}

}

bool contain(string S, int* sa, string T) {

	int a = 0, b = S.length();

	// sa は 接尾辞が辞書順に並んでいる、入っているのはその位置のインデックス

	while (b - a > 1) {

		int c = (a + b) / 2;

		if (S.compare(sa[c], T.length(), T) < 0) a = c;

		else b = c;

	}

	return S.compare(sa[b], T.length(), T) == 0;

}





#define bit(x,v) ((ll)x << v)



class BIT {



	static const int MAX_N = 400010;

public:

	BIT() { memset(bit, 0, sizeof(bit)); }

	ll bit[MAX_N + 1], n;

	ll sum(int i) {

		ll s = 0;

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





};

struct UnionFind {

	vector<int> A;

	UnionFind(int n) : A(n, -1) {}

	int find(int x) {

		if (A[x] < 0) return x;

		return A[x] = find(A[x]);

	}

	void unite(int x, int y) {

		x = find(x), y = find(y);

		if (x == y) return;

		if (A[x] > A[y]) swap(x, y);

		A[x] += A[y];

		A[y] = x;

	}

	int ngroups() {

		int ans = 0;

		for (auto a : A) if (a < 0) ans++;

		return ans;

	}

};

void yes() { cout << "Yes\n"; exit(0); }

void no() { cout << "No\n"; exit(0); }

vector<int> es[100010];

void dij(vector<int>& d,int x) {

	fill(d.begin(), d.end(), INF);

	priority_queue<pii,vector<pii>,greater<pii>> q;

	q.push(make_pair(0,x));

	while (!q.empty())

	{

		auto p = q.top();

		q.pop();

		int frm = p.second;

		int co = p.first;

		if (d[frm] <= co) continue;

		d[frm] = co;

		for (auto v : es[frm]) {

			if(d[v] > co + 1)

				q.push(make_pair(co+1,v));

		}

	}

}

ll r, s, p;

ll score(char a) {

	if (a == 'r')return p;

	if (a == 's') return r;

	if (a == 'p') return s;

	return 0;

}

void solv() {



	cin >> n;

	ll p[9],q[9];

	for (size_t i = 0; i < n; i++)

	{

		cin >> p[i];

	}



	for (size_t i = 0; i < n; i++)

	{

		cin >> q[i];

	}



	ll u = 1;

	for (int i = 1; i < n; i++)

	{

		u *= i;

	}

	ll a = 0;

	ll rp[10];

	memset(rp, 0, sizeof(rp));

	ll b = 0;

	ll rq[10];

	memset(rq, 0, sizeof(rq));

	int t = 0;

	for (ll i = n - 1; i >= 1; i--,t++)

	{

		int cn = 0;

		for (size_t j = 1; j <= n; j++)

		{

			if (j == p[t]) {

				rp[j] = 1; break;

			}

			if (rp[j] == 0) cn++;

		}

		a += u * cn;

		int cn2 = 0;

		for (size_t j = 1; j <= n; j++)

		{

			if (j == q[t]) {

				rq[j] = 1; break;

			}

			if (rq[j] == 0) cn2++;

		}

		b += u * cn2;



		u /= i;

	}

	cout << abs(a - b) << endl;

}



int main() {

	//COMinit();

	solv();

	return 0;

}