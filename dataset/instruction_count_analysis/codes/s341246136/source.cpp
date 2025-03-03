#include<cstdio>

#include<algorithm>

using namespace std;

int a[105],b[105];

int father[105];

int n,m,s,ans=0;

int find(int x){

    if(father[x]!=x)father[x]=find(father[x]);

    return father[x];

}

void unionn(int x,int y){

    x=find(x);y=find(y);

    father[y]=x;

}

void init(int n){

	for(int i=1;i<=n;i++)father[i]=i;

}

int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++){

		scanf("%d%d",&a[i],&b[i]);

	}

	for(int i=1;i<=m;i++){

		init(n);

		for(int j=1;j<=m;j++){

			if(i!=j){

				unionn(a[j],b[j]);

			}

		}

		s=find(1);

		for(int j=2;j<=n;j++){

			if(find(j)!=s){

				ans++;

				break;

			}

		}

	}

	printf("%d",ans);

	return 0;

}
