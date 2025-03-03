#include<cstring>

#include<algorithm>

#include<cstdio>

#define N 20005



using namespace std;

int a[N],n;

bool cmp(int a,int b){

return a>b;

}



int sol(int x,int y,int l,int r){

if(l==r){

if(y+a[l]>x)return l;

else return -1;

}

int md=(l+r)/2;

if(y+a[md+1]<=x)return sol(x,y,l,md);

else return sol(x,y,md+1,r);

}

int main(){

scanf("%d",&n);

for(int i=1;i<=n;i++){

scanf("%d",&a[i]);

}

sort(a+1,a+n+1,cmp);

long long int ans=0;

for(int i=1;i<=n;i++){

for(int j=i+1;j<=n-1;j++){

int as=sol(a[i],a[j],j+1,n);

if(as>j)ans+=(long long int )(as-j);

}

}

printf("%lld",ans);

}