#include<iostream>

#include<cstdio>

#define N 100000



using namespace std;







int main(){

  int K,c[N],i,ans=0;



  while(1){

    ans=0;

    for(i=0;i<N;i++){

      c[i]=0;

    }

    

    cin >> K;

    if(K==0)break;

    

  

   

    for(i=0;i<(K*(K-1))/2;i++){

      cin >> c[i];

    }

  

   

    

    for(i=0;i<=(K*(K-1))/2;i++){

      ans+=c[i];  

    }



    

  ans=ans/(K-1);

  

  cout << ans << endl;

  

  

  }

  

}