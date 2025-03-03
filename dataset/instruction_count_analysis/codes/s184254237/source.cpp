#include"stdc++.h"

using namespace std;

int main()

{

  int64_t A,B,C,K;

  cin>>A>>B>>C>>K;

  if(A>=K)return cout<<K<<endl,0;

  K-=A;

  if(B>=K)return cout<<A<<endl,0;

  K-=B;

  return cout<<A-K<<endl,0;

}