#include "stdc++.h"

using namespace std;



int main() {

    int x, a, b;

    cin >> x >> a >> b;

    int diff_a = abs(x - a), diff_b = abs(x - b);

    if(diff_a < diff_b) cout << "A" << endl;

    else cout << "B" << endl;

    return 0;

}
