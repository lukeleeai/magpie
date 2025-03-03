#include"stdc++.h"

int X,k,q;

struct ev{

	int x,y,id;

	bool operator<(const ev&e)const{return x<e.x;}

}e[500007];

int ep=0,as[500007];

int main(){

	scanf("%d%d",&X,&k);

	for(int i=0,a;i<k;++i){

		scanf("%d",&a);

		e[ep++]=(ev){a,0,0};

	}

	scanf("%d",&q);

	for(int i=1,a,b;i<=q;++i){

		scanf("%d%d",&a,&b);

		e[ep++]=(ev){a,b,i};

	}

	std::sort(e,e+ep);

	long long mn=0,mx=X,a=0;

	for(int i=0,sgn=-1,t0=0;i<ep;++i){

		long long v0=(e[i].x-t0)*sgn;

		if(e[i].id){

			long long v=e[i].y+a;

			if(v<mn)v=mn;

			if(v>mx)v=mx;

			v+=v0;

			if(v<0)v=0;

			if(v>X)v=X;

			as[e[i].id]=v;

		}else{

			mn+=v0,mx+=v0,a+=v0;

			if(mn<0) mn=0;

			if(mx<0) mx=0;

			if(mx>X) mx=X;

			if(mn>X) mn=X; 

			t0=e[i].x;

			sgn*=-1;

		}

	}

	for(int i=1;i<=q;++i)printf("%d\n",as[i]);

	return 0;

} 