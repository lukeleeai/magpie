#include "stdc++.h"

using namespace std;



int main(){

    int N;

    cin >> N;

    vector<int> A;

    static int num[2][200001];

    static vector<int> Apos[200001];

    for(int k=0; k<2; k++) for(int i=0; i<N; i++){

        int a;

        cin >> a;

        num[k][a]++;

        if(k == 0){

            Apos[a].push_back(i);

            A.push_back(a);

        }

    }

    vector<int> nums;

    for(int i=1; i<=N; i++) nums.push_back(i);

    // 前ほどBが多い

    sort(nums.begin(), nums.end(), [&](int i, int j){ return num[0][i]-num[1][i] < num[0][j]-num[1][j]; });



    int offset = 0, mx = 0;

    for(int i=1; i<=N; i++){

        mx = max(mx, num[0][i] + num[1][i]);

    }

    vector<int> V[2];

    for(int i : nums){

        int l0 = V[0].size(), l1 = V[1].size();

        int r0 = l0 + num[0][i], r1 = l1 + num[1][i];

        offset = max(offset, min(r0, r1) - max(l0, l1));

        for(int k=0; k<2; k++) for(int t=0; t<num[k][i]; t++) V[k].push_back(i);

    }



    // for(int k=0; k<2; k++) for(int i=0; i<N; i++) cerr << V[k][i] << " \n"[i==N-1];



    rotate(V[1].begin(), V[1].end()-offset, V[1].end());



    // for(int k=0; k<2; k++) for(int i=0; i<N; i++) cerr << V[k][i] << " \n"[i==N-1];



    vector<int> ans(N);

    for(int i=0; i<N; i++){

        int a = V[0][i];

        int pos = Apos[a].back();

        Apos[a].pop_back();

        ans[pos] = V[1][i];

        if(a == V[1][i]){

            cout << "No" << endl;

            // if(mx <= N){

            //     cerr << " ##### WA #####" << endl;

            //     exit(1);

            // }

            return 0;

        }

    }



    cout << "Yes" << endl;

    for(int a : ans) cout << a << " ";

    cout << endl;

    // for(int i=0; i<N; i++) if(A[i] == ans[i]){

    //     for(int i=0; i<N; i++) cerr << A[i] << " \n"[i==N-1];

    //     for(int i=0; i<N; i++) cerr << ans[i] << " \n"[i==N-1];

    //     cerr << "##### WA #####" << endl;

    //     exit(1);

    // }

    return 0;

}
