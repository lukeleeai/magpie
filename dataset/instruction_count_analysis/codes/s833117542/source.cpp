#include<iostream>

#include<algorithm>

#include<math.h>

#include<vector>

#include<map>

#include<set>



#define rep(i, n) for (int i = 0; i < (n); ++i)

#define rrep(i, a, n) for (int i = a; i <= (n); ++i)



using namespace std;

using ll = long long;

using ull = unsigned long long;



int main() {

    int A; cin >> A;

    int B; cin >> B;

    int C; cin >> C;

    int X; cin >> X;

    int Y; cin >> Y;



    int min_price = 1 << 30;

    rrep(i, 0, max(X, Y)) {

        int price = 2 * C * i + max(0, A * (X - i)) + max(0, B * (Y - i));

        min_price = min(min_price, price);

    }



    cout << min_price << endl;

    return 0;

}
