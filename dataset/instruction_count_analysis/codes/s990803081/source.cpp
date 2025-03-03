#include<iostream>

using namespace std;

int main()

{

    int w, h, n, a, b, c, d;

    cin>>w>>h>>n;

    a =0, b = w, c =0, d = h;

    while( n--)

    {

        int x, y, m;

        cin>>x>>y>>m;

        if( m ==1) a = max( a, x );

        if( m ==2) b = min( b, x );

        if( m ==3) c = max( c, y );

        if( m ==4) d = min( d, y );

    }

    w =(b-a<0?0:b-a);

    h =(d-c<0?0:d-c);

    cout<<w*h<<endl;

    return 0;

}