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



string S;

int N, M;

int U[100001], R[100001];

int A[100001], T[100001];

int find(int x) {

  if (U[x] == x) return x;

  return U[x] = find(U[x]);

}

void unite(int x, int y) {

  x = find(x), y = find(y);

  if (x == y) return;

  if (R[x] < R[y]) swap(x, y);

  U[y] = x;

  R[x] += R[y];

}



signed main() {

  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S >> M;

  N = S.length();

  rep(i, N) {

    A[i] = S[i]-(i>0?S[i-1]:'a');

    if (A[i] < 0) A[i] += 26;

  }

  rep(i, N+1) U[i] = i, R[i] = 1;

  rep(i, N+1) unite(i, N-i);

  rep(i, M) {

    int l, r;

    cin >> l >> r;

    l--;

    unite(l, r);

  }

  rep(i, N+1) T[find(i)] += A[i];

  rep(i, N+1) {

    if (i == find(0)) continue;

    if (T[i] % 26) {

      cout << "NO\n";

      return 0;

    }

  }

  cout << "YES\n";

  return 0;

}
