#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>

using namespace std;







int main() {

    int N;

    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; ++i) {

      int val;

      cin >> val;

      vec[i] = val;

    }



    int ans = 0;



    while (true) {

        bool odd = false;

        for (int i = 0; i < N; ++i) {

            if (vec[i] % 2 != 0) odd = true;

        }



        if (odd) break;



        for (int i = 0; i < N; ++i) {vec[i] /= 2;}

        ++ans;

    }

    cout << ans << "\n";

}
