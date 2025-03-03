#include "stdc++.h"



using namespace std;



const int N = 200005;



struct Node {

  int val[2];

  Node() {

    val[0] = val[1] = INT_MAX;

  }

};



int a[N], m[N];



struct S {

  int l, r, val;

  bool operator < (const S &b) const {

    return val > b.val;

  }

};



int n;

Node seg[N << 2];



void add(int id, int l, int r, int loc, int data) {

  if (l == r) {

    seg[id].val[loc & 1] = data;

    seg[id].val[2] = data;

    return ;

  }

  int mid = (l + r) >> 1;

  if (loc <= mid) {

    add(id << 1, l, mid, loc, data);

  }

  else {

    add(id << 1 | 1, mid + 1, r, loc, data);

  }

  seg[id].val[0] = min(seg[id << 1].val[0], seg[id << 1 | 1].val[0]);

  seg[id].val[1] = min(seg[id << 1].val[1], seg[id << 1 | 1].val[1]);

}



int query(int id, int l, int r, int ll, int rr, int flag) {

  if (l == ll && r == rr) {

    return seg[id].val[flag];

  }

  int mid = (l + r) >> 1;

  if (mid >= rr) {

    return query(id << 1, l, mid, ll, rr, flag);

  }

  if (mid < ll) {

    return query(id << 1 | 1, mid + 1, r, ll, rr, flag);

  }

  return min(query(id << 1, l, mid, ll, mid, flag), query(id << 1 | 1, mid + 1, r, mid + 1, rr, flag));

}



int main() {

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {

    scanf("%d", &a[i]);

    m[a[i]] = i;

    add(1, 1, n, i, a[i]);

  }

  a[n + 1] = INT_MAX;

  priority_queue<S> q;

  q.push({1, n, query(1, 1, n, 1, n, 1)});

  vector<int> res;

  while (!q.empty()) {

    S s = q.top();

    q.pop();

    res.push_back(s.val);

    int now = m[s.val];

    int go = query(1, 1, n, now + 1, s.r, (now & 1) ^ 1);

    res.push_back(go);

    go = m[go];

    if (now > s.l) {

      q.push({s.l, now - 1, query(1, 1, n, s.l, now - 1, s.l & 1)});

    }

    if (now + 1 < go) {

      q.push({now + 1, go - 1, query(1, 1, n, now + 1, go - 1, (now + 1) & 1)});

    }

    if (go < s.r) {

      q.push({go + 1, s.r, query(1, 1, n, go + 1, s.r, (go + 1) & 1)});

    }

  }

  for (int i = 0; i < n ; ++i) {

    printf("%d%c", res[i], i < n - 1 ? ' ' : '\n');

  }

  return 0;

}
