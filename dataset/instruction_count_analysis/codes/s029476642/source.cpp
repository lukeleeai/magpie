#include"stdc++.h"

using namespace std;

#define MAX_N 10005

int N,M;

int main(){

  while(cin>>N>>M){

    int Min[MAX_N]={},Max[MAX_N]={};

    if(M==0&&N==0)break;

    for(int i=0;i<M;i++){

      int p,k,id;

      cin>>p>>k;

      for(int j=0;j<k;j++){

        cin>>id;

        id--;

        if(k==1){

          Min[id]+=p;

        }

        Max[id]+=p;

      }

    }

    int ans=0;

    for(int i=0;i<N;i++){

      for(int j=0;j<i;j++){

        if(Max[i]>Min[j])

          ans=max(ans, abs(Max[i]-Min[j]) );

        

        if(Max[j]>Min[i])

          ans=max(ans, abs(Max[j]-Min[i]) );

      }

    }

    cout<<ans+1<<endl;

  }

  return 0;

}