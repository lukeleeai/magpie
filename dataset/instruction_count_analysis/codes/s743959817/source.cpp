#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);++i)

#define rep(i,a) repi(i,0,a)

#define all(a) (a).begin(), (a).end()



using ll = long long;



ll N;

ll A[100010];

std::vector<ll> ma, minus;

ll S;



int main()

{

  scanf( "%lld", &N );



  rep( i, N )

  {

    scanf( "%lld", A+i );



    if( A[i] >= 0 )

      ma.push_back( A[i] );

    

    if( A[i] < 0 )

      minus.push_back( -A[i] );



    S += llabs(A[i]);

  }



  std::sort( all(ma) );

  std::sort( all(minus) );



  ll ans = 0;



  if( minus.size() & 1 )

  {

    if( !minus.empty() ) rep( i, minus.size()-1 )

      ans += minus[i+1];



    if( !ma.empty() && !minus.empty() )

    {

      if( ma[0] < minus[0] )

      {

        ans += minus[0];

        ans -= ma[0];

      }

      else

      {

        ans -= minus[0];

        ans += ma[0];

      }

    }

    else

    {

      if( !ma.empty() )

        ans += ma[0];

      if( !minus.empty() )

        ans -= minus[0];

    }



    if( !ma.empty() ) rep( i, ma.size()-1 )

      ans += ma[i+1];

  }

  else

    ans = S;



  printf( "%lld\n", ans );



  return 0;

}