//#include"stdc++.h"

#include<cstdio>

#include<cstdlib>

#include<iostream>

#include<algorithm>

#include<vector>

#include<stack>

#include<queue>

#include<set>

#include<string>

#include<cmath>

#include<cassert>

#include<cstdint>

#include<map>

using namespace std;



typedef int64_t i64;typedef int32_t i32;

typedef int16_t i16;typedef int8_t i8;

typedef uint64_t ui64;typedef uint32_t ui32;

typedef uint16_t ui16;typedef uint8_t ui8;



typedef i64 int__;

#define rep(i,j) for(int__ i=0;i<j;i++)

#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)

#define all(v) begin(v),end(v)



const i32 INF=1<<30;//10E10



int P,Q,A,N;

double PpQ;

int dfs(i64 sum_u,i64 sum_d,int i,int a,int n){

  //printf("u:%lld d:%lld i:%d a:%d n:%d\n",sum_u,sum_d,i,a,n);

  if(P*sum_d==Q*sum_u)return 1;

  if(n<=0)return 0;

  int ret=0;

  while(i*a<=A){

    int u=sum_u*i+sum_d;

    int d=sum_d*i;

    if(P*d>=Q*u and Q*(n*d+u*i)>=P*d*i)

      ret+=dfs(u,d,i,i*a,n-1);

    i++;

  }

  return ret;

}





int main()

{

  while(true){

    cin>>P>>Q>>A>>N;

    if(Q==0)break;

    PpQ=(double)P/Q;

    cout<<dfs(0,1,1,1,N)<<endl;

  }

  return 0;

}