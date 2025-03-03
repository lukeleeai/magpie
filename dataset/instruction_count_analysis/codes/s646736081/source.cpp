#include <iostream>

#include <algorithm>

#include <array>

#include <cstdint>

#include <functional>

#include <map>

#include <math.h>

#include <queue>

#include <set>

#include <stack>

#include <stdlib.h>

#include <string>

#include <time.h>

#include <utility>

#include <vector>



#define INF 1000000000

#define MOD 1000000007

#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)

#define bitget(a,b) (((a) >> (b)) & 1)

#define ALL(x) (x).begin(),(x).end()

#define C(x) std::cout << #x << " : " << x << std::endl

#define scanf scanf_s



using int32 = std::int_fast32_t;

using int64 = std::int_fast64_t;

using uint32 = std::uint_fast32_t;

using uint64 = std::uint_fast64_t;



#include <iostream>

#include <algorithm>

#include <array>

#include <cstdint>

#include <functional>

#include <map>

#include <math.h>

#include <queue>

#include <set>

#include <stack>

#include <stdlib.h>

#include <string>

#include <time.h>

#include <utility>

#include <vector>



#define INF 1000000000

#define MOD 1000000007

#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)

#define bitget(a,b) (((a) >> (b)) & 1)

#define ALL(x) (x).begin(),(x).end()

#define C(x) std::cout << #x << " : " << x << std::endl

#define scanf scanf_s



using int32 = std::int_fast32_t;

using int64 = std::int_fast64_t;

using uint32 = std::uint_fast32_t;

using uint64 = std::uint_fast64_t;

template<typename Monoid, typename Operand>

struct RBnode {

	RBnode *ch[2], *par;

	Monoid value, sum;

	Operand lazy;

	uint32 size, height;

	bool color, reversed;//true=black

};

template<typename Monoid, typename Operand>

class RBTrees {

	using Node = RBnode<Monoid, Operand>;

	std::vector<Node> nodes;

	uint32 itr;

	bool balanced;

	Node *backup;

public:

	RBTrees(size_t maxsize) {

		nodes.resize(maxsize + 1);

		itr = 0;

		nodes[0].ch[0] = &nodes[0];

		nodes[0].ch[1] = &nodes[0];

		nodes[0].par = nullptr;

		nodes[0].size = 0;

		nodes[0].height = 1;

		nodes[0].color = 1;

	}

	Node *nil(void) {

		return &nodes[0];

	}

	Node *recalc(Node *node) {

		node->sum = node->value;

		if (node->ch[0] != &nodes[0]) {

			node->sum = node->ch[0]->sum + node->sum;

		}

		if (node->ch[1] != &nodes[0]) {

			node->sum = node->sum + node->ch[1]->sum;

		}

		node->size = node->ch[0]->size + 1 + node->ch[1]->size;

		return node;

	}

	void push(Node *node) {

		node->ch[0]->lazy = node->ch[0]->lazy * node->lazy;

		node->ch[1]->lazy = node->ch[1]->lazy * node->lazy;

		node->value = node->value * node->lazy;

		node->sum = node->sum * node->lazy;

		node->lazy.inactive();

		if (node->reversed) {

			node->ch[0]->reversed ^= 1;

			node->ch[1]->reversed ^= 1;

			std::swap(node->ch[0], node->ch[1]);

			node->sum.reverse();

			node->value.reverse();

			node->reversed = 0;

		}

		return;

	}

	Node *rotate(Node *node, uint32 dir) {

		Node *t = node->ch[dir ^ 1];

		node->ch[dir ^ 1] = t->ch[dir];

		t->ch[dir]->par = node;

		node->height = t->ch[dir]->height;

		t->height = node->height + node->color;

		t->color = node->color;

		node->color = 0;

		t->par = node->par;

		node->par = t;

		t->ch[dir] = recalc(node);

		return recalc(t);

	}

	Node *insert(Node *root, const Monoid &value, uint32 position) {

		nodes[++itr].ch[0] = &nodes[0];

		nodes[itr].ch[1] = &nodes[0];

		nodes[itr].value = value;

		nodes[itr].sum = value;

		nodes[itr].lazy.inactive();

		nodes[itr].size = 1;

		nodes[itr].height = 1;

		nodes[itr].color = 0;

		nodes[itr].reversed = 0;

		backup = nullptr;

		push(root);

		root = _subinsert(root, position);

		if (!root->color) {

			root->height += 1;

			root->color = 1;

		}

		return root;

	}

