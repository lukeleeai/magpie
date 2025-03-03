//code by lynmisakura.wish to be accepted!

#include"stdc++.h"

using namespace std;



typedef long long ll;



class UnionFind {

    static const int MAX_N = 200020;

public:

    //UnionFind

    int par[MAX_N];

    int ufrank[MAX_N];

    int ufsize[MAX_N];

    UnionFind(int ufsize_of_tree) {

        for (int i = 0; i < ufsize_of_tree; i++)

        {

            par[i] = i;

            ufrank[i] = 0;

            ufsize[i] = 1;

        }

    }

    int find(int x) {

        if (par[x] == x) return x;

        else return par[x] = find(par[x]);

    }

    void unite(int x, int y) {

        x = find(x);

        y = find(y);

        if (x == y) return;

        if (ufrank[x] < ufrank[y]) {

            par[x] = y;

            int sx = ufsize[x], sy = ufsize[y];

            ufsize[x] = ufsize[y] = sx + sy;

        }

        else {

            par[y] = x;

            if (ufrank[x] == ufrank[y]) ufrank[x]++;

            int sx = ufsize[x], sy = ufsize[y];

            ufsize[x] = ufsize[y] = sx + sy;

        }

    }

    bool same(int x, int y) {

        return find(x) == find(y);

    }

}; 



int main(void){

	int N,M;scanf("%d %d",&N,&M);

	UnionFind UF(N);

	int ans = N;

	for (int i = 0; i < M; ++i)

	{

		int x,y,z;scanf("%d %d %d",&x,&y,&z);

		if(!UF.same(x,y)){

			UF.unite(x,y);ans--;

		}

	}



	printf("%d\n", ans);

}
