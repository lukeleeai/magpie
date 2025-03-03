#include <cstdio>

#include <algorithm>

using namespace std;

 

const int maxn=1e5+5;

 

int n,rk,L,T;

int pos[maxn];

 

int read() {

	int x=0,f=1;char ch=getchar();

	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;

	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';

	return x*f;

}

 

int main() {

	n=read(),L=read(),T=read();

	for(int i=1;i<=n;i++) {

		int x=read(),w=read();

		if(w==2)pos[i]=x-T;

		else pos[i]=x+T;

		rk+=pos[i]/L;

		if(pos[i]%L<0)rk--;

		pos[i]=(pos[i]%L+L)%L;

	}

	sort(pos+1,pos+n+1);

	rk=(rk%n+n)%n;

	for(int i=rk+1;i<=n;i++)

		printf("%d\n",pos[i]);

	for(int i=1;i<=rk;i++)

		printf("%d\n",pos[i]);

	return 0;

}
