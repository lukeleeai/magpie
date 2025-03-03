#include"stdc++.h"

using namespace std;

typedef long long ll;

#define MAX 100005





ll bit[MAX];



void numSet(int r,ll x){

  r=MAX-r-1;

  while(r){

    bit[r]=max(bit[r],x);

    r-=(r&-r);

  }

}



ll getMin(int i){

  i=MAX-i-1;

  ll res=0;

  while(i<MAX){

    res=max(res,bit[i]);

    i+=(i&-i);

  }

  return res;

}





ll n,k,sum,ans,num;

int main(){

  scanf("%lld",&n);

  while(n--){

    scanf("%lld",&num);

    sum+=num;

    k=getMin(num);

    ans=max(ans,k+num);

    numSet(num,k+num);

  }

  printf("%lld\n",sum-ans);

  return 0;

}