/*

#pragma GCC optimize("Ofast,unroll-loops")

#pragma GCC target("avx,avx2,fma")

*/

#include "stdc++.h"

#define LL              long long

#define ll              long long

#define SL(n)           scanf("%lld",&n)

#define LF              double

#define SF(n)           scanf("%lf",&n)

 

#define pb              push_back

#define mp              make_pair

 

#define ON(n,i)         (n|(1LL<<i))

#define OFF(n,i)        (n&(~(1LL<<i)))

#define CHK(n,i)        (n&(1LL<<i))

 

#define ff              first

#define ss              second

 

#define SET(arr)        memset( arr , -1 , sizeof arr)

#define RESET(arr)      memset( arr,0,sizeof arr)

 

#define srt(v)          sort(v.begin(),v.end())

#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))

#define found( s,d )    (s.find(d) != s.end())

 

#define FOR(i,s,e)      for( LL i = s ; i<=e ; i++ )

#define RFOR(i,e,s)     for( LL i = e ; i>=s ; i-- )

         

 

#define FILEIN          freopen("in.txt","r",stdin)

#define FILEOUT         freopen("WA.txt","w",stdout)

 

#define DEBUG(x)        cerr<<#x<<" = "<<x<<endl

#define PRINTALL(v)     {cerr<<endl<<"Printing: "<<#v<<endl;for(LL i = 0 ; i<v.size(); i++) DEBUG(v[i]); cerr<<endl;}

 

using namespace std;

const LL inf = 1e9;



const LL lim = 1010;

LL dp[lim][lim];

LL c[lim], t[lim];

LL N,T;



LL F( LL pos, LL rem ){

    if(rem<0) return inf;

    if(pos == 0){

        if( rem == T ) return inf;

        else return 0;

    }

    LL &ret = dp[pos][rem];

    if(ret!=-1) return ret;

    ret = min( F(pos-1, rem) , c[pos] + F(pos-1,rem-t[pos]) );

    return ret;

}





int main(){

    SET(dp);

    

    SL(N); SL(T);

    FOR(i,1,N) SL(c[i]), SL(t[i]);

    LL ans = F(N,T);

    if(ans>=inf) cout<<"TLE"<<endl;

    else cout<<ans<<endl; 

return 0;}