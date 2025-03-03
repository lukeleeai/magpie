#include "stdc++.h"

using namespace std;

typedef long long lli;



int n,a[200000],b[200000];

int main() {

	scanf("%d",&n);

	for(int i=0;i<n;i++)

		scanf("%d",a+i),b[i]=a[i];



	sort(b,b+n);

	for(int i=0;i<n;i++) {

		if(a[i]<=b[n/2-1]) printf("%d\n",b[n/2]);

		else printf("%d\n",b[n/2-1]);

	}



	return 0;

}