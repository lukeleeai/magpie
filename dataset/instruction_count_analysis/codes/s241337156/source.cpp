#include "stdc++.h"

using namespace std;

static const long long MOD=1000000007;



int main(){

  long long N;

  cin>>N;

  long long A[200010];

  long long sum=0;

  for(long long i=0;i<N;i++){

    cin>>A[i];

    sum+=A[i];

  }

  sum%=1000000007;

  long long ans=0;

  sum-=A[0];

  if(sum<0){

    sum+=MOD;

  }

  for(long long i=0;i<N-1;i++){

    ans+=A[i]*sum;

    ans%=1000000007;

    sum-=A[i+1];

    if(sum<0){

    sum+=MOD;

    }

  } 

  cout<<ans<<endl;

  return 0;

}



 
