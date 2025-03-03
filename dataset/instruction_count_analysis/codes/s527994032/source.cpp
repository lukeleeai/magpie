#include "stdc++.h"

using namespace std;



int N, M, X[100000], A[100000], B[100000], Y[100000];



struct UnionFind {

    vector<int> par;

    vector<int> sz;

    vector<int64_t> wt;

    vector<int> es;



    UnionFind(int n=0){

        if(n>0) initialize(n);

    }



    void initialize(int n){

        par.resize(n);

        sz.resize(n);

        wt.resize(n);

        es.resize(n);

        for(int i=0; i<n; i++){

            par[i] = i;

            sz[i] = 1;

            wt[i] = X[i];

            es[i] = 0;

        }

    }



    int find(int x){

        if(par[x] == x){

            return x;

        }else{

            return par[x] = find(par[x]);

        }

    }



    void unite(int x, int y){

        x = find(x);

        y = find(y);

        if(x == y) return;

        if(sz[x] < sz[y]){

            par[x] = y;

            sz[y] += sz[x];

            wt[y] += wt[x];

            es[y] += es[x];

        }else{

            par[y] = x;

            sz[x] += sz[y];

            wt[x] += wt[y];

            es[x] += es[y];

        }

    }



    bool same(int x, int y){

        return find(x) == find(y);

    }



    int64_t weight(int x){

        return wt[find(x)];

    }



    void add_edge(int x){

        x = find(x);

        es[x]++;

    }



    int result_edge(int x){

        x = find(x);

        int ret = es[x];

        es[x] = 0;

        return ret;

    }

};



int main(){

    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> X[i];

    for(int i=0; i<M; i++){

        cin >> A[i] >> B[i] >> Y[i];

        A[i]--; B[i]--;

    }



    vector<int> order;

    for(int i=0; i<M; i++) order.push_back(i);

    sort(order.begin(), order.end(), [&](int a, int b){ return Y[a] < Y[b];});



    int use = 0;

    UnionFind uf(N);

    for(int i : order){

        uf.unite(A[i], B[i]);

        int64_t weight = uf.weight(A[i]);

        uf.add_edge(A[i]);



        if(weight >= Y[i]){

            use += uf.result_edge(A[i]);

        }

    }



    int ans = M - use;

    cout << ans << endl;

    return 0;

}