#include<cstdio>

inline int min(const int x,const int y){

	return x<y?x:y;

}

int h,n,f[10005],v[1005],c[1005];

int main(){

	scanf("%d%d",&h,&n);

	for(int i=1;i<=h;++i)f[i]=100000000;

	for(int i=1;i<=n;++i){

		scanf("%d%d",&v[i],&c[i]);

		for(int j=1;j<=h;++j){

			if(j<v[i])f[j]=

				min(f[j],c[i]);

			else f[j]=min(f[j],

				f[j-v[i]]+c[i]);

		}

	}

	return printf("%d\n",f[h]),0;

}