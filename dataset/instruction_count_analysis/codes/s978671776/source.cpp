#include<cstdio>

#include<algorithm>

#include<cstring>

#define MN 30005

using namespace std;

int n,num,ans[MN];

int main(){

	scanf("%d",&n);

	if(n==3){puts("2 5 63");}

	else {

		ans[++num]=2;ans[++num]=4;

		for(int i=6;num+2<=n&&i+3<=30000;i+=12)ans[++num]=i-3,ans[++num]=i+3;

		for(int i=6;num+2<=n&&i+4<=30000;i+=6)ans[++num]=i+2,ans[++num]=i+4;

		for(int i=6;num+1<=n&&i<=30000;i+=6)ans[++num]=i;

		for(int i=1;i<=num;i++)printf("%d ",ans[i]);

	}

}


