#include "stdc++.h"

typedef long long ll;

typedef long double ld;

const int INF=1e9,MOD=1e9+7,ohara=1e6;

const ll LINF=1e18;

using namespace std;



#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

#define rrep(i,a,b) for(int i=(a);i<(b);i++)

#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)

#define all(v) (v).begin(), (v).end()

#define Size(n) (n).size()

#define Cout(x) cout<<(x)<<endl



ll n,cnt,ans[ohara],a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos;

ld doua;

int dy[]={1,0,-1,0};

int dx[]={0,1,0,-1};

//int dy[]={-1,0,1,-1,1,-1,0,1};

//int dx[]={-1,-1,-1,0,0,1,1,1};

string alph("abcdefghijklmnopqrstuvwxyz"),s;

bool fl,f[ohara];

struct edge{int to,cost;};

map<pair<ll,ll>,ll> mp1;

map<pair<ll,ll>,ll> mp2;

map<pair<pair<ll,ll>,ll>,ll> mp3;



//-------------------------↓↓↓↓↓↓------------------------



void func(ll sp){

    rrep(i,2,n+1){

        if(!f[i]){

            if(sp%i==0){

                while(1){

                    sp/=i;

                    ans[i]++;

                    if(sp%i!=0)break;

                }

            if(sp<=1)break;

            }

        }

    }

    return ;

}



int main(void){

       cin.tie(0);

    ios::sync_with_stdio(false);



    cin>>n;

    pos=0;

    rrep(i,2,10000){

        if(!f[i]){

            for(int j=i+i;j<=10000;j+=i){

                f[j]=true;

            }

        }

    }

    rrep(i,2,n+1){

        func(i);

    }

    rep(i,n+1){

        ans[i]++;

    }

    rep(i,n+1){

        if(ans[i]>=75)cnt++;

    }

    rep(i,n+1){

        rrep(j,0,n+1){

            if(i==j)continue;

            if((ans[i]>=3&&ans[j]>=25))pos++;

        }

    }

    cnt+=pos;

    pos=0;

    rep(i,n+1){

        rrep(j,0,n+1){

            if(i==j)continue;

            if((ans[i]>=5&&ans[j]>=15))pos++;

        }

    }

    cnt+=pos;

    pos=0;

    rep(i,n+1){

        rrep(j,0,n+1){

            rrep(k,0,n+1){

                if(i==j||i==k||j==k)continue;

                if((ans[i]>=3&&ans[j]>=5&&ans[k]>=5))pos++;

            }

        }

    }

    cnt+=pos/2;

    Cout(cnt);

    return 0;

}
