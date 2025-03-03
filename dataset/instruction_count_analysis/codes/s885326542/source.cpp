#include <cstdio>



const int Max = 100005;

int n,m,k;

int fa[Max],Size[Max],Du[Max];



int getfa(int x){

	if(fa[x] == x) return x;

	return fa[x] = getfa(fa[x]);

}



void Union(int x,int y){

	int Fx = getfa(x);

	int Fy = getfa(y);

	if(Fx == Fy) return;

	fa[Fx] = Fy;

	Size[Fy] += Size[Fx];

}



int main(){

	scanf("%d %d %d",&n,&m,&k);

	for(int i = 1; i <= n; i++){

		fa[i] = i;

		Size[i] = 1;

	}

	for(int i = 1; i <= m; i++){

		int x,y;

		scanf("%d %d",&x,&y);

		Du[x]++;

		Du[y]++;

		Union(x,y);

	}

	for(int i = 1; i <= k; i++){

		int x,y;

		scanf("%d %d",&x,&y);

		if( getfa(x) == getfa(y) ) Du[x]++,Du[y]++;

	}

	for(int i = 1; i <= n; i++){

		int Out = Size[getfa(i)] - 1 - Du[i];

		printf("%d ",Out);

	}

	return 0;

}