#include <algorithm>

#include <iostream>

#include <vector>



using namespace std;



typedef long long ll;



template<class T>

inline bool chmax(T &a, T b) {

    if(a < b) {

        a = b;

        return true;

    }

    return false;

}



template<class T>

inline bool chmin(T &a, T b) {

    if(a > b) {

        a = b;

        return true;

    }

    return false;

}



vector<bool> dp;



int main(void) {

    int X;

    cin >> X;



    dp.resize(X + 110, false);

    dp[0] = true;



    for (int i = 0; i < X; i++) {

        if (dp[i]) {

            dp[i + 100] = true;

            dp[i + 101] = true;

            dp[i + 102] = true;

            dp[i + 103] = true;

            dp[i + 104] = true;

            dp[i + 105] = true;

        }

    }



    if (dp[X]) {

        cout << "1" << endl;

    } else {

        cout << "0" << endl;

    }



    return 0;

}
