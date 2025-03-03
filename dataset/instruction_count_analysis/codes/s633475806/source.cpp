#include <iostream>

#include <vector>

#include <algorithm>

#define all(c) (c).begin(),(c).end()



#define maxv 100000



using namespace std;



int n,len;

vector<int> tree[maxv], in, out, up[100];



void dfs(int u, int p, int &k){

  in[u] = k++;

  up[0][u] = p;

  for(int i = 1; i < len; i++)

    up[i][u] = up[i - 1][up[i - 1][u]];



  for(int i = 0; i < tree[u].size(); i++){

    if(tree[u][i] != p)dfs(tree[u][i],u,k);

  }

  out[u] = k++;

}



void init(int root){

  len = 1;

  while((1 << len) <= n)len++;

  for(int i=0;i<len;i++){

    up[i].resize(n);

    fill(all(up[i]),0);

  }

  in.resize(n);

  out.resize(n);

  fill(all(in),0);

  fill(all(out),0);

  int k=0;

  dfs(root,root,k);

}



bool isParent(int parent, int child){

  return in[parent] <= in[child] && out[child] <= out[parent];

}



int lca(int a, int b){

  if(isParent(a,b))return a;

  if(isParent(b,a))return b;

  for(int i = len - 1; i >= 0; i--){

    if(!isParent(up[i][a],b))a = up[i][a];

  }

  return up[0][a];

}





int main(void){



  cin >> n;

  for(int i=0;i<n;i++){

    int k,c;

    cin >> k;

    for(int j=0;j<k;j++){

      cin >> c;

      tree[i].push_back(c);

    }

  }



  init(0);



  int q;

  cin >> q;

  while(q--){

    int u,v;

    cin >> u >> v;

    cout << lca(u,v) << endl;

  }

  return 0;

}