#include "stdc++.h"

using namespace std;

int main(void){

    int N; cin >> N;

    vector<int> D(N);

    vector<int> Dcount(13);

    for (int i = 0; i < N; i++) {

        cin >> D[i];

        Dcount[D[i]]++;

    }

    

    for (int i = 0; i < 13; i++) {

        if (2 < Dcount[i] || Dcount[0]) {

            cout << 0 << endl;

            return 0;

        }

    }

    

    int ans = -1;    

    for (int i = 0; i < (1 << 12); i++) {

        vector<int> jikoku;

        int bits = i;

        int jisa_min = 13;

        for (int j = 0; j < 12; j++) {

            if (Dcount[j+1] == 0) continue;

            else if (Dcount[j+1] == 2) {

                jikoku.push_back(j+1);

                jikoku.push_back(24-j-1);

            } else if ((1 << j) & bits) {

                jikoku.push_back(j+1);

            } else {

                jikoku.push_back(24-j-1);

            }

        }

        for (int i = 0; i < jikoku.size(); i++) {

            jisa_min = min(min(jikoku[i], 24 - jikoku[i]), jisa_min);

        }

        for (int i = 0; i < jikoku.size(); i++) {

            for (int j = i+1; j < jikoku.size(); j++) {

                jisa_min = min(jisa_min, min(abs(jikoku[i] - jikoku[j]), abs(min(jikoku[i], jikoku[j]) + 24 - max(jikoku[i], jikoku[j]))));

            }

        }

        ans = max(jisa_min, ans);

    }

    cout << ans << endl;

}
