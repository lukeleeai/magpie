#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <algorithm>

#include <vector>



using namespace std;



class Node {

public:

	int location;

	int l, r;

	//Node() {}

};



class Point {

public:

	int id, x, y;

	Point() {}

	Point(int id, int x, int y) :id(id), x(x), y(y) {}

	bool operator<(const Point&p) const {

		return id < p.id;

	}



	void print() {

		printf("%d\n", id);

	}

};



static const int MAX = 500000;

static const int NIL = -1;



int N;

Point P[MAX];

Node T[MAX];

int np;

Point ans[MAX];

int NANS;



bool lessX(const Point &p1, const Point &p2) {

	return p1.x < p2.x;

}



bool lessY(const Point &p1, const Point &p2) {

	return p1.y < p2.y;

}



int makeKDTree(int l, int r, int depth) {

	if (l == r) {

		return NIL;

	}

	int mid = (l + r) / 2;

	int t = np++;

	if (depth % 2 == 0) {

		sort(P + l, P + r, lessX);

	}

	else {

		sort(P + l, P + r, lessY);

	}

	T[t].location = mid;

	T[t].l = makeKDTree(l, mid, depth + 1);

	T[t].r = makeKDTree(mid + 1, r, depth + 1);



	return t;

}



void find(int v, int sx, int tx, int sy, int ty, int depth) {

	int x = P[T[v].location].x;

	int y = P[T[v].location].y;



	if (sx <= x && x <= tx && sy <= y && y <= ty) {

		ans[NANS++] = P[T[v].location];

	}



	if (depth % 2 == 0) {

		if (T[v].l != NIL) {

			if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1);

		}

		if (T[v].r != NIL) {

			if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1);

		}

	}

	else {

		if (T[v].l != NIL) {

			if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1);

		}

		if (T[v].r != NIL) {

			if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1);

		}

	}

}



int main() {

	int x, y;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		scanf("%d %d", &x, &y);

		P[i] = Point(i, x, y);

		T[i].l = T[i].r = NIL;

	}



	np = 0;



	int root = makeKDTree(0, N, 0);



	int q;

	scanf("%d", &q);

	int sx, tx, sy, ty;

	for (int i = 0; i < q; i++) {

		scanf("%d %d %d %d", &sx, &tx, &sy, &ty);

		NANS = 0;

		find(root, sx, tx, sy, ty, 0);

		sort(ans, ans + NANS);

		for (int j = 0; j < NANS; j++) {

			ans[j].print();

		}

		printf("\n");

	}



	return 0;

}