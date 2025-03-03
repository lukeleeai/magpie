#include "stdc++.h"

using namespace std;



int main()

{

    long long a, b;

    cin >> a >> b;



    if((b % a))

    {

        cout << abs(a - b) << endl;

    }

    else

    {

        cout << a + b << endl;

    }

    return 0;

}
