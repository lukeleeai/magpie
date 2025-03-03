#include"stdc++.h"

using namespace std;

#define MAX_N 10005



int main(){

  while(1){

    int N,M;

    scanf("%d %d",&N,&M);

    if(M==0&&N==0)break;

    vector<int> Min(N,0);

    vector<int> Max(N,0);

    for(int i=0;i<M;i++){

      int p,k,id;

      scanf("%d %d",&p,&k);

      for(int j=0;j<k;j++){

        scanf("%d",&id);

        id--;

        if(k==1){

          Min[id]+=p;

        }

        Max[id]+=p;

      }

    }



    int mini=1e9,maxm=-1e9,ans=0;



    for(int i=0;i<N;i++){



      if(Max[i]>mini)

        ans=max(ans, abs(Max[i]-mini) );

        

      if(maxm>Min[i])

        ans=max(ans, abs(maxm-Min[i]) );



      mini=min(mini,Min[i]);

      maxm=max(maxm,Max[i]);

    }

    cout<<ans+1<<endl;

  }

  return 0;

}