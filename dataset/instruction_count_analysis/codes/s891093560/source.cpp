#include <iostream>

using namespace std;



/*

union_find class:

  int n;

  int *par, *rank;



  method: 

    union_find(int n);

    int find(int x);

    void unite(int x, int y);

    bool same(int x, int y);

    void print();

*/





class union_find{

public:

  int n;

  int *par, *rank;



  union_find(int n){

    this-> n = n;

    par = new int[n];

    rank = new int[n];

    init();

  }

  

  int find(int x){

    if(par[x] == x) return x;

    return par[x] = find(par[x]);

  }



  void unite(int x, int y){

    x = find(x);

    y = find(y);



    if(x == y) return;



    if(rank[x] < rank[y]){

      par[x] = y;

    }else{

      par[y] = x;

      if(rank[x] == rank[y]) rank[x]++;

    }

  }



  bool same(int x, int y){

    return find(x) == find(y);

  }



  int solve(){

    for(int i=0; i<n; i++){



    }

  }



  void print(){

    cout << "---------------" << endl;

    for(int i=0; i<n; i++){

      cout << "par " << i << " : " << par[i] << endl;

    }

    cout << "---------------" << endl;

  }



private:

  void init(){

    for(int i=0; i<n; i++){

      par[i] = i;

      rank[i] = 1;

    }

  }

};



int main(){

  int n, m; cin >> n >> m;

  union_find uf(n);

  int v[n];

  for(int i=0; i<n; i++) cin >> v[i];



  for(int i=0; i<m; i++){

    int x, y;

    cin >> x >> y;

    uf.unite(x-1, y-1);

  }  



  int cnt = 0;

  for(int i=0; i<n; i++){

    if(uf.same(i, v[i]-1)) cnt++;

  }



  cout << cnt << endl;

  /* uf.print(); */

  

  return 0; 

}
