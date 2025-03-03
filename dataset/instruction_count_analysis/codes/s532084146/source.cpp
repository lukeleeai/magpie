#include "stdc++.h"



#define FOR(i,a,b) for(int i=a;i<b;i++)

#define REP(i,b) FOR(i,0,b)

#define MP make_pair



using namespace std;



using uint=unsigned int;

using ll=long long;



uint xor128(){

	static uint d[]={1145141919,1919810893,810893364,364114514};

	uint t=d[0]^(d[0]<<11);

	REP(i,3)

		d[i]=d[i+1];

	return d[3]=d[3]^(d[3]>>19)^(t^(t>>8));

}



struct Node{

	Node *l,*r;

	uint pri;

	int s,v,mn;

} buf[200000];



using NP=Node*;



NP newNode(int v){

	static int c=0;

	buf[c]=Node{NULL,NULL,xor128(),1,v,v};

	return &buf[c++];

}



const int inf=1145141919;



inline int Mini(NP x){

	return x?x->mn:inf;

}



inline int Size(NP x){

	return x?x->s:0;

}



inline NP Update(NP x){

	x->s=Size(x->l)+Size(x->r)+1;

	x->mn=min({x->v,Mini(x->l),Mini(x->r)});

	return x;

}



inline NP LinkL(NP x,NP l){

	x->l=l;

	return Update(x);

}



inline NP LinkR(NP x,NP r){

	x->r=r;

	return Update(x);

}



inline NP CutL(NP x){

	x->l=NULL;

	return Update(x);

}



inline NP CutR(NP x){

	x->r=NULL;

	return Update(x);

}



NP Merge(NP a,NP b){

	static pair<NP,bool> pl[128];

	int c=0;

	while(a&&b){

		if(a->pri>b->pri){

			pl[c++]=MP(a,true);

			a=a->r;

		}else{

			pl[c++]=MP(b,false);

			b=b->l;

		}

	}

	NP t=a?a:b;

	while(c){

		NP p=pl[--c].first;

		bool rch=pl[c].second;

		if(rch)

			LinkR(p,t);

		else

			LinkL(p,t);

		t=p;

	}

	return t;

}



using Res=Node;



Res Split(NP x,int k){

	if(k<=0)

		return Res{NULL,x};

	else if(x->s<=k)

		return Res{x,NULL};

	else if(k<=Size(x->l)){

		Res s=Split(x->l,k);

		return Res{s.l,Merge(s.r,CutL(x))};

	}else{

		Res s=Split(x->r,k-Size(x->l)-1);

		return Res{Merge(CutR(x),s.l),s.r};

	}

}



inline void Set(NP x,int k,int v){

	int ls=Size(x->l);

	if(k<ls)

		Set(x->l,k,v);

	else if(k==ls)

		x->v=v;

	else

		Set(x->r,k-ls-1,v);

	Update(x);

}



int read(){

	int i;

	scanf("%d",&i);

	return i;

}



NP t[200000];



int main(){

	int n=read(),q=read();

	REP(i,n)

		t[i]=newNode(read());

	while(n>1){

		int k=n/2;

		REP(i,k)

			t[i]=Merge(t[i*2],t[i*2+1]);

		if(k*2<n)

			t[k]=t[k*2];

		n=(n+1)/2;

	}

	NP root=t[0];

	REP(_,q){

		int x=read(),y=read(),z=read();

		if(x==0){

			Res s1=Split(root,y);

			Res s2=Split(s1.r,z+1-y-1);

			Res s3=Split(s2.r,1);

			root=Merge(Merge(s1.l,s3.l),Merge(s2.l,s3.r));

		}else if(x==1){

			Res s1=Split(root,y);

			Res s2=Split(s1.r,z+1-y);

			printf("%d\n",Mini(s2.l));

			root=Merge(s1.l,Merge(s2.l,s2.r));

		}else if(x==2){

			Set(root,y,z);

		}

	}

}