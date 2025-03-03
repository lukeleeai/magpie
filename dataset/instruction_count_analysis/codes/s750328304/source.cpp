#include "stdc++.h"

using namespace std;



int main() {

    int N;

    cin >> N;

    vector<int> D(N + 1);

    for (int i = 0; i < N; ++i)

        cin >> D[i];

    sort(D.begin(), D.end());



    for (int i = 0; i < D.size(); ++i)

        if (i & 1)

            D[i] = 24 - D[i];



    int ans = 13;

    for (int i = 0; i < D.size(); ++i) {

        for (int j = i + 1; j < D.size(); ++j) {

            int stmp = abs(D[i] - D[j]);

            ans = min(ans, min(stmp, 24 - stmp));

        }

    }



    cout << ans << endl;



    return 0;

}