	Node *_subinsert(Node *node, uint32 pos) {

		if (node == &nodes[0]) {

			balanced = 1;

			nodes[itr].par = backup;

			return &nodes[itr];

		}

		backup = node;

		push(node->ch[0]);

		push(node->ch[1]);

		if (node->ch[0]->size < pos) {

			node->ch[1] = _subinsert(node->ch[1], pos - node->ch[0]->size - 1);

			if (balanced) {

				return _insertadjust(node, 1);

			}

		}

		else {

			node->ch[0] = _subinsert(node->ch[0], pos);

			if (balanced) {

				return _insertadjust(node, 0);

			}

		}

		return recalc(node);

	}

	Node *_insertadjust(Node *node, uint32 dir) {

		if (!node->color) {

			return recalc(node);

		}

		if (!node->ch[dir ^ 1]->color) {

			if (node->ch[dir]->ch[dir]->color&&node->ch[dir]->ch[dir ^ 1]->color) {

				balanced = 0;

				return recalc(node);

			}

			return flip(recalc(node));

		}

		balanced = 0;

		if (node->ch[dir]->ch[dir]->color) {

			if (node->ch[dir]->ch[dir ^ 1]->color) {

				return recalc(node);

			}

			else {

				node->ch[dir] = rotate(node->ch[dir], dir);

				return rotate(node, dir ^ 1);

			}

		}

		else {

			if (node->ch[dir]->ch[dir ^ 1]->color) {

				return rotate(node, dir ^ 1);

			}

			else {

				node->ch[dir] = rotate(node->ch[dir], dir);

				balanced = 1;

				node = rotate(node, dir ^ 1);

				return flip(node);

			}

		}

	}

	Node *flip(Node *node) {

		node->ch[0]->color = 1;

		node->ch[0]->height += 1;

		node->ch[1]->color = 1;

		node->ch[1]->height += 1;

		node->color = 0;

		return node;

	}

	Node *access(Node *root, uint32 position) {

		while (root->ch[0]->size != position) {

			if (position > root->ch[0]->size) {

				position -= root->ch[0]->size + 1;

				root = root->ch[1];

			}

			else {

				root = root->ch[0];

			}

		}

		return root;

	}

	Node *erase(Node *root, uint32 position) {

		push(root);

		return _suberase(root, position);

	}

	Node *_suberase(Node *node, uint32 position) {

		push(node->ch[0]);

		push(node->ch[1]);

		if (node->ch[0]->size > position) {

			node->ch[0] = _suberase(node->ch[0], position);

			if (balanced) {

				return _eraseadjust(node, 0);

			}

			return recalc(node);

		}

		if (node->ch[0]->size < position) {

			node->ch[1] = _suberase(node->ch[1], position - node->ch[0]->size - 1);

			if (balanced) {

				return _eraseadjust(node, 1);

			}

			return recalc(node);

		}

		if (node->ch[0] != &nodes[0]) {

			if (node->ch[1] != &nodes[0]) {

				node->ch[1] = _suberase(node->ch[1], 0);

				node->value = backup->value;

				if (balanced) {

					return _eraseadjust(node, 1);

				}

				return recalc(node);

			}

			node->ch[0]->par = node->par;

			node->ch[0]->color = 1;

			++node->ch[0]->height;

			balanced = 0;

			return node->ch[0];

		}

		backup = node;

		if (node->ch[1] != &nodes[0]) {

			node->ch[1]->par = node->par;

			node->ch[1]->color = 1;

			++node->ch[1]->height;

			balanced = 0;

			return node->ch[1];

		}

		balanced = node->color;

		return &nodes[0];

	}

