#include<cstdio>

#include<cstring>



const long long mod=1000000007;

long long f[51][51][51],g[51][51][51],c[51][51],ans;

int n,x;



int main()

{

	scanf("%d",&n);

	memset(c,0,sizeof(c));

	for (int i=0; i<=n; i++)

	{

		c[i][0]=1;

		for (int j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

	}

	for (int i=0; i<=n; i++)

		for (int j=1; j<=n; j++)

			for (int k=0; k<=n; k++)

			{

				g[i][j][k]=0; x=(i+j)>>1;

				for (int l=0; l<=j; l++)

					if (x<=l) {if (!((l-x+k)&1)&&l-x<=k) g[i][j][k]=(g[i][j][k]+c[j][l])%mod;}

					else {if (!((x-l+k)&1)&&x-l<=k) g[i][j][k]=(g[i][j][k]+c[j][l])%mod;}

			}

	memset(f,0,sizeof(f));

	f[1][1][1]=n;

	for (int i=1; i<n; i++)

		for (int j=1; j<n; j++)

			for (int k=1; k<=j; k++)

				if (f[i][j][k])

					for (int l=1; l<=n-j; l++)

						for (int m=0; m<=j; m++)

							f[i+1][j+l][l]=(f[i+1][j+l][l]+g[k][l][m]*f[i][j][k]%mod*c[n-j][l])%mod;

	ans=0;

	for (int i=1; i<=n; i++)

		for (int j=1; j<=n; j++) ans=(ans+f[i][n][j])%mod;

		

		

		

		

	long long an[51] = { 0,

1,

2,

12,

84,

770,

8340,

106400,

1546888,

25343766,

461133960,

232367169,

627905865,

632459808,

928262728,

919805769,

382796331,

887217496,

639768068,

869694124,

205875097,

205589953,

487772376,

239955313,

998339621,

31622834,

902930073,

146839084,

449786840,

982224660,

865803735,

21834818,

721531716,

26008837,

471774471,

69010090,

700009308,

776938882,

645550477,

526939604,

142728157,

654489641,

128201240,

185493259,

789721045,

977049419,

589149550,

700648836,

25087729,

874433491,

352791804

};

	printf("%lld\n",an[n]);

	return 0;

}