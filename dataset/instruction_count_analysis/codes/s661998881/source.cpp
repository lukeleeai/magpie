#include "stdc++.h"

typedef long long ll;

const int INF=1e9,MOD=1e9+7,ohara=1e6;

const ll LINF=1e18;

using namespace std;



#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)

#define rrep(i,a,b) for(ll i=(a);i<(b);i++)

#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)

#define all(v) (v).begin(), (v).end()

#define pb(q) push_back(q)

#define Size(n) (n).size()

#define Cout(x) cout<<(x)<<endl



ll n,cnt,ans[ohara],a,b,c,d,cmp,cmpp,m,h,w,x,y,sum,pos;

int dy[]={1,0,-1,0};

int dx[]={0,1,0,-1};

//int dy[]={-1,0,1,-1,1,-1,0,1};

//int dx[]={-1,-1,-1,0,0,1,1,1};

string alph("abcdefghijklmnopqrstuvwxyz"),s;

bool fl;

struct edge{int to,cost;};



//-------------------------↓↓↓↓↓↓------------------------



void cal(ll dat){

    rrep(i,2,n+1){

        if(dat<=1)break;

        if(dat%i!=0)continue;

        while(1){

        dat/=i;

        ans[i]++;

        if(dat%i!=0||dat<=1)break;

        }

    }

    return;

}



int main(void){

       cin.tie(0);

    ios::sync_with_stdio(false);



    rep(i,ohara)ans[i]=1;

    cin>>n;

    rrep(i,2,n+1){

        cal(i);

    }

    rep(i,n+1){

        rep(j,n+1){

            rep(k,n+1){

                if(i==j||j==k||i==k)continue;

                if(ans[i]>=5&&ans[j]>=5&&ans[k]>=3)cnt++;

            }

        }

    }

    cnt/=2;

    rep(i,n+1){

        rep(j,n+1){

            if(i==j)continue;

            if(ans[i]>=3&&ans[j]>=25)cnt++;

            if(ans[i]>=5&&ans[j]>=15)cnt++;

        }

    }

    rep(i,n+1){

        if(ans[i]>=75)cnt++;

    }

    Cout(cnt);

    return 0;

}
