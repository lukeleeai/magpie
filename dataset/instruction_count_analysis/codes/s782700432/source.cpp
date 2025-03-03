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





int main(void){

    int N,Ma,Mb;

    scanf("%d %d %d",&N,&Ma,&Mb);

    int A[50],B[50],C[50];

    rep(i,N){

        scanf("%d %d %d",&A[i],&B[i],&C[i]);

    }

    //Asum*Mb-Bsum*Ma=0

    vector< pair<int, int> > H1;

    vector< pair<int, int>  > H2;

    rep(i,1<<(N/2)){ //0...N/2-1 (N/2)

        int ABh=0,Ch=0;

        rep(j,N/2){

            ABh+=Mb*A[j]*( (i>>j)%2 );

            ABh-=Ma*B[j]*( (i>>j)%2 );

            Ch+=C[j]*( (i>>j)%2 );

        }

        H1.pb(mp(ABh,Ch ) );

    }

    rep(i,1<<(N-N/2) ){//N/2...N-1 (N-N/2)

        int ABh=0,Ch=0;

        rep(j,(N-N/2)){

            ABh+=Mb*A[j+N/2]*( (i>>j)%2 );

            ABh-=Ma*B[j+N/2]*( (i>>j)%2 );

            Ch+=C[j+N/2]*( (i>>j)%2 );

        }

        H2.pb(mp(ABh,Ch) );

    }

    sort(H1.begin(),H1.end());sort(H2.begin(),H2.end());

    int ans=1001001001;

    rep(i,H1.size()){

        int ite=lower_bound(H2.begin(),H2.end(),mp(-H1[i].first,-1) )-H2.begin();

        if(ite<H2.size()&&H1[i].second+H2[ite].second!=0&&H1[i].first+H2[ite].first==0){

            ans=min(ans,H1[i].second+H2[ite].second);

        }

        if(ite+1<H2.size()&&H1[i].second+H2[ite+1].second!=0&&H1[i].first+H2[ite+1].first==0){

            ans=min(ans,H1[i].second+H2[ite+1].second);

        }

    }

    if(ans==0||ans==1001001001)printf("%d\n",-1);

    else printf("%d\n",ans);

}
