#include <iostream>

#include <vector>

#include <algorithm>

#include <numeric>

#include <functional>

#include <queue>

#include <stack>

#include <bitset>

#include <set>

#include <chrono>

#include <string>

#include <assert.h>



using namespace std;



#define endl '\n'



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    int a, b, c;

    cin >> a >> b >> c;



    if (a == b && a != c)

        cout << "Yes" << endl;

    else if (a == c && a != b)

        cout << "Yes" << endl;

    else if (c == b && a != c)

        cout << "Yes" << endl;

    else

        cout << "No" << endl;



    return 0;

}