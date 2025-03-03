#include<cstring>

#include<algorithm>

#include<cstdio>

#define N 10005

#define INF 0x3f3f3f3f

using namespace std;

long long int d[N];

long long int a[1005];

int v[15];

int s[10005];

int b[1005];

int c[15];

int n;

int m;

int tar;

long long int ans=INF;

int main(){

scanf("%d%d",&n,&m);

//for(int i=1;i<=n;i++){

//l[i][0]=0;

//}

memset(d,0x3f,sizeof(d));

memset(v,0,sizeof(v));

memset(s,0,sizeof(s));



for(int i=1;i<=m;i++){

int x,y;

scanf("%lld%d",&a[i],&y);

int st=0;

for(int j=1;j<=y;j++){

scanf("%d",&c[j]);

v[c[j]]++;

st+=(1<<(c[j]-1));

}

b[i]=st;

}

tar=0;

for(int i=1;i<=n;i++){

tar+=(1<<(i-1));

if(v[i]==0){

printf("-1");

return 0;

}

}

d[0]=0;

for(int i=0;i<=tar;i++){

for(int j=1;j<=m;j++){

if(d[i|b[j]]>d[i]+a[j]){

d[i|b[j]]=d[i]+a[j];

}

}



}

printf("%lld",d[tar]);

}