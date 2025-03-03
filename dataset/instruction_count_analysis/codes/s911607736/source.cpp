#include <cstdio>

#include <algorithm>

#define repi(i,a,b) for(int i=(a);i<(b);++i)

#define rep(i,a) repi(i,0,a)

#define all(a) (a).begin(), (a).end()



using ll = long long;



ll N;

ll A[100010];

ll dp[100010][2];



int main()

{

  scanf( "%lld", &N );

  rep( i, N )

    scanf( "%lld", A+i );



  dp[0][0] = A[0], dp[0][1] = -A[0];



  rep( i, N )

  {

    dp[i+1][0] = std::max( dp[i][0]+A[i+1], dp[i][1]-A[i+1] );

    dp[i+1][1] = std::max( dp[i][0]-A[i+1], dp[i][1]+A[i+1] );

  }



  printf( "%lld\n", dp[N-1][0] );



  return 0;

}