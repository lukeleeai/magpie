#include "stdc++.h"

using namespace std;

int n;

int d[1000000];



string check2(){

  int nowpos=n-1;

  int canhop=n-1;

  int minhop=n-1;



  for(int j=0;j<300000;j++){

    canhop=nowpos-d[nowpos]/10;

    minhop=canhop;

    if(canhop<=0)return "yes";



    for(int i=nowpos;i>=canhop;i--){

      if(i-d[i]/10<minhop){

        nowpos=i;

        minhop=i-d[i]/10;

      }

    }





  }

  return "no";

}



string check1(){

  int nowpos=0;

  int canhop=0;

  int maxhop=0;



  for(int j=0;j<300000;j++){

    canhop=d[nowpos]/10+nowpos;

    maxhop=canhop;

    if(canhop>=n-1)return check2();



    for(int i=nowpos;i<=canhop;i++){

      if(d[i]/10+i>=maxhop){

        nowpos=i;

        maxhop=d[i]/10+i;

      }

    }

  }

  return "no";

}



int main(){

  cin >>n;

  for(int i=0;i<n;i++){

    cin>>d[i];

    int sub=d[i]%10;

    d[i]-=sub;

  }

  cout <<check1()<<endl;

  return 0;

}