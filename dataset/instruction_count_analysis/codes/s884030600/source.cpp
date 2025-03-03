#include<cstdio>

#include<vector>

const int MaxN=1<<17|10;

int N,ch[MaxN][2],v[MaxN];

long long dep[MaxN];

struct Point{long long x,y;};

void ins(std::vector<Point>&v,long long x,long long y){

	if(!v.size()||y<v[v.size()-1].y)v.push_back((Point){x,y});

}

void find(std::vector<Point>&v,int&p,long long M){

	while(p<v.size()&&v[p].x<=M)p++;

}

std::vector<Point>chk(int i,long long M){

	std::vector<Point>f;

	if(!*ch[i]){

		f.push_back((Point){dep[i],dep[i]});

		return f;

	}

	std::vector<Point>fl=chk(ch[i][0],M),fr=chk(ch[i][1],M);

	for(int pl=0,pr=0,ql=0,qr=0;;pl++){

		for(;pr<fr.size()&&(pl>=fl.size()||fr[pr].x<fl[pl].x);pr++){

			find(fl,ql,M+2*dep[i]-fr[pr].y);

			if(ql)ins(f,fr[pr].x,fl[ql-1].y);

		}

		if(pl>=fl.size())break;

		find(fr,qr,M+2*dep[i]-fl[pl].y);

		if(qr)ins(f,fl[pl].x,fr[qr-1].y);

	}

	return f;

}

int main(){

	scanf("%d",&N);

	for(int i=2,f;i<=N;i++){

		scanf("%d%d",&f,v+i);

		if(*ch[f])ch[f][1]=i;

		else ch[f][0]=i;

		dep[i]=dep[f]+v[i];

	}

	long long l=-1,r=1ll<<34,mid;

	while(r-l>1)chk(1,mid=l+r>>1).size()?r=mid:l=mid;

	printf("%lld\n",r);

}