#include <stdio.h>

#include <queue>

#include <vector>

#include <iostream>

#include <algorithm>

#define R register

namespace IO{

	char buf[1<<15],*S,*T;

	inline char gc(){

		if (S==T){

			T=(S=buf)+fread(buf,1,1<<15,stdin);

			if (S==T) return EOF;

		}return *S++;

	}

	inline int read(){

		R int x; R bool f; R char c;

		for (f=0; (c=gc())<'0'||c>'9'; f=c=='-');

		for (x=c^'0'; (c=gc())>='0'&&c<='9'; x=(x<<3)+(x<<1)+(c^'0'));

		return f?-x:x;

	}

}

#define MN 200005

std::priority_queue<int,std::vector<int>,std::greater<int> > pq;

struct sth{

	int l,r;

	inline bool operator < (const sth &a)const{

		return l<a.l;

	}

}a[MN];

int n,m,r[MN],lb,ans,cnt;

int main(){

	n=IO::read(),m=IO::read();

	for (R int i=1; i<=n; ++i)

		a[i].l=IO::read(),a[i].r=IO::read(),++r[a[i].r];

	std::sort(a+1,a+n+1);

	for (R int i=1,j=1; i<=m&&j<=n; ++i){

		for (;a[j].l<i&&j<=n;++j)

			if (!pq.empty()&&a[j].r>pq.top()) pq.pop(),pq.push(a[j].r);

		if (j>n) break;pq.push(a[j].r);++j;lb=i;

	}while(!pq.empty()) --r[pq.top()],pq.pop();

	ans=r[m+1];

	for (R int i=m; i>lb; --i){

		++cnt;

		if (cnt<r[i]) ans+=r[i]-cnt,cnt=0;

		else cnt-=r[i];

	}for (R int i=lb; i; --i)

		if (cnt<r[i]) ans+=r[i]-cnt,cnt=0;

		else cnt-=r[i];

	printf("%d\n",ans);return 0;

}