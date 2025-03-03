#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define MN 1000005

using namespace std;

typedef long long ll;

int k,tt;

ll ans[MN];

int calc(ll num){int tot=0;while(num)tot+=num%10,num/=10;return tot;}

int main(){

	scanf("%d",&k);

	for(int i=1;i<=9;i++)ans[++tt]=i;ans[++tt]=19;ll lst=19;

	while(tt<k){

		int tmp=calc(lst);ll add=1;

		while((lst+add)*calc(lst+add*2)>(lst+2*add)*calc(lst+add))add*=10;

		lst+=add;ans[++tt]=lst;

	}for(int i=1;i<=k;i++)printf("%lld\n",ans[i]);

}
