#include "stdc++.h"



const int maxn=2e5+10;



int n,m,cnt;

int F[maxn];

int cost[maxn];

std::vector<int> right[maxn];



int minv[maxn<<2];

int get(int r,int L,int R,int Lu,int Ru){

	if (L>Ru||R<Lu)return 0x3F3F3F3F;

	if (L>=Lu&&R<=Ru)return minv[r];

	int Mid=(L+R)>>1;

	return std::min(get(r<<1,L,Mid,Lu,Ru),get(r<<1|1,Mid+1,R,Lu,Ru));

}



void insert(int r,int L,int R,int p,int v){

	if (L==R)return minv[r]=v,void();

	int Mid=(L+R)>>1;

	if (p<=Mid)insert(r<<1,L,Mid,p,v);

	else insert(r<<1|1,Mid+1,R,p,v);

	minv[r]=std::min(minv[r<<1],minv[r<<1|1]);

}



int main (){

#ifdef LOCAL

	freopen("input","r",stdin);

#endif

	std::cin >> n;

	for (int i=1,x;i<=n;i++){

		std::cin >> x;

		cnt+=(x==0);

		cost[i]=x>0?1:-1;

	}

	std::cin >> m;

	for (int i=1,L,R;i<=m;i++){

		std::cin >> L >> R;

		right[L].push_back(R);

	}

	memset(F,0x3F,sizeof(F));

	memset(minv,0x3F,sizeof(minv));

	F[0]=0;

	for (int i=1,tmp;i<=n;i++){

		F[i]=std::min(F[i],F[i-1]+cost[i]);

		for (int R:right[i]){

			tmp=std::min(F[i-1],get(1,1,n,std::max(i-1,1),R));

			if (tmp<F[R])

				insert(1,1,n,R,F[R]=tmp);

		}

	}

	std::cout << F[n]+cnt << '\n';

	return 0;

}


