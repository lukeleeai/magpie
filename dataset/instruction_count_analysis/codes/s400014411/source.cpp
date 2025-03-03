#include"stdc++.h"

using namespace std;



const int K = 18, N = 55;

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



bool between(int sub, int super, int x) {

    return (sub&x) == sub && (super&x) == x;

}



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    pre();



    int n, k, S, T;

    cin>>n>>k>>S>>T;



    vector<int> v(n);

    for (int i=0; i<n; i++) cin>>v[i];



    long long ans = 0;

    for (int mask = 0; mask < (1<<K); mask++) {

        if (!between(S, T, mask))  continue;



        vector<int> vv;

        for (int i=0; i<n; i++)

            if (between(S, T, v[i]))

                vv.push_back(v[i] & (~mask));



        sort(vv.begin(), vv.end());



        long long ww = 0;

        while (vv.size()) {

            int last = vv.back();

            int cnt = 0;

            while (vv.size() && vv.back() == last)  cnt++, vv.pop_back();

            ww += C[cnt][k]-1;

        }



        int bc = __builtin_popcount(mask);

        if (bc%2)   ans += ww;

        else        ans -= ww;

    }

    cout<<abs(ans)<<endl;

}
