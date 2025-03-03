#define taskname ""

#include "stdc++.h"



using namespace std;



const int maxN = 1e5;



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << min(a, b) + min(c, d);

    return 0;

}