	Node *_eraseadjust(Node *node, uint32 dir) {

		if (node->ch[dir ^ 1]->ch[0]->color&&node->ch[dir ^ 1]->ch[1]->color) {

			if (node->ch[dir ^ 1]->color) {

				node->ch[dir ^ 1]->color = 0;

				--node->ch[dir ^ 1]->height;

				balanced = node->color;

				node->height -= node->color;

				node->color = 1;

				return recalc(node);

			}

			push(node->ch[dir ^ 1]->ch[0]);

			push(node->ch[dir ^ 1]->ch[1]);

			node = rotate(node, dir);

			node->ch[dir] = _eraseadjust(node->ch[dir], dir);

			return node;

		}

		balanced = 0;

		push(node->ch[dir ^ 1]->ch[0]);

		push(node->ch[dir ^ 1]->ch[1]);

		if (node->ch[dir ^ 1]->ch[dir ^ 1]->color) {

			push(node->ch[dir ^ 1]->ch[dir]->ch[0]);

			push(node->ch[dir ^ 1]->ch[dir]->ch[1]);

			node->ch[dir ^ 1] = rotate(node->ch[dir ^ 1], dir ^ 1);

		}

		node = rotate(node, dir);

		++node->height;

		++node->ch[0]->height;

		node->ch[0]->color = 1;

		++node->ch[1]->height;

		node->ch[1]->color = 1;

		return node;

	}

	Monoid range(Node *root, uint32 begin, uint32 end) {

		Node *t = root;

		Monoid ret;

		while (1) {

			push(t);

			if (t->ch[0]->size < begin) {

				begin -= t->ch[0]->size + 1;

				end -= t->ch[0]->size + 1;

				t = t->ch[1];

				continue;

			}

			if (t->ch[0]->size < end) {

				end -= t->ch[0]->size + 1;

				ret = t->value;

				root = t->ch[0];

				t = t->ch[1];

				break;

			}

			t = t->ch[0];

		}

		while (root != &nodes[0]) {

			push(root);

			if (root->ch[0]->size < begin) {

				begin -= root->ch[0]->size + 1;

				root = root->ch[1];

				continue;

			}

			if (root->ch[1] != &nodes[0]) {

				push(root->ch[1]);

				ret = (root->value + root->ch[1]->sum) + ret;

			}

			else ret = root->value + ret;

			root = root->ch[0];

		}

		while (t != &nodes[0]) {

			push(t);

			if (t->ch[0]->size < end) {

				end -= t->ch[0]->size + 1;

				if (t->ch[0] != &nodes[0]) {

					push(t->ch[0]);

					ret = ret + (t->ch[0]->sum + t->value);

				}

				else ret = ret + t->value;

				t = t->ch[1];

				continue;

			}

			t = t->ch[0];

		}

		return ret;

	}

	void update(Node *root, uint32 begin, uint32 end, const Operand &data) {

		Node *t = root;

		push(t);

		while (1) {

			push(t->ch[0]);

			push(t->ch[1]);

			if (t->ch[0]->size < begin) {

				begin -= t->ch[0]->size + 1;

				end -= t->ch[0]->size + 1;

				t = t->ch[1];

				continue;

			}

			if (t->ch[0]->size < end) {

				end -= t->ch[0]->size + 1;

				t->value = t->value*data;

				backup = t;

				break;

			}

			t = t->ch[0];

		}

		root = t->ch[0];

		while (root != &nodes[0]) {

			backup = root;

			if (root->ch[0]->size < begin) {

				begin -= root->ch[0]->size + 1;

				push(root->ch[0]);

				push(root->ch[1]);

				root = root->ch[1];

				continue;

			}

			root->value = root->value*data;

			root->ch[1]->lazy = root->ch[1]->lazy*data;

			push(root->ch[0]);

			push(root->ch[1]);

			root = root->ch[0];

		}

		while (backup != t) {

			backup = recalc(backup)->par;

		}

		root = t->ch[1];

		while (root != &nodes[0]) {

			t = root;

			if (root->ch[0]->size < end) {

				end -= root->ch[0]->size + 1;

				root->value = root->value*data;

				root->ch[0]->lazy = root->ch[0]->lazy*data;

				push(root->ch[0]);

				push(root->ch[1]);

				root = root->ch[1];

				continue;

			}

			push(root->ch[0]);

			push(root->ch[1]);

			root = root->ch[0];

		}

		while (t != nullptr) {

			t = recalc(t)->par;

		}

		return;

	}

