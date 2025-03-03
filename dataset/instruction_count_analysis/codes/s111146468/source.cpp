#include "stdc++.h"



#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)

#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)

#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)

#define all(v) (v).begin(), (v).end()

#define pb(q) push_back(q)

#define Abs(a,b) max(a,b)-min(a,b)

#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}

#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}

#define Cout(x) cout<<(x)<<endl

#define POSSIBLE(condition) if(condition){cout << "POSSIBLE" << endl;}else{cout << "IMPOSSIBLE" << endl;}

#define Possible(condition) if(condition){cout << "Possible" << endl;}else{cout << "Impossible" << endl;}

#define possible(condition) if(condition){cout << "possible" << endl;}else{cout << "impossible" << endl;}

#define Size(n) (n).size()



typedef long long ll;





using namespace std;



const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;

const ll LINF = 1e18;



/*---------------------------------------------------------------

long long int kaizyo(long long int hh){

    cmp=1;

    while(hh>1){

        cmp=(cmp*hh)%MOD;

        hh--;

    }

    return cmp;

}

long long int ruizyo(long long int aa, long long int bb){

    if(aa==0){

        return 1;

    }

    else if(aa%2==0){

        long long int tt=ruizyo(aa/2,bb);

        return (tt*tt)%MOD;

    }

    else{

        return (ruizyo(aa-1,bb)*bb)%MOD;

    }

}フェルマ－のア

---------------------------------------------------------------



while(x!=0){

            sum+=x%10;

          / x/=10;

        }

        各桁の和

---------------------------------------------------------------



pair<int,int> p[100000];

cin >> tmp;

p[i]=make_pair(tmp,i);

cout << p[i].second+1 << endl;//ペアの右側つまりiを出力



---------------------------------------------------------------



bool f[100001];//1000000以下の素数を調べよう！

rrep(i,2,100001){

       f[i]=false;

    }

rrep(i,2,100001){

        if(!f[i]){

            for(int j=i+i;j<=100000;j+=i){

                f[j]=true;

            }

        }

    }

    for(int i=3;i<=100000;i+=2){

        if(!f[i]){

            c[i]++;

        }

    }



---------------------------------------------------------------



long long gcd(long long aaa,long long bbb){

    if(bbb==0){

        return aaa;

    }

    return gcd(bbb,aaa%bbb);

}

 

long long lcm(long long aaa,long long bbb){

    long long g = gcd(aaa,bbb);

    return aaa/g * bbb;

}左から最大公約数と最小公倍数





---------------------------------------------------------------



long long int prime_cnt[10000];

       for(int i=2;i*i<=n;i++){

           while(n%i==0){

               n/=i;

               prime_cnt[i]+=1;

           }

           if(n>1){

               prime_cnt[n]+=1;

               break;

           }

      }ある数nを素因数分解しましょう



---------------------------------------------------------------

debug:

cout<<"i: "<<i<<" j: "<<j<<" cnt: "<<cnt<<"\n";



---------------------------------------------------------------*/



long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,dp[ohara];

int dy[]={1,0,-1,0};

int dx[]={0,1,0,-1};

string alph("abcdefghijklmnopqrstuvwxyz"),s;

bool fl=true;

struct edge{int to,cost;};



//-------------------------↓↓↓↓↓↓------------------------



int main(void){

       cin.tie(0);

    ios::sync_with_stdio(false);



      

       cin>>n;

       rep(i,ohara){

           dp[i]=INF;

       }

       dp[0]=0;



       rep(i,n){

           dp[i+1]=min(dp[i+1],dp[i]+1);

           for(ll j=6;i+j<=n;j*=6){

               dp[i+j]=min(dp[i+j],dp[i]+1);

           }

           for(ll j=9;i+j<=n;j*=9){

               dp[i+j]=min(dp[i+j],dp[i]+1);

           }

       }

       Cout(dp[n]);

       

return 0;

}
