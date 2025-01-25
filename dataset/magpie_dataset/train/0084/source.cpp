#include <iostream>



#define C 300000

using namespace std;



int main() {

    int n, q;

    int c[300000], query[100000];

    bool has_c[C+1];

    cin >> n >> q;

    for (int i=0; i<n; i++) {

        cin >> c[i];

    }

    for (int i=0; i<q; i++) {

        cin >> query[i];

    }

    for (int i=0; i<=C; i++) {

        has_c[i] = false;

    }

    for (int i=0; i<n; i++) {

        has_c[c[i]] = true;

    }

    for (int i=0; i<q; i++) {

        int max_r = -1;

        for (int r=query[i]-1; r>=0; r--) {

            for (int k=0; true; k++) {

                int x = k*query[i]+r;

                if (x > C) {

                    break;

                }

                if (has_c[x]) {

                    max_r = max(r, max_r);

                    break;

                }

            }

            if (max_r >= 0) {

                break;

            }

        }

        cout << max_r << endl;

    }

    return 0;

}