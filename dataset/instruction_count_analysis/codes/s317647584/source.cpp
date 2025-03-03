#include <iostream>

using namespace std;

char p[105][105];

int main()

{

    int h, w;

    cin >> h >> w;

    for ( int i = 1; i <= h; i++ )

    {

        for ( int j = 1; j <= w; j++ )

        {

            cin >> p[i][j];

        }

        for ( int k = 1; k <= w; k++ )

        {

            cout << p[i][k];

        }

        cout << "\n";

        for ( int l = 1; l <= w; l++ )

        {

            cout << p[i][l];

        }

        cout << "\n";

    }

}