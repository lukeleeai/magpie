#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long int ll;

typedef pair<int, int> P;



int n;

vector<vector<int>> graph(101010, vector<int>(0));

vector<int> colors(101010);

map<P, int> edge_num;

int mc = 0;



void dfs(int a, int pa, int pc){

  int c = 1;

  for(int x : graph.at(a)){

    if(x == pa) continue;

    if(c == pc) c++;

    colors.at(edge_num[P(x, a)]) = c;

    dfs(x, a, c);

    c++;

  }

  mc = max(c - 1, mc);

}



int main(){

  cin >> n;

  rep(i, n - 1){

    int a, b;

    cin >> a >> b;

    graph.at(a).emplace_back(b);

    graph.at(b).emplace_back(a);

    edge_num[P(a, b)] = edge_num[P(b, a)] = i;

  }

  

  dfs(1, 0, 0);

  

  cout << mc << endl;

  rep(i, n - 1) cout << colors[i] << endl;

  

  return 0;

}