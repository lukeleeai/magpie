#include "stdc++.h"



#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)

#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)

#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)

#define all(v) (v).begin(), (v).end()

#define pb(q) push_back(q)

#define Size(n) (n).size()

#define Cout(x) cout<<(x)<<endl



typedef long long ll;



using namespace std;



const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;

const ll LINF = 1e18;

long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,ppos;

int dy[]={1,0,-1,0};

int dx[]={0,1,0,-1};

string alph("abcdefghijklmnopqrstuvwxyz"),s;

bool fl;

struct edge{int to,cost;};



//-------------------------↓↓↓↓↓↓------------------------



int main(void){

       cin.tie(0);

    ios::sync_with_stdio(false);

      

      cin>>n;

      ll dp[n+1];

      rep(i,n+1){

        dp[i]=LINF;

      }

      dp[0]=0;

      rrep(i,1,n+1){

        if(i<6){

          dp[i]=min(dp[i-1]+1,dp[i]);

        }

        else if(i<9){

          pos=6;

          while(1){

            dp[i]=min({dp[i-1]+1,dp[i-pos]+1,dp[i]});

            pos*=6;

            if(pos>i)break;

          }

        }

        else{

          pos=6;

          ppos=9;

          while(1){

            if(ppos>i){

              dp[i]=min({dp[i-1]+1,dp[i-pos]+1,dp[i]});

               pos*=6;

            }

            else dp[i]=min({dp[i-1]+1,dp[i-pos]+1,dp[i-ppos]+1,dp[i]}),pos*=6,ppos*=9;

            if(pos>i)break;

          }

        }

      }

      Cout(dp[n]);

    

       

return 0;

}
