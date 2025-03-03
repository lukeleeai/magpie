/*

the top of the losers

*/

#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define sz(v)   ((int)(v).size())

#define  all(v)    ((v).begin()),((v).end())

#define  allr(v)    ((v).rbegin()),((v).rend())

#define   pb         push_back

#define   mp         make_pair

#define    Lcm(a,b)  ((a*b)/(__gcd(a,b)))

#define   length(a)      hypot( (a.imag()),(a.real()) )

#define    x            real()

#define    y            imag()

#define    clr(v,d)      memset( v, d ,sizeof(v))

#define     point        complex<double>

#define    dp(a,b)          (((conj(a))*(b)).real())

#define    cp(a,b)          (((conj(a))*(b)).imag())

typedef  long long     ll ;

typedef  unsigned long long     ull ;

const double eps= (1e-9);

using namespace std;

using namespace __gnu_pbds;

int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}

int setBit1(int num, int idx) {return num | (1<<idx);}

ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}

ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}

int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}

void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

vector< pair<int,pair<int,int> > >v1,v2;

string tst;

ll get_res(){

    int cnt=0;

    for(int i=0;i<sz(tst)-1;i++){

        if(tst[i]==tst[i+1])

            cnt++;

    }

    return cnt;

}

void up(int a,int b){

   for(int i=a;i<=b;i++){

    if(tst[i]=='L') tst[i]='R';

    else tst[i]='L';

   }

}

int main(){

    GO();

    int n,k;

    string st;

    cin>>n>>k>>st;

    int lf=0;

    tst=st;

    for(int i=0;i<n;i++){

        if(i+1<n&&st[i]==st[i+1]){

            ;

        }

        else{

            int stat=0;

            if(i>0&&lf<n)

                stat=2;

            else if(i==0&&lf==n-1){

                stat=0;

            }

            else{

               stat=1;

            }

            if(st[i]=='L')

            v1.pb(mp(stat,mp(lf,i)));

            else

            v2.pb(mp(stat,mp(lf,i)));

            lf=i+1;

        }

    }

    int cnt=0;



    sort(allr(v1));

    sort(allr(v2));

    int rem=k;

    ll add=0;

    for(int i=0;i<sz(v1)&&rem>0;i++){

        rem--;

        up(v1[i].second.first,v1[i].second.second);

    }

    cnt=get_res();



    int ans=0;

    ans=max(cnt,ans);



    rem=k;

    add=0;

    tst=st;



    for(int i=0;i<sz(v2)&&rem>0;i++){

        rem--;

        up(v2[i].second.first,v2[i].second.second);

    }

    cnt=get_res();

    ans=max(ans,cnt);

    cout<<ans<<endl;

}




