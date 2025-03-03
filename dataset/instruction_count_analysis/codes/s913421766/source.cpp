#include <iostream>

#include <algorithm>

#include <vector>

#include <deque>

#include <queue>

#include <list>

#include <stack>

#include <string>

#include <tuple>

#include <functional>

#include <numeric>

#include <cmath>

#include <iomanip>

#include <map>

#include <random>

#include <cstdlib>

#define INT_MAX 2147483647

#define INT_MIN -2147483646

#define Loop(i, n) for(int i = 0; i < (int)n; i++)

#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)

#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)

#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)

using namespace std;

typedef long long int ll;

typedef vector<int> vi;

typedef vector<vector<int>> vvi;



struct vertex {

	int id;

	int x;

	int y;

};



bool xComp(const vertex& s1, const vertex& s2) {

	return s1.x != s2.x ? s1.x < s2.x : s1.y < s2.y;

}

bool yComp(const vertex& s1, const vertex& s2) {

	return s1.y != s2.y ? s1.y < s2.y : s1.x < s2.x;

}



struct node {

	int innum;

	node* left;

	node* right;

};



vector<vertex> V(500005);

node* NIL = (node*)malloc(sizeof(node));

node* root;



void makeT(int a, int b, node** focus, int turn) {

	if (a >= b) return;

	if (turn % 2 == 0) sort(V.begin() + a, V.begin() + b, xComp);

	else sort(V.begin() + a, V.begin() + b, yComp);

	int mid = (a + b) / 2;

	node* buf = (node*)malloc(sizeof(node));

	buf->innum = mid;

	buf->left = NIL;

	buf->right = NIL;

	*focus = buf;

	makeT(a, mid, &((*focus)->left), turn + 1);

	makeT(mid + 1, b, &((*focus)->right), turn + 1);

}



vi ret;



void findT(int sx, int tx, int sy, int ty, node* focus, bool t) {

	if (focus == NIL) return;

	int xx = V[focus->innum].x, yy = V[focus->innum].y;

	if (sx <= xx && xx <= tx && sy <= yy && yy <= ty){

		ret.push_back(V[focus->innum].id);

	}

	if (t == 0) {

		if (sx <= xx) findT(sx, tx, sy, ty, focus->left, 1);

		if (xx <= tx) findT(sx, tx, sy, ty, focus->right, 1);

	}

	else {

		if (sy <= yy) findT(sx, tx, sy, ty, focus->left, 0);

		if (yy <= ty) findT(sx, tx, sy, ty, focus->right, 0);

	}

}



int main() {

	root = NIL;

	int n;

	scanf("%d", &n);

	Loop(i, n) {

		int x, y;

		scanf("%d %d", &x, &y);

		V[i] = { i, x, y };

	}

	makeT(0, n, &root, 0);

	int q;

	scanf("%d", &q);

	Loop(i, q) {

		int sx, tx, sy, ty;

		scanf("%d %d %d %d", &sx, &tx, &sy, &ty);

		ret.clear();

		findT(sx, tx, sy, ty, root, 0);

		sort(ret.begin(), ret.end());

		Loop(j, ret.size()) printf("%d\n", ret[j]);

		printf("\n");

	}

	return 0;

}