	Node *_submerge(Node *left, Node *right, Node *mid) {

		uint32 dir = 1;

		if (left->height < right->height) {

			dir = 0;

			std::swap(left, right);

		}

		if (right == &nodes[0]) {

			uint32 t = itr;

			itr = (mid - &nodes[0]) - 1;

			if (dir) {

				left = insert(left, mid->value, left->size);

			}

			else {

				left = insert(left, mid->value, 0);

			}

			itr = t;

			return left;

		}

		push(left);

		push(right);

		while (left->height != right->height) {

			push(left->ch[0]);

			push(left->ch[1]);

			left = left->ch[dir];

		}

		mid->ch[dir ^ 1] = left;

		mid->ch[dir] = right;

		recalc(mid)->par = left->par;

		mid->height = left->height;

		mid->color = 0;

		left->par = mid;

		right->par = mid;

		push(left->ch[0]);

		push(left->ch[1]);

		balanced = 1;

		while (mid->par != nullptr) {

			mid->par->ch[dir] = mid;

			mid = mid->par;

			if (balanced) {

				mid = _insertadjust(mid, dir);

			}

			else {

				recalc(mid);

			}

		}

		if (!mid->color) {

			++mid->height;

			mid->color = 1;

		}

		return mid;

	}

	Node *merge(Node *left, Node *right) {

		if (right == &nodes[0]) {

			return left;

		}

		right = erase(right, 0);

		return _submerge(left, right, backup);

	}

	void show(Node *node) {

		std::cout << "(";

		if (node->ch[0] != &nodes[0]) {

			show(node->ch[0]);

			std::cout << "←";

		}

		std::cout << node->size << " " << (node->color?"黒":"赤") << " " << node->height;

		if (node->ch[1] != &nodes[0]) {

			std::cout << "→";

			show(node->ch[1]);

		}

		std::cout << ")";

		return;

	}

	void check(Node *node) {

		if (node->ch[0] != &nodes[0]) {

			if (node->ch[0]->par != node)

				std::cerr << "#\n";

			check(node->ch[0]);

		}

		if (node->ch[1] != &nodes[0]) {

			if (node->ch[1]->par != node)

				std::cerr << "#\n";

			check(node->ch[1]);

		}

	}

};

struct SUB {

	int32 e;

	bool a;

	SUB() { inactive(); }

	SUB(int32 x, bool y) { e = x; a = y; }

	void inactive(void) {

		a = false;

	}

	SUB operator*(const SUB &other) {

		if (other.a) return other;

		return *this;

	}

};

struct MIN {

	int32 e;

	MIN() { set(); }

	MIN(int32 x) { e = x; }

	void set() { e = 2147483647; }

	void reverse(void) {}

	MIN operator+(const MIN &other) {

		if (e < other.e) return *this;

		return other;

	};

	MIN operator*(const SUB &other) {

		if (other.a) return MIN(other.e);

		return *this;

	}

};

int main(void) {

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	uint32 n, q;

	std::cin >> n >> q;

	RBTrees<MIN, SUB> T(n);

	RBnode<MIN, SUB> *r = T.nil();

	uint32 c;

	uint32 s, t;

	SUB x;

	x.a = 1;

	/*

	rep(i, 0, n) {

		RBnode<MIN, SUB> *A;

		A = T.insert(T.nil(), MIN(2147483647), 0);

		r = T.merge(A, r);

		//T.show(r);std::cout << "\n";T.check(r);

	}

	/*/

	std::queue<RBnode<MIN, SUB> *> Q;

	rep(i, 0, n) {

		Q.push(T.insert(r, MIN(2147483647), 0));

	}

	while (Q.size() != 1) {

		RBnode<MIN, SUB> *A, *B;

		A = Q.front();Q.pop();

		B = Q.front();Q.pop();

		Q.push(T.merge(A, B));

	}

	r = Q.front();Q.pop();

	//*/

	//T.show(r);std::cout << "\n";T.check(r);

	rep(i, 0, q) {

		std::cin >> c >> s >> t;

		if (c == 0) {

			std::cin >> x.e;

			T.update(r, s, t + 1, x);

			//T.show(r);std::cout << "\n";T.check(r);

		}

		else {

			std::cout << T.range(r, s, t + 1).e << "\n";

		}

	}

	return 0;

}
