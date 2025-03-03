//from Kuugo

#include"stdc++.h"

using namespace std;

#define N 1111116

 

int w,h,n,l[N],r[N],f[N],g[N],ans;

 

struct node{int x,y;}a[N];

vector<node> ql,qr;

bool cmp(node a,node b){return a.y<b.y;}

 

void build(int t,int x,int y){

	l[t]=x;r[t]=y;f[t]=0;g[t]=0;

	if (x==y){f[t]=w-a[x].y;return;}

	build(2*t,x,(x+y)/2);

	build(2*t+1,(x+y)/2+1,y);

	f[t]=max(f[2*t],f[2*t+1]);

}

 

void modify(int t,int x,int y,int z){

	if (x<=l[t]&&y>=r[t]) {f[t]+=z;g[t]+=z;return;};

	if (x<=r[2*t]) modify(2*t,x,y,z);

	if (y>=l[2*t+1]) modify(2*t+1,x,y,z);

	f[t]=max(f[2*t],f[2*t+1])+g[t];

}

 

void solve(){

	sort(a+1,a+n+1,cmp);

	build(1,0,n);

	ql.clear();ql.push_back((node){0,-1});ql.push_back((node){0,0});

	qr.clear();qr.push_back((node){w,-1});qr.push_back((node){w,0});

	for (int i=1;i<=n;i++){

		ans=max(ans,(f[1]+a[i].y)*2);

		if (a[i].x<=w/2){

			for (int j=ql.size()-1;j&&ql[j].x<=a[i].x;ql.pop_back(),j--)

				modify(1,ql[j-1].y+1,ql[j].y,ql[j].x-a[i].x);

			ql.push_back((node){a[i].x,i-1});

		}

		else {

			for (int j=qr.size()-1;j&&qr[j].x>=a[i].x;qr.pop_back(),j--)

				modify(1,qr[j-1].y+1,qr[j].y,a[i].x-qr[j].x);

			qr.push_back((node){a[i].x,i-1});

		}

		ql.push_back((node){0,i});

		qr.push_back((node){w,i});

	}

	ans=max(ans,(f[1]+h)*2);

}

 

int read(){

	int x=0,f=1;char ch=getchar();

	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;

	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';

	return x*f;

}

 

int main(){

	w=read();h=read();n=read();

	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();

	solve();

	for (int i=1;i<=n;i++) swap(a[i].x,a[i].y);

	swap(h,w);solve();

	printf("%d\n",ans);

	return 0;

}