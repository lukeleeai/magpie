#include<set>

#include<map>

#include<cmath>

#include<queue>

#include<bitset>

#include<string>

#include<cstdio>

#include<cctype>

#include<cstdlib>

#include<cstring>

#include<cassert>

#include<sstream>

#include<numeric>

#include<iostream>

#include<algorithm>

#include<functional>



#define For(i,x,y) for (int i=x;i<y;i++)

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define Lsn (x<<1)

#define Rsn (x<<1|1)

#define Mid ((L+R)>>1)



#define dprintf(...) fprintf(stderr,__VA_ARGS__)

using namespace std;



typedef long long ll;

typedef double db;

typedef vector<int> Vi;

typedef pair<int,int> pii;



int IN(){

	int c,f,x;

	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');

	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;

}

void Output(int x){

	if (x>=10) Output(x/10);

	putchar(x%10+'0');

}



const int N=500000+19;

const int oo=(1<<30)-1;



priority_queue<int> Q;

int A[N],d[N],C[N],res[N];

int n,k;



int Query(int x){

	int res=0;

	for (;x;x-=x&-x) res+=C[x];

	return res;

}

void Add(int x){

	for (;x<=n;x+=x&-x) C[x]++;

}



pii mn[N*4];

int plu[N*4];

int Ql,Qr;



void Build(int x,int L,int R){

	if (L==R){

		mn[x]=mp(d[L],-L);

		return;

	}

	Build(Lsn,L,Mid);

	Build(Rsn,Mid+1,R);

	mn[x]=min(mn[Lsn],mn[Rsn]);

}

void Plus(int x,int v){

	plu[x]+=v;

	mn[x].fi+=v;

}

void Down(int x){

	if (plu[x]){

		Plus(Lsn,plu[x]);

		Plus(Rsn,plu[x]);

		plu[x]=0;

	}

}

void Modify(int x,int L,int R){

	if (Ql<=L&&R<=Qr){

		Plus(x,-1);

		return;

	}

	Down(x);

	if (Ql<=Mid) Modify(Lsn,L,Mid);

	if (Qr>Mid) Modify(Rsn,Mid+1,R);

	mn[x]=min(mn[Lsn],mn[Rsn]);

}

void Change(int x,int L,int R){

	if (L==R){

		mn[x]=mp(oo,-L);

		return;

	}

	Down(x);

	Ql<=Mid?Change(Lsn,L,Mid):Change(Rsn,Mid+1,R);

	mn[x]=min(mn[Lsn],mn[Rsn]);

}



int main(){

	n=IN(),k=IN()-1;

	For(i,1,n+1) A[IN()]=i;

	for (int i=n;i;i--){

		d[A[i]]=Query(min(A[i]+k,n))-Query(max(A[i]-k,1)-1);

		Add(A[i]);

	}

	For(i,1,n+1){

		if (!d[i]) Q.push(i),d[i]=oo;

	}

	Build(1,1,n);

	For(t,1,n+1){

		int x=Q.top();Q.pop();

		res[x]=n-t+1;

		Ql=max(x-k,1);

		Qr=min(x+k,n);

		Modify(1,1,n);

		while (mn[1].fi==0){

			Q.push(-mn[1].se);

			Ql=-mn[1].se;

			Change(1,1,n);

		}

	}

	For(i,1,n+1){

		Output(res[i]);

		puts("");

	}

}