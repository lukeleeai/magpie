#include "stdc++.h"

using namespace std;



using T = int;

const T id = INT_MAX;

T op(T l, T r) {

	return min(l, r);

}



enum COL { BLACK, RED };



struct node;

node *update(node *t);

struct node {

	T val, all;

	node *ch[2];

	COL color;

	int level;

	int size;

	node() {}

	void init(T v) {

		val = v;

		all = v;

		color = BLACK;

		level = 0;

		size = 1;

		ch[0] = ch[1] = nullptr;

	}

	void init(node *l, node *r) {

		val = id;

		color = RED;

		ch[0] = l;

		ch[1] = r;

		update(this);

	}

};



const int pmax = 8e5;

node pool[pmax];

queue<int> deleted;

int it = 0;



int count(node *t) { return !t ? 0 : t->size; }



T que(node *t) { return !t ? id : t->all; }



node *update(node *t) {

	t->size = count(t->ch[0]) + count(t->ch[1]) + (!t->ch[0] || !t->ch[1]);

	t->all = op(que(t->ch[0]), op(t->val, que(t->ch[1])));

	t->level = (t->ch[0] ? t->ch[0]->level + (t->ch[0]->color == BLACK) : 0);

	return t;

}



node *new_leaf(T v) {

	if (!deleted.empty()) {

		auto pos = deleted.front(); deleted.pop();

		pool[pos].init(v);

		return pool + pos;

	}

	assert(it < pmax);

	pool[it].init(v);

	return pool + it++;

}



node *new_node(node *l, node *r) {

	if (!deleted.empty()) {

		auto pos = deleted.front(); deleted.pop();

		pool[pos].init(l, r);

		return pool + pos;

	}

	assert(it < pmax);

	pool[it].init(l, r);

	return pool + it++;

}



void delete_node(node* t) {

	deleted.push(t - pool);

}



node *rotate(node *t, int b) {

	node *s = t->ch[1 - b];

	t->ch[1 - b] = s->ch[b];

	s->ch[b] = t;

	update(t);

	return update(s);

}



node *submerge(node *l, node *r) {

	if (l->level < r->level) {

		node *c = submerge(l, r->ch[0]);

		r->ch[0] = c;

		if (r->color == BLACK && c->color == RED && c->ch[0] && c->ch[0]->color == RED) {

			if (r->ch[1]->color == BLACK) {

				r->color = RED;

				c->color = BLACK;

				return rotate(r, 1);

			}

			c->color = BLACK;

			r->ch[1]->color = BLACK;

			r->color = RED;

		}

		return update(r);

	}

	if (l->level > r->level) {

		node *c = submerge(l->ch[1], r);

		l->ch[1] = c;

		if (l->color == BLACK && c->color == RED && c->ch[1] && c->ch[1]->color == RED) {

			if (l->ch[0]->color == BLACK) {

				l->color = RED;

				c->color = BLACK;

				return rotate(l, 0);

			}

			l->ch[0]->color = BLACK;

			c->color = BLACK;

			l->color = RED;

		}

		return update(l);

	}

	return new_node(l, r);

}



node *merge(node *l, node *r) {

	if (!l) return r;

	if (!r) return l;

	node *c = submerge(l, r);

	c->color = BLACK;

	return c;

}



pair<node*, node*> split(node *t, int k) {

	if (!t) return make_pair(nullptr, nullptr);

	if (k == 0) return make_pair(nullptr, t);

	if (k >= count(t)) return make_pair(t, nullptr);

	int c = count(t->ch[0]);

	node *l = t->ch[0], *r = t->ch[1];

	delete_node(t);

	if (k < c) {

		pair<node*, node*> p = split(l, k);

		return make_pair(p.first, merge(p.second, r));

	}

	if (k > c) {

		pair<node*, node*> p = split(r, k - c);

		return make_pair(merge(l, p.first), p.second);

	}

	return make_pair(l, r);

}



node *insert(node *t, int k, T v) {

	pair<node*, node*> s = split(t, k);

	return merge(merge(s.first, new_leaf(v)), s.second);

}



node *erase(node *t, int k) {

	pair<node*, node*> s1 = split(t, k), s2 = split(s1.second, 1);

	return merge(s1.first, s2.second);

}



T find(node *t, int l, int r) {

	if (!t) return id;

	if (r < 0 || l >= count(t)) return id;

	if (l <= 0 && r >= t->size) return t->all;

	int c = count(t->ch[0]), d = c + (!t->ch[0] || !t->ch[1]);

	return op(!t->ch[0] ? id : find(t->ch[0], l, r), op(l <= c && c < r ? t->val : id, !t->ch[1] ? id : find(t->ch[1], l - d, r - d)));

}



node *find(node *t, int k) {

	if (!t) return t;

	int c = count(t->ch[0]), b = (!t->ch[0] || !t->ch[1]);

	return c == 0 && b ? t : k < c ? find(t->ch[0], k) : find(t->ch[1], k - c - b);

}



node* build(const vector<int>& v, int lb, int ub) {

	if (ub - lb == 1) return new_leaf(v[lb]);

	int m = (lb + ub) >> 1;

	return merge(build(v, lb, m), build(v, m, ub));

}



int main()

{

	ios::sync_with_stdio(false), cin.tie(0);

	int n, q;

	cin >> n >> q;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {

		cin >> a[i];

	}

	node* root = build(a, 0, n);

	while (q--) {

		int x, y, z;

		cin >> x >> y >> z;

		if (x == 0) {

			int val = find(root, z)->val;

			root = insert(erase(root, z), y, val);

		}

		else if (x == 1) {

			printf("%d\n", find(root, y, z + 1));

		}

		else {

			root = erase(root, y);

			root = insert(root, y, z);

		}

	}

	return 0;

}


