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

    rrep(i, 0, 100000) {

        int price = 2 * C * i; // ABピザは2枚で2C円の1セットと考える

        int a = X - i; // A ピザの枚数

        int b = Y - i; // A ピザの枚数

        if (a > 0) price += A * a; // A ピザが足りなければ買い足す

        if (b > 0) price += B * b; // B ピザが足りなければ買い足す

        min_price = min(min_price, price);

    }



    cout << min_price << endl;

    return 0;

}
