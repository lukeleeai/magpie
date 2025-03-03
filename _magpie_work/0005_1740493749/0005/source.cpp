#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<1000000> judge;
    judge.set();
    judge[0] = judge[1] = 0;
    int n, sum;

    while (cin >> n) {
        if (n == 0 || n == 1) {
            sum = 0;
        } else {
            sum = 1;
            for (int i = 3; i * i <= n; i += 2) {
                if (judge[i]) {
                    for (int j = i * i; j <= n; j += i)
                        judge[j] = 0;
                }
            }
            for (int i = 3; i <= n; i += 2) {
                if (judge[i]) {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
