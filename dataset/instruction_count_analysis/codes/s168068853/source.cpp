#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define SF scanf

#define PF printf

#define MAXN 200010

#define x first

#define y second

using namespace std;

typedef long long ll;

pair<int,int> p[MAXN];

const double Pi=acos(-1);

int xl,yl,xr,yr;

int fx,fy;

int n;

int st[MAXN];

int main(){

	SF("%d%d%d%d",&xl,&yl,&xr,&yr);

	if(xl>xr)

		fx=-1;

	else

		fx=1;

	if(yl>yr)

		fy=-1;

	else

		fy=1;

	xl*=fx,xr*=fx,yl*=fy,yr*=fy;

	SF("%d",&n);

	for(int i=1;i<=n;i++){

		SF("%d%d",&p[i].x,&p[i].y);

		p[i].x*=fx;

		p[i].y*=fy;

		if(p[i].x<xl||p[i].x>xr||p[i].y<yl||p[i].y>yr){

			n--;

			i--;

			continue;

		}

	}

	sort(p+1,p+1+n);

	int top=0;

	for(int i=1;i<=n;i++){

		if(top==0||st[top]<p[i].y)

			st[++top]=p[i].y;

		else{

			int pos=lower_bound(st+1,st+1+top,p[i].y)-st;

			st[pos]=p[i].y;	

		}

	}

	double ans=(xr-xl)*100.0+(yr-yl)*100.0;

	ans=ans+(double)top*(Pi*5.0-20.0);

	if(top==min(xr-xl+1,yr-yl+1))

		ans+=Pi*5;

	PF("%.11lf",ans);

}