#include<cstdio>



#include<cstring>

#include<algorithm>

#define ll long long

#define MAXN 100000005



using namespace std;







struct TH{

	ll w,v;

}th[105];



ll v1[105],v2[105],v3[105],v4[105];



int cnt1=0,cnt2=0,cnt3=0,cnt4=0; 



bool cmp(ll a,ll b){

	return a>b;

}



int main(){

	ll n,w;

	scanf("%lld %lld",&n,&w);

	for(int i=1;i<=n;i++){

		scanf("%lld %lld",&th[i].w,&th[i].v);

		if(i==1){

			v1[++cnt1]=th[i].v;

			continue;

		}

		//以w[1]为基准， 把所有价值分为4类 

		int con=th[i].w-th[1].w;

		switch(con){//从1开始存放 

			case 0:v1[++cnt1]=th[i].v;break;

			case 1:v2[++cnt2]=th[i].v;break;

			case 2:v3[++cnt3]=th[i].v;break;

			case 3:v4[++cnt4]=th[i].v;break;

		}

	}

	//所有价值从大到小排序 

	sort(v1+1,v1+cnt1+1,cmp);

	sort(v2+1,v2+cnt2+1,cmp);

	sort(v3+1,v3+cnt3+1,cmp);

	sort(v4+1,v4+cnt4+1,cmp);

	//每种类型的物品价值叠加 

	for(int i=2;i<=cnt1;i++){

		v1[i]+=v1[i-1];

	} 

	for(int i=2;i<=cnt2;i++){

		v2[i]+=v2[i-1];

	} 

	for(int i=2;i<=cnt3;i++){

		v3[i]+=v3[i-1];

	} 

	for(int i=2;i<=cnt4;i++){

		v4[i]+=v4[i-1];

	} 

	ll ans=0;

	for(int i=0;i<=cnt1;i++){

		for(int j=0;j<=cnt2;j++){

			for(int k=0;k<=cnt3;k++){

				for(int h=0;h<=cnt4;h++){

					if(th[1].w*(i)+(th[1].w+1)*(j)+(th[1].w+2)*(k)+(th[1].w+3)*(h)<=w){

						ans=max(ans,v1[i]+v2[j]+v3[k]+v4[h]);

					}

				}

			}

		}

	}

	printf("%lld",ans);

	return 0;

} 