#include <cstdio>

#include <algorithm>

#define repi(i,a,b) for(int i=(a);i<(b);++i)

#define rep(i,a) repi(i,0,a)

#define all(a) (a).begin(), (a).end()



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int N, C;

int D[40][40];

int c[510][510];

int diff[5][40];



int main()

{

  scanf( "%d%d", &N, &C );



  rep( i, C ) rep( j, C )

    scanf( "%d", &D[i][j] );



  rep( i, N ) rep( j, N )

    scanf( "%d", &c[i][j] ), --c[i][j];



  rep( col, C )

  {

    rep( i, N ) rep( j, N )

      diff[(i+1+j+1)%3][col] += D[c[i][j]][col];

  }



  int ans = 1<<30;



  rep( col1, C ) rep( col2, C ) rep( col3, C )

  {

    if( !(col1 != col2 && col2 != col3 && col3 != col1) )

      continue;



    ans = std::min( ans, diff[0][col1]+diff[1][col2]+diff[2][col3] );

  }



  printf( "%d\n", ans );



  return 0;

}