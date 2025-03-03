#include<stdio.h>

#include<algorithm>

using namespace std;

long long a[200010];

int t[200010];

int main()

{

    int n;

    long long ans=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%lld",&a[i]);

    sort(a,a+n);

    t[n-1]=1;int j=n-1;

    for(int i=1;i<n;i++)

    {

    	if(t[j]==2)j--;

    	ans+=a[j];t[j]++;

    	

	}

	printf("%lld ",ans);

    return 0;

}