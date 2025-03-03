#include<stdio.h>

#include<algorithm>

using namespace std;

int n,k,i,j,srx[200001],sry,t,p;

int main(){

   scanf("%d%d",&n,&k);

   for(i=1;i<=n;++i){

   scanf("%d",&t);

   srx[t]++;

   } 

   sort(srx+1,srx+n+1);

   for(i=n;i>n-k;--i) 

   sry+=srx[i]; 

   printf("%d",n-sry); 

   return 0;

}