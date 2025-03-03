#include <iostream>

#include <algorithm>



using namespace std;



int main(void) {

    int n, k, x, y;

    cin >> n >> k >> x >> y;



    cout << min(k, n)*x + max(0, n-k)*y << endl;

    return 0;

}
