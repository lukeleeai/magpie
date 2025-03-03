#include "stdc++.h"

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n;

    cin >> n;

    vector<int> vec, sor;

    for (int i = 0; i < n; i++) {

        int a;

        cin >> a;

        vec.push_back(a);

        sor.push_back(a);

    }

    sort(sor.begin(), sor.end());

    bool g = true;

    for (int i = 0; i < n; i++)

        if (vec[i] != sor[i])

            g = false;

    if (g) return cout << "YES\n", 0;



    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            vector<int> v;

            for (auto a: vec) v.push_back(a);

            swap(v[i], v[j]);

            bool good = true;

            for (int k = 0; k < n; k++)

                if (v[k] != sor[k]) good = false;

            if (good) return cout << "YES", 0;

        }

    }

    cout << "NO";

    return 0;

}