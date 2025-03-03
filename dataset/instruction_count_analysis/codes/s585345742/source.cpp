#include<cstdio>

#include<cstdio>

#include<cstring>

#include<set>

#include<queue>

#include<algorithm>

#define N 1005

#define INF 0x3f3f3f3f

using namespace std;

long long int a,b,x,y;

long long int exgcd(long long int a,long long int b,long long int &x,long long int &y){

if(b==0){

x=1;

y=0;

return a;

}

long long int ans=exgcd(b,a%b,y,x);

y-=a/b*x;

return ans;

}



int main(){

long long int s;

scanf("%lld",&s);

//s=(long long int )1e18-2;

a=1000000000;

b=1;

x=s%a?s/a+1:s/a;

y=a*x-s;

printf("0 0 %lld %lld %lld %lld",a,b,y,x);

}