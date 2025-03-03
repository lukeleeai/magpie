#include <cstdlib>

#include <cassert>

#include <utility>

#include <tuple>

#include <ctime>

#include <cstdio>

#include <vector>

#include <algorithm>

#define loop(i,a,b) for(int i=(a);i<int(b);i++)

#define rep(i,n) loop(i,0,n)



using namespace std;



int const inf = 1e9;

#define np nullptr



struct Node {

    int val;

    Node * ch[2];

    int pri, cnt, sum;

    int min;

    Node(int v, int p) : val(v), pri(p), cnt(1), sum(v), min(v) {

        ch[0] = ch[1] = np;

    }

    ~Node(){

        if(ch[0]) delete ch[0];

        if(ch[1]) delete ch[1];

    }

};



int count(Node * t){

    return t == np ? 0 : t->cnt;

}

int sum(Node * t){

    return t == np ? 0 : t->sum;

}

int min(Node * t){

    return t == np ? inf : t->min;

}



void show(Node * n, int ofs=0){

    if(n==nullptr) return;

    show(n->ch[0],ofs+1);

    rep(i,ofs*2) putchar(' ');

    printf("v:%d m:%d (%p)\n",n->val,n->min,n);

    show(n->ch[1],ofs+1);

}



void update(Node * t){

    t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;

    t->sum = sum(t->ch[0]) + sum(t->ch[1]) + t->val;

    t->min = min({ min(t->ch[0]), min(t->ch[1]), t->val });

}



Node * merge(Node * l, Node * r){

    if(l == np || r == np) return l == np ? r : l;

    if(l->pri > r->pri){

        l->ch[1] = merge(l->ch[1],r);

        update(l);

        return l;

    } else {

        r->ch[0] = merge(l,r->ch[0]);

        update(r);

        return r;

    }

}



pair<Node*,Node*> split(Node * t, int k){

    if(t == np) return make_pair(np,np);

    if(k <= count(t->ch[0])){

        auto s = split(t->ch[0],k);

        t->ch[0] = s.second;

        update(t);

        return make_pair(s.first, t);

    } else {

        k -= count(t->ch[0]) + 1;

        auto s = split(t->ch[1],k);

        t->ch[1] = s.first;

        update(t);

        return make_pair(t,s.second);

    }

}



Node * erase(Node * t, int k){

    Node *l,*m,*r;

    tie(l,m) = split(t,k);

    tie(m,r) = split(m,1);

    delete m;

    return merge(l,r);

}



Node * at(Node * t, int k){

    int lc = count(t->ch[0]);

    if(k < lc) return at(t->ch[0],k);

    else if(k == lc) return t;

    else return at(t->ch[1], k-lc-1);

}



Node * insert(Node * t, int k, int v){

    Node *l,*m = new Node(v,rand()), *r;

    tie(l,r) = split(t,k);

    return merge(merge(l,m),r);

}



int min(Node * t, int l, int r){

    if(r - l <= 0) return inf;

    if(r - l == count(t)) return min(t);

    int s = count(t->ch[0]);

    if(l == s && r - s == 1) return t->val;

    int res = inf;

    if(l < s) res = min(res, min(t->ch[0], l, min(s,r)));

    if(l <= s && s < r) res = min(res, min(t, s, s+1));

    if(s+1 < r) res = min(res, min(t->ch[1], max(0,l-s-1), r-s-1));

    return res;

}



int get(){

    int x;

    scanf("%d",&x);

    return x;

}

void put(int x){

    //printf("ans : %d\n",x);

    printf("%d\n",x);

}



int main(){

#ifdef DEBUG

    freopen("in","r",stdin);

#endif

    srand(time(0));

    int n = get(), q = get();

    Node * root = np;

    rep(i,n) root = insert(root,i,get());



    rep(i,q){

        int op = get();

        if(false){

        } else if(op == 0){

            int l = get(), r = get();

            int x = at(root,r)->val;

            root = erase(root,r);

            root = insert(root,l,x);

        } else if(op == 1){

            int l = get(), r = get();

            r++;

            put(min(root,l,r));

        } else if(op == 2){

            int p = get(), v = get();

            root = erase(root,p);

            root = insert(root,p,v);

        }

    }

    delete root;

}