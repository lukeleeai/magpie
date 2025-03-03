#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN=1e6+5;

int n;

int a[MAXN],num[MAXN];

struct rec{

	int x,pos;

};

rec c1[MAXN],c2[MAXN];

bool comp(const rec &x,const rec &y){

	return x.x>y.x;

}

int main(){

	scanf("%d",&n);

	for (int i=1;i<=n;++i){

		scanf("%d",&a[i]); num[i]=a[i];

	}

	sort(num+1,num+1+n);

	int nn=unique(num+1,num+1+n)-num-1;

	for (int i=1;i<=n;++i) a[i]=lower_bound(num+1,num+1+nn,a[i])-num;

	for (int i=1;i<=n;++i){

		c1[i].pos=i; c2[i].pos=i;

	}

	for (int i=1;i<=n;++i)

		if (i%2==1) ++c1[a[i]].x; else ++c2[a[i]].x;

	

	sort(c1+1,c1+1+n,comp); sort(c2+1,c2+1+n,comp);

	if (c1[1].pos==c2[1].pos) printf("%d",min(n-c1[1].x-c2[2].x,n-c1[2].x-c2[1].x)); else printf("%d",n-c1[1].x-c2[1].x);

}