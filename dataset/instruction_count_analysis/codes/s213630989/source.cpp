#include <cstdio>

#include <iostream>

#include <algorithm>

#include <string>

#include <cstring>

#include <vector>

#include <queue>

#include <set>

#include <map>

#include <cmath>

#include <iomanip>

#include <cassert>

#include <bitset>

using namespace std;



typedef pair<int, int> P;

#define rep(i, n) for (int i=0; i<(n); i++)

#define all(c) (c).begin(), (c).end()

#define uniq(c) c.erase(unique(all(c)), (c).end())

#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())

#define _1 first

#define _2 second

#define pb push_back

#define INF 1145141919

#define MOD 1000000007

int U[100001];

set<int> R[100001];



int find(int x) {

  if (U[x] == x) return x;

  return U[x] = find(U[x]);

}



void unite(int x, int y) {

  x = find(x), y = find(y);

  if (x == y) return;

  if (R[x].size() < R[y].size()) swap(x, y);

  U[y] = x;

  for (int e : R[y]) R[x].insert(e);

  R[y].clear();

}



bool same(int x, int y) {

  return find(x) == find(y);

}

inline int mins(int v) {

  return (26-(v%26))%26;

}



int N, M;

string S;

int A[100001];

bool done[100001];

void add(int p, int v) {

  v = (26+v)%26;

  A[p] = (A[p]+v)%26;

}

bool go(int pos, int v) {

  v = (26+v)%26;

  if (R[find(pos)].empty()) return false;

  int a = A[pos];

  int left = *R[find(pos)].begin(), right = *R[find(pos)].rbegin();

  if (!done[left]) {

    add(left, a-v);

    add(pos, v-a);

    assert(A[pos] == v);

    return true;

  }

  if (!done[right]) {

    add(right, a-v);

    add(pos, v-a);

    assert(A[pos] == v);

    return true;

  }

  return false;

}



signed main() {

  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S >> M;

  N = S.length();

  rep(i, N+1) U[i] = i, R[i].insert(i);

  rep(i, M) {

    int l, r;

    cin >> l >> r;

    l--;

    unite(l, r);

  }

  rep(i, N) A[i] = S[i]-(i>0?S[i-1]:'a');

  rep(i, N) A[i] = ((A[i]%26)+26)%26;

  A[N] = 0;

  N++;

  for (int p=N/2-1; p>=0; p--) {

    int right = N-1-p;

    unite(p, right);

  }

  if (N % 2 == 1) {

    int pos = (N-1)/2;

    // pos -> 0

    done[pos] = true;

    if (A[pos] != 0) {

      if (!go(pos, 0)) {

        cout << "NO\n";

        return 0;

      }

    }

  }

  int hoge = N/2;

  for (int p=N/2-1; p>=1; p--) {

    int right = N-1-p;

    done[p] = done[right] = true;

    if (A[p] == mins(A[right])) continue;

    if (go(p, mins(A[right])) || go(right, mins(A[p]))) {

    }

    else {

      cout << "NO\n";

      return 0;

    }

  }

  cout << "YES\n";

  return 0;

}
