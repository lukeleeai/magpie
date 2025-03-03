#include<iostream>

using namespace std;



int N;

int a,b,ans=0;

int P[100010]={};



int main(){

  cin >> N;

  for(int i=0;i<N;i++){

    cin  >> a >> b;

    for(int j=a-1;j<=b-1;j++){

      P[j]+=1;

    }

  }

  for(int i=0;i<=N+1;i++){

    //cout << P[i] << endl;

  }

  for(int i=1;i<=N+1;i++){

    //cout << P[i] << endl;

    //ans = max(ans,P[i]);

    if(P[i]>=i){

      ans = max(ans,i);

    }

    else if(P[i]==i){

      ans = max(ans,P[i]);

    }

    //cout << i <<":" << ans << endl;

  }

  //if(ans!=0) ans-=1;

  cout << ans << endl;

}


