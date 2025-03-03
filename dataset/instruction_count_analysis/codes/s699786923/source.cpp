#include <iostream>

#include <vector>



using namespace std;



typedef vector<int> V;



bool binary_search(V v, int t) {

    int left = 0;

    int right = v.size();

    while (left < right) {

        int mid = (left + right) / 2;

        if (v[mid] == t) {

            return true;

        } else if (v[mid] > t) {

            right = mid;

        } else {

            left = mid + 1;

        }

    }

    return false;

}



int main() {

    int n;

    cin >> n;

    V s = V(n);

    for (int i = 0; i < n; i++) {

        cin >> s[i];

    }

    int q;

    cin >> q;

    int c = 0;

    for (int i = 0; i < q; i++) {

        int t;

        cin >> t;

        if (binary_search(s, t)) {

            c++;

        }

    }



    cout << c << "\n";

}


