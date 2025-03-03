// sol1

#include<stdio.h>



int a[1001][1001];

int w, h, x, y, t, n;



void f(int x, int y, int mode)

{

    if(mode==1)

    {

        for(int i=1; i<=h; i++)

            for(int j=1; j<=x; j++)

                a[i][j]=1;

    }

    else if(mode==2)

    {

        for(int i=1; i<=h; i++)

            for(int j=x+1;j<=w; j++)

                a[i][j]=1;

    }

    

    else if(mode==3)

    {

        for(int i=1; i<=y ; i++)

            for(int j=1; j<=w; j++)

                a[i][j]=1;

    }

    

    else{

        for(int i=y+1; i<=h; i++)

            for(int j=1; j<=w; j++)

                a[i][j]=1;

    }

}



int main()

{

    scanf("%d %d %d",&w, &h, &n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d %d %d",&x, &y, &t);

        f(x, y, t);

    }

    int cnt=0;

    for(int i=1; i<=h; i++)

        for(int j=1; j<=w; j++)

            if(a[i][j]==0)

                cnt++;

    printf("%d",cnt);

}





// sol2

/*

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

*/