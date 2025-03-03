#include "stdc++.h"

using namespace std;

using Int = long long int;

template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}





vector<Int> m[300002];

Int stts[300002];

Int arr[300002];



void dfs(Int u, Int val) {

    stts[u] = 1;

    arr[u] += val;

    for(Int i=0; i<m[u].size(); i++){

        if(stts[m[u][i]] == 0){

            dfs(m[u][i], arr[u]);

        }

    }

}



int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);



    Int n, q, a, b;

    cin >> n >> q;

    Int p, x;



    // init

    for(Int i=0; i<n; i++){

        arr[i] = 0;

        stts[i] = 0;

    }



    for(Int i=0; i<n-1; i++){

        cin >> a >> b;

        m[a-1].push_back(b-1);

        m[b-1].push_back(a-1);

    }

    for(Int i=0; i<q; i++){

        cin >> p >> x;

        arr[p-1] += x;

    }

    dfs(0, 0);

    for(Int i=0; i<n; i++){

        cout << arr[i] << " ";

    }

    cout << endl;



    return 0;

}