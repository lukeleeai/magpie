#include<cstdio>

#include<algorithm>

using namespace std;

int x[100000],a,n,q;

int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++)scanf("%d",&x[i]);

	scanf("%d",&q);x[n]=1<<30;int cnt=0;

	for(int i=0;i<q;i++){

		scanf("%d",&a);

		int pos=lower_bound(x,x+n,a)-x;

		if(x[pos]==a)cnt++;

	}

	printf("%d\n",cnt);

	return 0;

}