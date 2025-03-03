#include "stdc++.h"

using namespace std;



int main() {

    ios::sync_with_stdio(false);

    int N, W;

    cin >> N >> W;

    int w[N + 1], v[N + 1];

    map<int, vector<int> > dict;

    for (int i = 1; i <= N; i++) {

        cin >> w[i] >> v[i];

        dict[w[i]].push_back(v[i]);

    }

    for (int i = 0; i <= 3; i++) {

        vector<int>& v = dict[w[1] + i];

        sort(v.begin(), v.end(), greater<int>());                           // descending order

    }

    int max_value = 0;

    for (int a = 0; (size_t)a <= dict[w[1]].size(); a++) {                  // 'a': qty of w1

        if (a * w[1] > W)

            break;

        int value_a = 0;

        for (int i = 0; i < a; i++)

            value_a += dict[w[1]][i];

        for (int b = 0; (size_t)b <= dict[w[1] + 1].size(); b++) {          // 'b': qty of w1+1

            if (a * w[1] + b * (w[1] + 1) > W)

                break;

            int value_b = 0;

            for (int i = 0; i < b; i++)

                value_b += dict[w[1] + 1][i];

            for (int c = 0; (size_t)c <= dict[w[1] + 2].size(); c++) {      // 'c': qty of w1+2

                if (a * w[1] + b * (w[1] + 1) + c * (w[1] + 2) > W)

                    break;

                int value_c = 0;

                for (int i = 0; i < c; i++)

                    value_c += dict[w[1] + 2][i];

                for (int d = 0; (size_t)d <= dict[w[1] + 3].size(); d++) {  // 'd': qty of w1+3

                    if (a * w[1] + b * (w[1] + 1) + c * (w[1] + 2) + d * (w[1] + 3) > W)

                        break;

                    int value_d = 0;

                    for (int i = 0; i < d; i++)

                        value_d += dict[w[1] + 3][i];

                    max_value = max(max_value, value_a + value_b + value_c + value_d);

                }

            }

        }

    }

    cout << max_value << "\n";



    return 0;

}