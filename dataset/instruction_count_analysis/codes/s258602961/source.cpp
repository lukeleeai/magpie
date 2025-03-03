#include<cstdio>

#include<algorithm>

#define ll long long





using namespace std;



const ll MAXN=1e5+10;



struct V{

	ll x,order;

}vx[MAXN],vy[MAXN];



struct Edge{

	int va,vb;

	ll w;

}e[2*MAXN];



int pre[MAXN];



void init(int n){

	for(int i=1;i<=n;i++){

		pre[i]=i;

	}

}



bool cmpv(V a,V b){

	return a.x<b.x;

}

bool cmpe(Edge a,Edge b){

	return a.w<b.w;

}



int find(int v){

	if(pre[v]==v){

		return v;

	}

	else {

		pre[v]=find(pre[v]);

		return pre[v];

	}

}



ll Kruskal(int ver,int edges){

	ll tot=0,ale=0;//权重和已加入的顶点数 

	init(ver);

	for(int i=1;i<=edges&&ale<ver-1;i++){

		 int h=find(e[i].va);

		 int k=find(e[i].vb);

		 if(h!=k){

		 	tot+=e[i].w;//增加权重 

		 	ale++;//增加边 

		 	pre[h]=k;//加入集合 

		 } 

	}

	return tot; 

	

}



int main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%lld %lld",&vx[i].x,&vy[i].x);

		vx[i].order=vy[i].order=i;

	}

	sort(vx+1,vx+n+1,cmpv);

	sort(vy+1,vy+n+1,cmpv);

	for(int i=1;i<n;i++){

		e[i].w=vx[i+1].x-vx[i].x;

		e[i].va=vx[i+1].order,e[i].vb=vx[i].order;

		

		e[i+n-1].w=vy[i+1].x-vy[i].x;

		e[i+n-1].va=vy[i+1].order,e[i+n-1].vb=vy[i].order;

	}

	//对边长按权重排序 

	sort(e+1,e+2*n-1,cmpe);

	//Kruskal算法 找最小生成树 

	ll ans=Kruskal(n,2*n-2);

	printf("%lld",ans);

	return 0;

}

 