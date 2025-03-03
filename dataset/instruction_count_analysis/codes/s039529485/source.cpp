#include "stdc++.h"



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define sf scanf

#define pf printf

#define pb push_back

#define mp make_pair

#define PI ( acos(-1.0) )

#define mod 1000000007LL

#define IN freopen("C.in","r",stdin)

#define OUT freopen("output.txt","w",stdout)

#define FOR(i,a,b) for(i=a ; i<=b ; i++)

#define DBG pf("Hi\n")

#define MEM(ara,val) memset(ara,val,sizeof(ara))

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



#define maxn 700



int g[maxn+5][maxn+5] ;



int col[maxn+5] , cnt[2] , n ;



bool dfs(int u ,int c)

{

//    printf("dfs %d %d\n",u,c) ;

    int ret = 1 ;

    cnt[c]++ ; col[u] = c ;

    for(int i=1 ; i<=n ; i++)

    {

        if(!g[u][i] || u==i) continue ;

        int v = i ;

        if( col[v]!=-1 && col[v]==c )

        {

  //          printf("false %d %d\n",u,v) ;

            ret = false ;

        }

        if( col[v]==-1 ) ret &= dfs(v,c^1) ;

    }

    return ret ;

}



int dp[705][705] ;



int main()

{

    MEM(col,-1) ;

    MEM(g,1) ;



    int i , j , k , m ;



    scanf("%d %d",&n,&m) ;



    for(i=1 ; i<=m ; i++)

    {

        int u , v ;

        scanf("%d %d",&u,&v) ;

        g[u][v] = 0 ;

        g[v][u] = 0 ;

    }

    int yes = 1 ;

    dp[0][0] = 1 ;

    for(i=1 ; i<=n ; i++)

    {

        if( col[i]==-1 )

        {

            cnt[0]= cnt[1] = 0 ;

            yes &= dfs(i,0) ;

            for(j=0 ; j+cnt[0]<=n ; j++) dp[i][j+cnt[0]] |= dp[i-1][j] ;

            for(j=0 ; j+cnt[1]<=n ; j++) dp[i][j+cnt[1]] |= dp[i-1][j] ;

        }

        else for(j=0 ; j<=n ; j++) dp[i][j] = dp[i-1][j] ;

    }

    int ans = (n*(n-1))/2 ;



    for(i=0 ; i<=n ; i++)

    {

        if( dp[n][i] ) ans = min( ans, (n*(n-1))/2 - (n-i)*i ) ;

    }



    if(!yes) printf("-1\n") ;

    else printf("%d\n",ans) ;



    return 0 ;

}
