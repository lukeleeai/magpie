#include <cstdio>

#include <algorithm>



using std::min;

using std::max;



const int MAXN=100111;

const int INF=1034567890;



int N;



struct Vert{

	int FE;

	int Size, Val;

} V[MAXN];



struct Edge{

	int y, c, next;

} E[MAXN<<1];



int Ecnt;



void addE(int a, int b, int c){

	++Ecnt;

	E[Ecnt].y=b;E[Ecnt].c=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;

}



void getSize(int at, int f=0){

	V[at].Size=1;

	for(int k=V[at].FE, to;k;k=E[k].next){

		to=E[k].y;

		if(to==f)	continue;

		getSize(to, at);

		V[at].Size+=V[to].Size;

	}

}



void getVal(int at, int f=0){

	V[at].Val=N-V[at].Size;

	for(int k=V[at].FE, to;k;k=E[k].next){

		to=E[k].y;

		if(to==f)	continue;

		getVal(to, at);

		V[at].Val=max(V[at].Val, V[to].Size);

	}

}



int getG(int at, int f=0){

	int ret=at;

	for(int k=V[at].FE, to;k;k=E[k].next){

		to=E[k].y;

		if(to==f)	continue;

		to=getG(to, at);

		if(V[to].Val<V[ret].Val)	ret=to;

	}

	return ret;

}



long long Calc(bool &v){

	long long ret=0LL;

	for(int i=1, s;i<=Ecnt;i+=2){

		s=min(V[E[i].y].Size, V[E[i+1].y].Size);

		ret+=2LL*min(s, N-s)*E[i].c;

		if(s==N-s)	{ret-=(long long)(E[i].c);v=true;}

	}

	return ret;

}



int main(){

	

	scanf("%d", &N);

	

	for(int i=1, a, b, c;i<N;++i){

		scanf("%d%d%d", &a, &b, &c);

		addE(a, b, c);addE(b, a, c);

	}

	

	int at=1;

	getSize(at);getVal(at);at=getG(at);

	

	bool v=false;

	long long Ans=Calc(v);

	if(!v){

		int m=INF;

		for(int k=V[at].FE;k;k=E[k].next)	m=min(m, E[k].c);

		Ans-=(long long)m;

	}

	

	printf("%lld\n", Ans);

	

	return 0;

}