#include<iostream>

#include<algorithm>

#include<cstring>

#include<cstdio>

#include<map>

#include<queue>

#define inf1 1000000009

#define inf -1

using namespace std;

long long A,B,N;

long long s[100006];

bool cool(int a){

long long t=a;long long s1[100006];

 for(int i=1;i<=N;i++)

    s1[i]=s[i];

 for(int i=1;i<=N;i++)

   { s1[i]-=a*B;

    if(s1[i]<=0)continue;

      int y;

      if(s1[i]%(A-B)==0)y=s1[i]/(A-B);

      else y=s1[i]/(A-B)+1;

       t-=y;

   }//cout<<endl;

 if(t>=0)return true;

 return false;

}

int main(){



 cin>>N>>A>>B;

  for(int i=1;i<=N;i++)

  cin>>s[i];

  long long l=0,L=inf1,s1;s1=inf1;

  while(l<L){

   long long man=(l+L)/2;

    if(cool(man)) L=man,s1=min(s1,man);

    else l=man+1;

    //cout<<L<<" "<<l<<endl;

  }

  cout<<s1<<endl;

}