#include <iostream>

#include <vector>



using namespace std;



typedef vector<int> V;



bool combination(V &a, int t, int i, int c) {

    if (c > t) {

        return false;

    }

    if (c == t) {

        return true;

    }

    if (a.size() == i) {

        return false;

    }

    return combination(a, t, i + 1, c + a[i])

           || combination(a, t, i + 1, c);

}



bool hasCombination(V &a, int t) {

    return combination(a, t, 0, 0);

}



int main() {

    int n, q;

    cin >> n;

    V a = V(n);

    for (int i = 0; i < n; i++) {

        cin >> a[i];

    }

    cin >> q;

    for (int i = 0; i < q; i++) {

        int m;

        cin >> m;

        if (hasCombination(a, m)) {

            cout << "yes" << "\n";

        } else {

            cout << "no" << "\n";

        }

    }

}
