#include<cstdio>

#include<algorithm>

#include<cmath>

using namespace std;

int vist[100005];

int Q(int n){

	long long x = 2,ans = 1;

	while(n>0){

		if(n&1)		ans = ans*x%1000000007;

		x = x*x%1000000007;

		n/=2;

	}

	return ans;

}

void Init(int n){

	for(int i = 0; i <= n-1; i++)

		vist[i]	= 0;

}

int main()

{

	int n,m,F;

	while(scanf("%d",&n)!=EOF){

		Init(n);

		F = true;

		for(int i = 0; i < n; i++){

			scanf("%d",&m);

			vist[m]++;		if(m>n-1)	F = false;

		}

		if(n%2!=0){

			for(int i = 0; i <= n-1; i++){

				if(i==0&&vist[i]!=1)		F = false;	

				if(i!=0&&i%2==0&&vist[i]!=2)		F = false;

				if(i%2!=0&&vist[i]!=0)		F = false;	

			}

			if(F){

				int c = Q((n-1)/2);

				printf("%d\n",c%1000000007);

			}

			else	printf("0\n");

		}

		

		else{

			for(int i = 1; i <= n-1; i++){

				if(i%2!=0&&vist[i]!=2)		F = false;

				if(i%2==0&&vist[i]!=0)		F = false;

			}

			if(F){

				int c = Q(n/2);

				printf("%d\n",c%1000000007);

			}

			else	printf("0\n");

		}

	}

	return 0;

}