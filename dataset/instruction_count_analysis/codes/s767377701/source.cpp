#include<cstring>

#include<algorithm>

#include<cstdio>

#define N 100005

long long int a[N];

int n;

long long int ans=0;

int main(){

scanf("%d",&n);

for(int i=1;i<=n;i++){

scanf("%lld",&a[i]);

}

for(int i=1;i<=n;i++){

if(i%2)ans+=a[i];

else ans-=a[i];

}



for(int i=1;i<=n;i++){

long long int x=2*a[i]-ans;

printf("%lld ",ans);

ans=x;

}



}