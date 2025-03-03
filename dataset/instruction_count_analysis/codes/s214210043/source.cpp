/*Lucky_Glass*/

#include<vector>

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



const int N=700;

int n,mod,Nf,Ng;

vector< pair<int,int> > Epr;

int Ef[N+3][N+3];



int main(){

	scanf("%d%d",&n,&mod);

	Nf=2*n-1;Ng=2*n-1;

	for(int i=0;i<2*n;i++){

		while(i*i+Nf*Nf>4*n*n && Nf>=0) Nf--;

		while(i*i+Ng*Ng>=n*n && Ng>=0) Ng--;

		if(i>=n) Epr.push_back(make_pair(Nf+1,0));

		else  Epr.push_back(make_pair(Ng+1,Nf+1));

//		printf("%d %d\n",Epr.back().first,Epr.back().second);

	}

	sort(Epr.begin(),Epr.end());

	int Vans=0;long long typ=1;

	for(int k=0;k<=n;k++){

		memset(Ef,0,sizeof Ef);

		Ef[0][0]=1;

		for(int i=0,Ctf=0,Ctg=0;i<(int)Epr.size();Ctg+=Epr[i].second==0,Ctf+=Epr[i].second!=0,i++){

			for(int j=0;j<=k;j++){

				int tmp=Ef[i][j];

				if(Epr[i].second){

					if(j!=k) Ef[i+1][j+1]=(Ef[i+1][j+1]+1ll*tmp*(Epr[i].first-j-Ctg)%mod)%mod;

					Ef[i+1][j]=(Ef[i+1][j]+1ll*tmp*(Epr[i].second-k-n-(Ctf-j))%mod)%mod;

				}

				else

					Ef[i+1][j]=(Ef[i+1][j]+1ll*tmp*(Epr[i].first-j-Ctg)%mod)%mod;

			}

//			printf("%d %d\n",Ctf,Ctg);

		}

//		printf("%d\n",Ef[Epr.size()][k]);

		Vans=(Vans+typ*Ef[Epr.size()][k]+mod)%mod;

		typ*=-1;

	}

	printf("%d\n",Vans);

	return 0;

}
