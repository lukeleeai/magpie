#include <stdio.h>

int n,a[100005],b[100005];

int ans=0;

inline void smax(int &a,int b){b>a?a=b:0;}

inline void test(int x,int y) {

	if(x!=y) smax(ans,a[x]+b[y]);

}

int main() {

	int x,f1=0,f2=0,g1=0,g2=0;

	scanf("%d",&n);n/=2;

	for(int i=0;i<n;++i) {

		scanf("%d",&x);++a[x];

		scanf("%d",&x);++b[x];

	}

	for(int i=1;i<=100000;++i) {

		if(a[i]>a[g1]) {

			if(a[i]>=a[f1]) {

				g1=f1;f1=i;

			} else {

				g1=i;

			}

		}

		if(b[i]>b[g2]) {

			if(b[i]>=b[f2]) {

				g2=f2;f2=i;

			} else {

				g2=i;

			}

		}

	}

	test(f1,f2);

	test(f1,g2);

	test(g1,f2);

	test(g1,g2);

	printf("%d",2*n-ans);

	return 0;

}