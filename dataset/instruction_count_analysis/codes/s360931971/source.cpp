#include <stdio.h>

#include <vector>

#include <algorithm>

#include <map>



using namespace std;



struct node {

    node *l = nullptr;

    node *r = nullptr;

    node *p = nullptr;

    long long val = 0;

    long long sum = 0;

    node() {}

};



void fix(node *x) {

    x->sum = x->val;

    if (x->l) x->sum += x->l->sum;

    if (x->r) x->sum += x->r->sum;

}



void rot(node *x) {

    node *y = x->p, *z = y->p;

    if (z) {

        if (y == z->l) z->l = x;

        if (y == z->r) z->r = x;

    }

    x->p = z; y->p = x;

    if (x == y->l) {

        y->l = x->r; x->r = y;

        if (y->l) y->l->p = y;

    } else {

        y->r = x->l; x->l = y;

        if (y->r) y->r->p = y;

    }

    fix(y);

}



node *splay(node *x) { while (x->p) { node *y = x->p, *z = y->p;

        if (z) rot((x == y->l) == (y == z->l) ? y : x);

        rot(x);

    }

    fix(x);

    return x;

}



void join(node *x, node *y) {

    if (!x || !y) return;

    splay(x);

    while (x->r) x = x->r;

    splay(x);

    splay(y);

    x->r = y;

    y->p = x;

}



node *split_left(node *x) {

    splay(x);

    node *y = x->l;

    if (y) y->p = x->l = nullptr;

    return y;

}



node *split_right(node *x) {

    splay(x);

    node *y = x->r;

    if (y) y->p = x->r = nullptr;

    return y;

}



void rotate(node *x) {

    join(x, split_left(x));

}





pair<node *, node *> link(node *u, node *v) {

    node *uv = new node();

    node *vu = new node();

    rotate(u);

    rotate(v);

    join(u, uv);

    join(uv, v);

    join(v, vu);

    return { uv, vu };

}



void cut(pair<node *, node *> e) {

    rotate(e.first);

    split_right(e.first);

    split_left(e.second);

    split_right(e.second);

    delete e.first;

    delete e.second;

}



int par[100000];



int find(int x) {

    if (par[x] == x) return x;

    return par[x] = find(par[x]);

}



void unite(int x, int y) {

    par[find(x)] = find(y);

}





int N, M;

int X[100000];

int A[100000], B[100000], Y[100000], P[100000];

node *V[100000];

pair<node *, node *> E[100000];

int used[100000];



int main() {

    for (int i = 0; i < 100000; i++) {

        par[i] = i;

    }

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {

        scanf("%d", &X[i]);

        V[i] = new node();

        V[i]->val = X[i];

        V[i]->sum = X[i];

    }

    for (int i = 0; i < M; i++) {

        scanf("%d %d %d", &A[i], &B[i], &Y[i]);

        A[i]--;

        B[i]--;

        P[i] = i;

    }

    sort(P, P + M, [&](int i, int j) { return Y[i] < Y[j]; });

    for (int i = 0; i < M; i++) {

        int j = P[i];

        if (find(A[j]) != find(B[j])) {

            unite(A[j], B[j]);

            used[j] = 1;

            E[j] = link(V[A[j]], V[B[j]]);

        }

    }

    int ans = 0;

    for (int i = M - 1; i >= 0; i--) {

        int j = P[i];

        splay(V[A[j]]);

        if (used[j]) {

            if (V[A[j]]->sum < Y[j]) {

                ans++;

                cut(E[j]);

            }

        } else {

            if (V[A[j]]->sum < Y[j]) {

                ans++;

            }

        }

    }

    printf("%d\n", ans);

    return 0;

}


