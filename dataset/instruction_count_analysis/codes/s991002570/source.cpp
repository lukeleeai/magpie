#include<cstdio>

#include<set>

typedef unsigned long long ull;

const int MaxN=200010,B=1000000007;

int N,K,P[MaxN];

ull pw[MaxN],H[MaxN];

struct info{

	int s;ull h;

	info operator+(const info&i)const{

		return(info){s+i.s,h+i.h*pw[s]};

	}

}T[1<<19];

#define Def int o,int L,int R

#define Mid (L+R>>1)

#define Ls o<<1,L,Mid

#define Rs o<<1|1,Mid,R

void modify(Def,int i,int x){

	if(R-L==1){

		T[o]=(info){x,i*x};

		return;

	}

	i<Mid?modify(Ls,i,x):modify(Rs,i,x);

	T[o]=T[o<<1]+T[o<<1|1];

}

int main(){

	scanf("%d%d",&N,&K);

	for(int i=0;i<N;i++)scanf("%d",P+i);

	for(int i=*pw=1;i<=N;i++)pw[i]=pw[i-1]*B;

	for(int i=0;i<N;i++)H[i+1]=H[i]+P[i]*pw[i];

	std::set<ull>st;

	for(int l=0,r=K;r<=N;l++,r++){

		if(!l){

			for(int i=0;i<K;i++)modify(1,0,N,P[i],1);

		}

		else{

			modify(1,0,N,P[l-1],0);

			modify(1,0,N,P[r-1],1);

		}

		st.insert(H[l]+H[N]-H[r]+T[1].h*pw[l]);

	}

	printf("%d\n",st.size());

}