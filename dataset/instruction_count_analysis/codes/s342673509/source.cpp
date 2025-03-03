#include"stdc++.h"

using namespace std;



const int K = 18, N = 55;



vector<int> vv[1<<K];



long long C[N][N];



void pre() {

    for (int i=0; i<N; i++) C[i][0] = 1;

    for (int i=1; i<N; i++)

        for (int j=1; j<N; j++)

            C[i][j] = C[i-1][j-1] + C[i-1][j];



    for (int i=0; i<N; i++)

        for (int j=1; j<N; j++)

            C[i][j] += C[i][j-1];

}



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    pre();





    int n, k, S, T;

    cin>>n>>k>>S>>T;



    vector<int> v(n);

    for (int i=0; i<n; i++) cin>>v[i];

    sort(v.begin(), v.end());



    if ( (S&T) != S) {

        cout<<0<<endl;

        return 0;

    }



    for (int i=0; i<n; i++) {

        int x = v[i];



        if ((x&S) != S) continue;

        if ((x&T) != x) continue;



        for (int mask = 0; mask < (1<<K); mask++) {

            if ((mask&S) != S) continue;

            if ((mask&T) != mask) continue;

            int ans = x & (~mask);

            vv[mask].push_back(ans);

        }

    }



    long long ans = 0;

    for (int mask = 0; mask < (1<<K); mask++) {

        if ((mask&S) != S) continue;

        if ((mask&T) != mask) continue;

        sort(vv[mask].begin(), vv[mask].end());



        long long ww = 0;

        while (vv[mask].size()) {

            int last = vv[mask].back();

            int cnt = 0;

            while (vv[mask].size() && vv[mask].back() == last)  cnt++, vv[mask].pop_back();



            ww += C[cnt][k]-1;

        }



        int bc = __builtin_popcount(mask);

        if (bc%2)   ans += ww;

        else        ans -= ww;

    }

    cout<<abs(ans)<<endl;

}
