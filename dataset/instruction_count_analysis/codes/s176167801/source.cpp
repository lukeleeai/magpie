#include "stdc++.h"



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define sf scanf

#define pf printf

#define pb push_back

#define mp make_pair

#define PI ( acos(-1.0) )

#define mod 998244353LL

#define maxn 300005

#define IN freopen("C.in","r",stdin)

#define OUT freopen("output.txt","w",stdout)

#define FOR(i,a,b) for(i=a ; i<=b ; i++)

#define DBG pf("Hi\n")

#define INF 1000000000

#define i64 long long int

#define eps (1e-8)

#define xx first

#define yy second

#define ln 17

#define off 2



using namespace __gnu_pbds;

using namespace std ;



typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<i64, i64> pii;



int type[205] , y[205] ;



int main()

{

    int n ;



    scanf("%d",&n) ;



    for(int i=1 ; i<=n ; i++)

    {

        int x , Y ;

        scanf("%d %d",&x,&Y) ;

        type[x] = 1 ;

        y[x] = Y ;

    }



    for(int i=1 ; i<=n ; i++)

    {

        int x , Y ;

        scanf("%d %d",&x,&Y) ;

        type[x] = 2 ;

        y[x] = Y ;

    }



    int ans = 0 ;



    for(int i=2*n ; i>=0 ; i--)

    {

        if(type[i]==2) continue ;

        int mnY = 205 , idx = -1 ;

        for(int j=i+1 ; j<2*n ; j++)

        {

            if( type[j]==2 && y[j] > y[i] )

            {

                if( y[j] < mnY )

                {

                    mnY = y[j] ;

                    idx = j ;

                }

            }

        }

        if( idx != -1 )

        {

            ans++ ;

            type[idx] = -1 ;

        }

    }



    printf("%d\n",ans) ;



    return 0 ;

}
