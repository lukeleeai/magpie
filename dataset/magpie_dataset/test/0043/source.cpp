#include "stdc++.h"

using namespace std;

#define print printf("==================\n")

#define ll long long

#define pi acos(-1.0)

#define eps 1e-16

const ll INF = 1 << 30;

typedef pair<ll, ll  > payar;

typedef struct

{

    ll  x, y;

} point;

priority_queue<payar, vector<payar>,  greater<payar> > pq; ///accending

vector< pair<ll,payar  > > vpp;

vector < payar >  vp;



ll n ;

int ara[200005];



ll dp[200005];



ll par[100005];



ll k ;

ll cal(int pos)

{

      if(pos>n)

    {

        return 10000000000000000;

    }

    if(dp[pos]!=-1)

    {

        return dp[pos];

    }

    if(pos==n )

    {

        return 0 ;

    }







    dp[pos]=abs(ara[pos+1]-ara[pos]) +cal(pos+1);



    for(int i  = 2 ; i<=k ; i++)

    {



            dp[pos]=min( abs(ara[pos]-ara[pos+i])+ cal(pos+i), dp[pos] );



    }

    return dp[pos];

}

int main()

{



    cin>>n>>k;

    memset(dp,-1,sizeof dp);

    for(int i =  1 ; i<=n ; i++)

    {

        //  cin>>ara[i];

        scanf("%d",&ara[i]);

    }

      for(int i =  n+1 ; i<=n+k ; i++)

    {

        ara[i]=10000000000000000;

       // scanf("%d",&ara[i]);

    }

    cout<<cal(1);







    return  0 ;

}
