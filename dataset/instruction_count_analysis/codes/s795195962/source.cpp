#include"stdc++.h"

#define N (100005)

#define ll long long

#define itn int

#define scafn scanf

#define debug(x) cerr<<#x<<" : "<<x<<endl

#define CM cerr<<(&MOP2-&MOP1)/1024.0/1024.0<<endl

using namespace std;

template <class T> inline T Min(T x, T y){

    return x<y?x:y;

}

template <class T> inline T Max(T x, T y){

    return x>y?x:y;

}

bool MOP1;

int n,m;

struct node{

	int cost,val;

	bool operator < (const node &a)const{

		return val==a.val?cost>a.cost:val>a.val;

	}

	void read(){

		scanf("%d%d",&cost,&val);

	}

	void deb(){

		printf("%d %d\n",cost,val);

	}

}A[N];

int f[N];

int find(int x){

	return f[x]==x?x:f[x]=find(f[x]);

}

int ans;

bool MOP2;

int main(){	

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)A[i].read();

	for(int i=1;i<=m+1;i++)f[i]=i;

	sort(A+1,A+1+n);

//	for(int i=1;i<=n;i++)A[i].deb();

	for(int i=1;i<=n;i++){

		int c=A[i].cost;

		int v=A[i].val;

		if(c>m)continue;

		int now=find(f[c]);

		if(now>m)continue;

		ans+=v,f[now]++;

	}

	printf("%d\n",ans);

	return 0;

}








