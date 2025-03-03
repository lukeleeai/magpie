#include<cstring>

#include<algorithm>

#include<cstdio>

#define N 100005

using namespace std;

struct ab{

int a,b;

};

ab a[N];

int cmp(ab x,ab y){

return x.a<y.a;

}

int n;

int main(){

scanf("%d",&n);

for(int i=1;i<=n;i++){

scanf("%d",&a[i].a);

a[i].b=i;

}

sort(a+1,a+n+1,cmp);

for(int i=1;i<=n;i++){

printf("%d ",a[i].b);

}

}