#include<cstdio>

#include<algorithm>

using namespace std;

struct node{

	int b,num;

}q[200010];

long long a[200010];

int cmp(const node&x,const node&y)

{

	if(x.b!=y.b)

	 return x.b<y.b;

	return x.num<y.num;

}

int main()

{

	int n,i,l;

	long long k,ans=0;

	scanf("%d%lld",&n,&k);

	for(i=1;i<=n;i++)

	 {

	 	scanf("%lld",&a[i]);

	 	a[i]+=a[i-1];

	 	q[i].b=(((a[i]-i)%k)+k)%k;

	 	q[i].num=i;

	 }

	sort(q+1,q+n+1,cmp);

	l=0;

	for(i=1;i<=n;i++)

	 if(q[i].b==q[i-1].b)

	  {

	  		while(q[i].num-q[l].num>=k)

	  		 l++;

	  		ans+=i-l;

	  }

	else

	 l=i;

	printf("%lld",ans);

	return 0;

}