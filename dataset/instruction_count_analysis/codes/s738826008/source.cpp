#include<cstring>

#include<algorithm>

#include<cstdio>

#define N 100005

using namespace std;

long long int a[30],b[30];

long long int x,y;

int la=0,lb=0;

int main(){

scanf("%lld%lld",&x,&y);

a[++la]=1;

b[++lb]=1;

for(long long int i=2;i*i<=x;i++){

if(x%i==0){a[++la]=i;}

while(x%i==0){x/=i;}

}

if(x>1)a[++la]=x;

for(long long int i=2;i*i<=y;i++){

if(y%i==0){b[++lb]=i;}

while(y%i==0){y/=i;}

}

if(y>1)b[++lb]=y;

int z=1;

int ans=0;

for(int i=1;i<=la;i++){

while(b[z]<a[i]&&z<lb)z++;

if(b[z]==a[i])ans++;

}

printf("%d",ans);



}