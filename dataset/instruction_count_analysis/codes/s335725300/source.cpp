#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <math.h>

#include <queue>

#include <deque>

#define MOD 1000000007

typedef long long ll;

using namespace std;



#define INFTY (1<<30)

#define MAX 100010



int main(){

  int k;

  cin>>k;



  deque<pair<int,int>> DQ;

  int d[k+1]={};

  for(int i=0;i<k;i++) d[i]=INFTY;

  DQ.push_back(make_pair(1,0));



  while(!DQ.empty()){

    pair<int,int> p=DQ.front();

    DQ.pop_front();

    int f=p.first;

    if(d[f]!=INFTY) continue;

    d[f]=p.second;



    DQ.push_front(make_pair((f*10)%k,d[f]));

    DQ.push_back(make_pair((f+1)%k,d[f]+1));

  }



  cout<<d[0]+1<<endl;



  return 0;

}
