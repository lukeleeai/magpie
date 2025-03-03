#include <iostream>

using namespace std;

int a[200005], price[200005];

int main()

{

    int n, tot = 0;

    cin >> n;

    for ( int i = 1; i <= n; i++ )

    {

        cin >> a[i];

    }

    for ( int i = 0; i <= n; i++ )

    {

        tot = tot + abs( a[i+1] - a[i] );

    }

    for ( int i = 1; i <= n; i++ )

    {

        price[i] = tot - abs( a[i] - a[i-1] ) - abs( a[i] - a[i+1] ) + abs( a[i+1] - a[i-1] );

        cout << price[i] << endl;

    }

}