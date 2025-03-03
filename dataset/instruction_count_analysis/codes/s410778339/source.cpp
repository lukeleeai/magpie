#include<iostream>

using namespace std;



int main()

{

   int sx, sy, tx, ty;

    cin >> sx >> sy >> tx >> ty;

    int i;

    for (i=sy+1 ; i<=ty ; i++)

    {

        cout << "U";

    }

    for (i=sx+1 ; i<=tx ; i++)

    {

        cout << "R";

    }

    for (i=ty-1 ; i>=sy ; i--)

    {

        cout << "D";

    }

    for (i=tx-1 ; i>=sx ; i--)

    {

        cout << "L";

    }

    cout << "L";

    for (i=sy ; i<=ty ; i++)

    {

        cout << "U";

    }

    for (i=sx ; i<=tx ; i++)

    {

        cout << "R";

    }

    cout << "DR";

      

    for (i=ty ; i>=sy ; i--)

    {

        cout << "D";

    }

    for (i=tx ; i>=sx ; i--)

    {

        cout << "L";

    }

    cout << "U" ;

    return 0;

}