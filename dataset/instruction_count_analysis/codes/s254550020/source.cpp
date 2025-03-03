#include <stdio.h>

#include <stdlib.h>

#include<math.h>

#include<algorithm>

#include<vector>

#include<queue>

#include<string>

#include<set>

#include<cstring>

 

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

#define INF 1001001001

#define LLINF 1001001001001001001

#define mp make_pair

#define pb push_back

#define LLIandI pair<long long int , int>

#define ll long long



//DPバージョン

int main(void){

    int N,Ma,Mb;

    scanf("%d %d %d",&N,&Ma,&Mb);

    int A[50],B[50],C[50];

    int dp[41][41*11*11*2];

    //dp[i][j]=m i番までの薬品を使ってM_a*b-M_b*a(絶対値N(=40)*Ma,Mb(=10)*max(a),max(b)(=10)=4000以下)=Jにしたときの最低のコストがmということを表す

    //Jについては、添字jについてJ=k-N*10*10とする。(kは0以上2*N*10*10以下 )

    rep(i,N)rep(j,N*10*10*2+1)dp[i][j]=INF;

    rep(i,N){

        scanf("%d %d %d",&A[i],&B[i],&C[i]);

        if(i==0){

            dp[i][N*100]=0;

            dp[i][N*100+Ma*B[i]-Mb*A[i]]=C[i];

        }

    }

    rep(i,N){

        rep(k,2*100*N+1){

            //i-1番めまでは一切使わない時の例外処理

            dp[i][ N*100+Ma*B[i]-Mb*A[i] ]=min(C[i], dp[i][ N*100+Ma*B[i]-Mb*A[i] ] );

            if(i<N-1){

                if(dp[i][k]==0)continue;//i番目までは全く使っていないものについては上で処理するので継承しない

                int newJ=Ma*B[i+1]-Mb*A[i+1];

                //i+1を使う時

                dp[i+1][k+newJ]=min(dp[i][k]+C[i+1], dp[i+1][k+newJ] );

                //i+1を使わない時

                dp[i+1][k]=min(dp[i][k],dp[i+1][k]);

            }

            

        }

    }

    

    if(dp[N-1][N*100]>=INF||dp[N-1][N*100]<=0)printf("%d\n",-1);

    else printf("%d\n",dp[N-1][N*100]);

}
