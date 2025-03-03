#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define cmax(_i,_j) ((_i)<(_j)?(_i)=(_j):0)

#define cmin(_i,_j) ((_i)>(_j)?(_i)=(_j):0)

#define N 20005

using namespace std;

namespace runzhe2000

{

	int n, p[N], a[N], b[N], pa[N], pb[N];

	void main()

	{

		scanf("%d",&n);

		for(int i = 1; i <= n; i++) 

		{

			scanf("%d",&p[i]), a[i] = i, b[i] = n-i+1;

			

			int v = i;

			

			pa[p[i]] += v; pa[n+1] -= v;

			pb[1] += v; pb[p[i]+1] -= v;

		}

		for(int i = 1, tmp = 0; i <= n; i++) tmp += pa[i], a[i] += tmp;

		for(int i = 1, tmp = 0; i <= n; i++) tmp += pb[i], b[i] += tmp;

		

		for(int i = 1; i <= n; i++) 

		{	

			printf("%d ",a[i]); 

		}	

		puts("");

		for(int i = 1; i <= n; i++) 

		{

			printf("%d ",b[i]); 

		}

		puts("");

//for(int i = 1; i < n; i++) if(a[p[i]]+b[p[i]] >= a[p[i+1]]+b[p[i+1]]) {for(;;);}

		

	}

}

int main()

{

	runzhe2000::main();

}