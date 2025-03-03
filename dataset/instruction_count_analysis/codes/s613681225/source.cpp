#include <cstdio>

#include <algorithm>

using namespace std;

#define N 100010

int n,l,t,cnt,a[N],w[N];

int main(){

	scanf("%d%d%d",&n,&l,&t);

	for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&w[i]);

	for(int i=1;i<=n;++i){

		int now=a[i];

		if(w[i]==2) w[i]=-1;

		a[i]+=t*w[i];

		cnt+=a[i]/l;

		if(a[i]%l<0) cnt--;

		a[i]=(a[i]%l+l)%l;

	}

	sort(a+1,a+n+1);

	cnt=(cnt%n+n)%n;

	for(int i=1;i<=n;++i) printf("%d\n",a[(i+cnt-1)%n+1]);

	return 0;

}