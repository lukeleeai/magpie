#include "stdc++.h"

using namespace std;

#define ll long long

#define N 100010

int n,X,Y,Z,a[N],b[N],c[N],id[N];

ll ans,tmp,s1[N],s2[N];

priority_queue<int,vector<int>,greater<int> >q;

inline char gc(){

    static char *S,*T,buf[1<<16];

    if(T==S){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}

    return *S++;

}

inline int read(){

    int x=0,f=1;char ch=gc();

    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=gc();}

    while('0'<=ch && ch<='9') x=x*10+ch-'0',ch=gc();

    return x*f;

}

inline bool cmp(int x,int y){return a[x]-b[x]>a[y]-b[y];}

int main(){

	X=read();Y=read();Z=read();n=X+Y+Z;

	for(int i=1;i<=n;++i){

		a[i]=read();b[i]=read();c[i]=read();

		id[i]=i;tmp+=b[i];

	}

	sort(id+1,id+n+1,cmp);

	for(int i=1;i<=X;++i){

		s1[i]=s1[i-1]+a[id[i]]-b[id[i]];

		q.push(a[id[i]]-c[id[i]]);

	}

	for(int i=X+1;i<=X+Z;++i){

		s1[i]=s1[i-1]+c[id[i]]-b[id[i]];

		if(a[id[i]]-c[id[i]]>q.top()){

			int x=q.top();q.pop();

			q.push(a[id[i]]-c[id[i]]);

			s1[i]+=-x+a[id[i]]-c[id[i]];

		}

	}

	while(!q.empty()) q.pop();

	for(int i=n;i>=n-Y+1;--i){

//		s2[i]=s2[i-1]+c[id[i]]-b[id[i]];

		q.push(b[id[i]]-c[id[i]]);

	}

	for(int i=n-Y;i>=X+1;--i){

		s2[i]=s2[i+1]+c[id[i]]-b[id[i]];

		if(b[id[i]]-c[id[i]]>q.top()){

			int x=q.top();q.pop();

			q.push(b[id[i]]-c[id[i]]);

			s2[i]+=-x+b[id[i]]-c[id[i]];

		}

	}

	for(int i=X;i<=X+Z;++i){

		ans=max(ans,tmp+s1[i]+s2[i+1]);

	}

	printf("%lld\n",ans);

	return 0;

}