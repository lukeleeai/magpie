#include <cstdio>

#include <iostream>

#include <vector>

#include <cassert>

#include <string>

using namespace std;



struct QuickFind {

    int N;

    vector<int> i2g;

    vector< vector<int> > g2i;

    vector<long long int> weight;



    QuickFind(int N_) {

        N = N_;

        i2g.resize(N);

        g2i.resize(N);

        weight.resize(N);



        for(int i=0; i<N; i++) {

            i2g[i] = i;

            g2i[i] = vector<int>{i};

        }

    }



    bool same(int u, int v) {

        return i2g[u] == i2g[v];

    }



    // v の方が w だけ大きい

    void unite(int u, int v, int w) {

        int ru = i2g[u], rv = i2g[v];

        if(ru == rv) return;



        if(g2i[rv].size() > g2i[ru].size()) {

            swap(ru, rv);

            swap(u, v);

            w = -w;

        }



        long long int prev = weight[v];

        weight[v] = weight[u] + w;



        for(auto e : g2i[rv]) {

            i2g[e] = ru;

            long long int diff = weight[e] - prev;

            if(e != v) weight[e] = weight[v] + diff;

        }



        for(auto e : g2i[rv]) {

            g2i[ru].push_back(e);

        }

        g2i[rv].clear();

    }



    long long int query(int u, int v) {

        assert(same(u, v));

        return weight[v] - weight[u];

    }

};



int N, Q;



int main() {

    while(cin >> N >> Q, N || Q) {

        QuickFind qf(N);

        for(int i=0; i<Q; i++) {

            char query; cin >> query;

            if(query == '!') {

                int u, v, w; cin >> u >> v >> w;

                u--; v--;

                qf.unite(u, v, w);

            }

            else {

                int u, v; cin >> u >> v;

                u--; v--;

                if(qf.same(u, v)) {

                    cout << qf.query(u, v) << endl;

                }

                else {

                    cout << "UNKNOWN" << endl;

                }

            }

        }

    }

    return 0;

}
