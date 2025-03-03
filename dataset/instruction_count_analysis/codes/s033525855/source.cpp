#include "stdc++.h"

using namespace std;



int main() {

    int N;

    cin >> N;

    vector<int> vec(N);

    for (auto& i : vec) cin >> i;



    double l = 0., r = 1.0;

    for (int c = 0; c < 100; c++) {

        double m = (l + r) / 2.0;

        set<int> s;

        s.insert(1);



        for (int i = 0; i < N; i++) {

            int lo_n = ceil((1.0 - m) * (double)vec[i]);

            int up_n = (1.0 + m) * vec[i];



            set<int> ns;

            for (auto j : s) {

                int v = up_n / j;

                int u = ceil((double)lo_n / j);

                for (; u <= v; u++) if (u != 0) ns.insert(j * u);

            }



            s = ns;

        }



        if (s.size() > 0) r = m;

        else l = m;

    }



    printf("%.10f\n", l);



    return 0;

}