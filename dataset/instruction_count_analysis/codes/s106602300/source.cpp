#include<cstdio>

#include<cstring>

#include<algorithm>

const int MAXN=110;

long long w[5][MAXN],tot[5],base;



int main(){

	long long n,c;scanf("%lld%lld",&n,&c);

	for(int i=1;i<=n;i++){

		int x,v;scanf("%d%d",&x,&v);

		if(i==1)

			base=x;

		w[x-base][++tot[x-base]]=-v;

	}

	std::sort(w[0]+1,w[0]+tot[0]+1);

	std::sort(w[1]+1,w[1]+tot[1]+1);

	std::sort(w[2]+1,w[2]+tot[2]+1);

	std::sort(w[3]+1,w[3]+tot[3]+1);

	for(int i=0;i<4;i++)

		for(int j=1;j<=n;j++)

			w[i][j]+=w[i][j-1];

	long long ans=1;

	for(int i=0;i<=tot[0];i++)

		for(int j=0;j<=tot[1];j++)

			for(int k=0;k<=tot[2];k++)

				for(int l=0;l<=tot[3];l++){

					if(i*base+j*(base+1ll)+k*(base+2ll)+l*(base+3ll)>c)

						continue;

					ans=std::min(ans,(long long)w[0][i]+w[1][j]+w[2][k]+w[3][l]);

				}

	printf("%lld\n",-ans);

	return 0;

}