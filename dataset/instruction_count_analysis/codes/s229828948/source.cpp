#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int main()

{

    vector<int> haiku;

    int a, b, c;

    cin >> a >> b >> c;

    haiku.push_back(a);

    haiku.push_back(b);

    haiku.push_back(c);

    sort (haiku.begin(), haiku.end());



    if (haiku[0] == 5 && haiku[1] == 5 && haiku[2] == 7) {

        cout << "YES" << endl;

    } else {

        cout << "NO" << endl;

    }



    return 0;

}
