#include"stdc++.h"

using namespace std;

long long n,k,mod=1e9+7;

struct matrix{

	long long x[100][100];	

}mat;

matrix matrixidentity(long long sz)

{

	matrix res;

	for(int i=0;i<=sz;i++)

	{

		for(int j=0;j<=sz;j++)

		{

			res.x[i][j] = 0;

			if(i==j) res.x[i][j] = 1;

		}

	}

	return res;

}

matrix multiplication(matrix a,matrix b,int sz,long long md)

{

	matrix res;

	for(int i=0;i<sz;i++)

	{

		for(int j=0;j<sz;j++)

		{

			res.x[i][j] = 0;

			for(int k=0;k<sz;k++)

			{

				res.x[i][j]+=(a.x[i][k]%md*b.x[k][j]%md)%md;

				res.x[i][j]%=md;

			}

		}

	}

	return res;

}

matrix matpow(matrix a,long long p,long long md)

{

	matrix res;

	res = matrixidentity(n);

	while(p)

	{

		if(p%2) res = multiplication(res,a,n,md);

		

		a = multiplication(a,a,n,md);

		p/=2;

	}

	

	return res;

}

int main()

{

	scanf("%lld %lld",&n,&k);

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			scanf("%lld",&mat.x[i][j]);

		}

	}

	mat = matpow(mat,k,mod);

	//mat = multiplication(mat,mat,n,mod);

	long long ans = 0;

//	printf("\n");

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			ans+=mat.x[i][j]%mod;

			ans%=mod;

			//printf("%lld ",mat.x[i][j]);

		}

		//printf("\n");

	}

	printf("%lld\n",ans);

	return 0;

}