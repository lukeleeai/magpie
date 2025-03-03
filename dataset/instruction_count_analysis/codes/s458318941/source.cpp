// includes {{{

#include<iostream>

#include<iomanip>

#include<algorithm>

#include<vector>

#include<stack>

#include<queue>

#include<map>

#include<set>

#include<tuple>

#include<cmath>

#include<random>

#include<cassert>

// #include<deque>

// #include<multiset>

// #include<bitset>

// #include<cstring>

// #include"stdc++.h"

// }}}

using namespace std;

using ll = long long;



const int N = 2e5;

std::vector<std::vector<int>> g;

int n, m;

string s;



bool ok[N];



void check(int i) {

  if(!ok[i]) return;

  auto ng = g[i];

  ng.clear();

  int cntA = 0, cntB = 0;

  for(int j : g[i]) {

    if(ok[j]) {

      ng.push_back(j);

      if(s[j] == 'A') cntA++;

      else cntB++;

    }

  }

  g[i] = ng;

  if(!cntA || !cntB) {

    ok[i] = 0;

    for(int j : g[i]) {

      check(j);

    }

  }

}



int main() {

  std::ios::sync_with_stdio(false), std::cin.tie(0);

  cin >> n >> m;

  cin >> s;

  g.resize(n);

  for(int i = 0; i < m; i++) {

    int a, b; std::cin >> a >> b;

    a--; b--;

    g[a].emplace_back(b);

    g[b].emplace_back(a);

  }



  for(int i = 0; i < n; i++) ok[i] = 1;



  for(int i = 0; i < n; i++) {

    check(i);

  }



  bool ans = 0;

  for(int i = 0; i < n; i++) ans |= ok[i];



  cout << (ans ? "Yes" : "No") << endl;



  return 0;

}
