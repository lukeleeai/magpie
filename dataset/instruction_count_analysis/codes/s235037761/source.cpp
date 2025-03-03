#include<cstdio>

#include<cstring>

#include<algorithm>



#define N 100010



int a[N];



long long Find(int x){

	return a[x]==x? a[x]:Find(a[x]);

}



int main(){

	while(true){

		int n,q;

		scanf("%d%d",&n,&q);

		if(!(n||q))

			break;

		a[1]=1;

		for(int i=2;i<=n;i++)

			scanf("%d",a+i);

		long long ans=0ll;

		while(q--){

			char tmp[10]={};

			int x;

			scanf("%s%d",tmp,&x);

			if(*tmp=='Q')

				ans+=Find(x);

			else

				a[x]=x;

		}

		printf("%lld\n",ans);

	}

	return 0;

}
