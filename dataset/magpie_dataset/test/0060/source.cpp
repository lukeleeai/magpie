#include"stdc++.h"

using namespace std;

#define ll long long

#define ld long double





int main()

{

    ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

    ll cord,koita;

    cin >> koita >> cord; /// 3 7

    ll start = cord - koita + 1; /// 5

    for (int i=start; i<cord; i++){

        cout << i << " "; /// 5 6

    }

    cout << cord << " "; // 7

    ll en = cord + koita - 1; /// 9

    for (int i= cord + 1; i<=en; i++){

        cout << i << " ";

    }

    return 0;

}
