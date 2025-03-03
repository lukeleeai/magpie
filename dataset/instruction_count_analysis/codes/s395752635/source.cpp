#include<cstdio>

using namespace std;

#define N 100005

#define LL long long

#define rep(i,j,k) for(i=j;i<=k;++i)

#define down(i,j,k) for(i=j;i>=k;--i)

int n,m,i,j,k,top;

LL cnt[N],xs[N],q[N];

LL len,t;

void read(int &p){

	p=0; char x=getchar();

	while(x<'0' || x>'9') x=getchar();

	while(x>='0'&&x<='9'){p=p*10+x-'0';	x=getchar();}

}

void read(LL &p){

	p=0; char x=getchar();

	while(x<'0' || x>'9') x=getchar();

	while(x>='0'&&x<='9'){p=p*10+x-'0';	x=getchar();}

}

int find(int l,int r,LL x){

	int mid;

	while(l<r){

		if(r-l>1) mid=(l+r)>>1;

		else mid=r;

		if(q[mid]<x) l=mid;

		else r=mid-1;

	}

	return l;

}

int main(){

	

	read(n); read(m);

	top=1; q[1]=n;

	rep(i,1,m){

		read(len);

		while((top)&&(q[top]>=len)) top--;

		top++; q[top]=len;

	}

	m=top;

	xs[m]=1;

	while(top>1){

		len=q[top]; k=top-1;

		while(len>=q[1]){

			t=len/q[k];

			xs[k]+=xs[top]*t;

			len=len%q[k];

			if(len>=q[1]) k=find(1,k,len);

		}

		cnt[len]+=xs[top];

		top--;

	}

	len=xs[1];

	down(i,n-1,1) cnt[i]+=cnt[i+1];

	rep(i,1,n)  

		if(i<=q[1]) printf("%lld\n",len+cnt[i]);

		else printf("0\n");

	return 0;

}