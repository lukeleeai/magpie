//include

//------------------------------------------

#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cctype>

#include <string>

#include <cstring>

#include <ctime>

#include <climits>

#include <queue>



using namespace std;



//typedef

//------------------------------------------

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef long long LL;



//container util

//------------------------------------------

#define ALL(a)  (a).begin(),(a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define PB push_back

#define MP make_pair

#define SZ(a) int((a).size())

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())



//repetition

//------------------------------------------

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)  FOR(i,0,n)



//constant

//--------------------------------------------

const double EPS = 1e-10;

const double PI  = acos(-1.0);



int N, Q;

int par[100001];

VI chd[100001];

VI node(100001, 1);

VI mkd(100001, 0);



class UnionFind{

private:

  vector<int> par, rank;

public:

  UnionFind(int n){

	par.assign(n, 0);

	rank.assign(n, 0);

	for(int i=0;i<n;++i)

	  par[i] = i;

  }



  //find root of x

  int find(int x){

	if(par[x] == x)

	  return x;

	return (par[x] = find(par[x]));

  }



  void unite(int x, int y){

	x = find(x);

	y = find(y);

	if(x == y) return;



	if(rank[x] < rank[y])

	  par[x] = y;

	else{

	  par[y] = x;

	  if(rank[x] == rank[y])

		++rank[x];

	}

  }



  bool same(int x, int y){

	return find(x) == find(y);

  }

};



void init(int i, int p, UnionFind& uf){

  if(mkd[i]){

	for(int c: chd[i]){

	  init(c, i, uf);

	}

  }

  else{

	node[i] = node[p];

	uf.unite(p, i);

	for(int c: chd[i]){

	  init(c, p, uf);

	}

  }

}



int main(){

  cin.tie(0);

  ios_base::sync_with_stdio(false);



  while(cin >> N >> Q, N){

	REP(i,100001) chd[i].clear();

	UnionFind uf(N+1);

	REP(i,N-1){

	  cin >> par[i+2];

	  chd[par[i+2]].PB(i+2);

	}	

	

	vector<PII> q;

	for(int i=1;i<=N;++i)

	  node[i] = i;

	fill(ALL(mkd), false);

	mkd[1] = true;

	REP(i,Q){

	  char ch; int x;

	  cin >> ch >> x;

	  if(ch == 'M')

		q.PB(MP(0,x)), mkd[x]++;

	  else

		q.PB(MP(1,x));

	}



	init(1, 1, uf);

	

	LL ans = 0;

	for(int i=Q-1;i>=0;--i){

	  if(q[i].first == 0){

		int idx = q[i].second;

		--mkd[idx];

		if(!mkd[idx]){

		  node[uf.find(idx)] = node[uf.find(par[idx])];

		  uf.unite(idx, par[idx]);

		}

	  }

	  else{

		ans += node[uf.find(q[i].second)];

	  }

	}

	cout << ans << endl;

  }

  

  return 0;

}