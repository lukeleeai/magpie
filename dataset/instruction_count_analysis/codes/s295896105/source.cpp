#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")



#include <algorithm>

#include <iostream>

#include <vector>



using namespace std;



typedef long long ll;



struct edge {

    int to, from;

};



const int MAX_N = 100000;



vector<edge> G[MAX_N + 1];



int N, M;



void tracePath(int s, int p, int& ans);



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    cin >> N >> M;



    for (int i = 0; i < M; i++) {

        int a, b;

        cin >> a >> b;

        edge et = { a, b };

        G[b].push_back(et);

        edge es = { b, a };

        G[a].push_back(es);

    }



    int ans = 0;



    tracePath(1, 0, ans);



    cout << ans << "\n";



    return 0;

}



void tracePath(int s, int p, int& ans)

{

    if (p == (1 << (N - 1)) - 1) {

        ans++;

        return;

    }

    vector<edge> v = G[s];

    for (int i = 0; i < v.size(); i++) {

        edge e = v[i];

        if (e.to != 1 && !(p & (1 << (e.to - 2)))) {

            int np = p | (1 << (e.to - 2));

            tracePath(e.to, np, ans);

        }

    }

    return;

}