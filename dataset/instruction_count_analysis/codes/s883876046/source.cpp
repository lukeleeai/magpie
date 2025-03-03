#include "stdc++.h"



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define sf scanf

#define pf printf

#define pb push_back

#define mp make_pair

#define PI ( acos(-1.0) )

#define IN freopen("hard1.txt","r",stdin)

#define OUT freopen("hard1.txt","w",stdout)

#define FOR(i,a,b) for(i=a ; i<=b ; i++)

#define DBG pf("Hi\n")

#define i64 long long int

#define eps (1e-8)

#define xx first

#define yy second

#define ln 17

#define off 1000005



using namespace __gnu_pbds;

using namespace std ;



typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<i64, i64> pii;



#define INF 1000000000000000000LL

#define alpha 26

#define mod 998244353LL

#define maxn 500005

#define LOG 18



bool comp( pair<i64,i64> a, pair<i64,i64> b )

{

    return ( a.xx-a.yy > b.xx-b.yy ) ;

}



i64 X[maxn] , Y[maxn] ;



i64 f( int x , int y , vector < pair<i64,i64> > vp )

{

    sort( vp.begin() , vp.end() , comp ) ;

    multiset<i64> ms ;



    i64 ret = 0 ;



    int n = (int)vp.size() ;



    for(int i=0 ; i<n ; i++)

    {

        ms.insert( vp[i].xx ) ;

        ret += vp[i].xx ;

        if( ms.size() > x )

        {

            auto it = ms.begin() ;

            ret -= (*it) ;

            ms.erase(it) ;

        }

        X[i] = ret ;

    }

    ms.clear() ;

    ret = 0 ;

    for(int i=n-1 ; i>=0 ; i--)

    {

        ms.insert( vp[i].yy ) ;

        ret += vp[i].yy ;

        if( ms.size() > y )

        {

            auto it = ms.begin() ;

            ret -= (*it) ;

            ms.erase(it) ;

        }

        Y[i] = ret ;

    }

    i64 ans = -INF ;

    for(int i=0 ; i<n ; i++)

    {

        if( i+1 >= x && (n-1-i) >= y ) ans = max( ans , X[i] + Y[i+1] ) ;

    }

    return ans ;

}



int main()

{

    int x , y , z  ;



    scanf("%d %d %d",&x,&y,&z) ;



    i64 ans = 0 ;

    vector < pair<i64,i64> > vp ;



    for(int i=1 ; i<=x+y+z ; i++)

    {

        i64 a , b , c ;

        scanf("%lld %lld %lld",&a,&b,&c) ;

        ans += a ;

        b-=a ; c-=a ;

        vp.pb(mp(b,c)) ;

    }



    ans += f(y,z,vp) ;



    printf("%lld\n",ans) ;



    return 0 ;

}
