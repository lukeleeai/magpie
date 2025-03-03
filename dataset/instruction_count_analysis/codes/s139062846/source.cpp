#include"stdc++.h"

using namespace std;



main()

{

    unsigned long long int a, b, x, result;



    cin >> a >> b >> x;



    if (a%x != 0)

    {

        result = (b/x - a/x);

    }

    else

    {

        result = (b/x - a/x) + 1;

    }





    cout << result;

}