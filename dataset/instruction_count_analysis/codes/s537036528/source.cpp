#include<cstdio>

using namespace std;

int K,N,ans;

int main(){

	scanf("%d%d",&N,&K);

	if(K==2)ans=N-1;

	else if(K>=N)ans=1;

	else {

		N-=K;

		ans=1;

		if(N%(K-1)==0)ans+=N/(K-1);

		else ans+=N/(K-1)+1;

	}

	printf("%d",ans);

}