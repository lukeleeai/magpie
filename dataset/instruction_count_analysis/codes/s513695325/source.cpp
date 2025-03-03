#include<cstdio>

#include<iostream>

#include<cmath>

#include<algorithm>



typedef long long ll;



const ll INF=1E9+10;

const ll MAXN=1e5+10;

using namespace std;



ll par[2*MAXN]; 



struct NODE{

	ll len,a,b;

}node[2*MAXN];



struct NO{

	ll sit,order;

}x[MAXN],y[MAXN];



ll rk[MAXN];



bool cmp1(NO i,NO j){

	return i.sit<j.sit;

}

bool cmp2(NODE h,NODE k){

	return h.len<k.len;

}





ll find(ll a){//寻找根节点 

	if(rk[a]==a)	return a;

	else {

		rk[a]=find(rk[a]);

		return rk[a];

	} 

} 



ll Kruskal(ll ver,ll edge){//顶点数量、边数 

	ll tot=0,e=0;//目前的权值和已加入的边数

	

	//初始化前驱 

	for(ll i=1;i<=ver;i++){

		rk[i]=i;//最开始第i个顶点的集合是他自己 

	}

	

	for(ll i=1;i<=edge&&e<ver-1;i++){

		ll h=find(node[i].a);//a点根节点 

		ll k=find(node[i].b);//b点根节点 

		if(h!=k){//如果这两个点不在同一个集合中，说明可以加入这条边 

			tot+=node[i].len;//增加权值 

			e++;//增加边数 

			rk[h]=k; //合并这两个点到同一个集合 

		}

	}

	 

	return tot; 

}



 int main() {

 	ll n;

 	scanf("%lld",&n);

 	for(ll i=1;i<=n;i++){

 		scanf("%lld %lld",&x[i].sit,&y[i].sit);

 		x[i].order=i;

 		y[i].order=i;

	}

	sort(x+1,x+n+1,cmp1);

	sort(y+1,y+n+1,cmp1);

	 

	//一共有2*n-2条边从 1到2*n-2 

	for(ll i=1;i<n;i++){

		node[i].len=x[i+1].sit-x[i].sit;

		node[i].a=x[i+1].order;node[i].b=x[i].order;

		

		node[i+n-1].len=y[i+1].sit-y[i].sit;

		node[i+n-1].a=y[i+1].order;node[i+n-1].b=y[i].order;

	}

	

	sort(node+1,node+2*n-1,cmp2);

	

	//克鲁斯卡尔算法 

	ll ans=Kruskal(n,2*n-2);//顶点数量、边数 

	printf("%lld\n",ans);

	

 	return 0;

 }