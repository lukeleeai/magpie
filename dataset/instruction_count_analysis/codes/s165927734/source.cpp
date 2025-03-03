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

#define _USE_MATH_DEFINES

#include <iostream>

#include <math.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<int, char> pic;

#define bit(x,v) ((ll)x << v)



const ll INF = 1000000007;

const int MAX = 210000;

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

vector<pii> es[100010];

int ci = 0;

ll P[1000010];

struct Node {

	int key;

	int priority;

	Node* parent, *left, *right;

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

void solv() {



	cin >> n;

	if (n == 0) { cout << 0 << endl; return; }



	vector<int> v;

	while (n != 0)

	{

		if (n% -2 != 0) {

			v.push_back(1);

			n -= 1;

		}

		else v.push_back(0);

		n /= -2;

	}

	reverse(v.begin(), v.end());

	for (size_t i = 0; i < v.size(); i++)

	{

		cout << v[i];

	}

	cout << endl;

}



int main() {

	//COMinit();

	solv();

	return 0;

}