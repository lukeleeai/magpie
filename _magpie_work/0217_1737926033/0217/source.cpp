#include <iostream>
#include <array>
#include <numeric> // for std::accumulate
using namespace std;

int main() {
    int n, k;

    while (cin >> n >> k, n || k) {
        array<int, 100> S = {}; // Assuming k ≤ 100
        for (int i = 0; i < k; i++) {
            cin >> S[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int b;
                cin >> b;
                S[j] -= b;
            }
        }

        bool flag = accumulate(S.begin(), S.end(), true, [](bool acc, int x) { return acc && (x >= 0); });
        cout << (flag ? "Yes" : "No") << endl;
    }
}
