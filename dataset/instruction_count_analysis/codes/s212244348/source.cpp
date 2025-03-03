#include<cstdio>

#include<cmath>

int n,m,l,p[100],t[100],v[100];

double time[100][51],poss[100][51],c[2][51],ans,sum[100][51];

int main(){

        scanf("%d%d%d",&n,&m,&l);

        c[0][0]=1;

        for (int i=1;i<=m;i++){

                c[i%2][0]=c[i%2][i]=1;

		for (int j=1;j<i;j++) c[i%2][j]=c[(i+1)%2][j-1]+c[(i+1)%2][j];

        }

        for (int i=0;i<n;i++){

                scanf("%d%d%d",&p[i],&t[i],&v[i]);

                time[i][0]=(double)l/v[i];

                for (int j=1;j<=m;j++) time[i][j]=time[i][j-1]+t[i];

                for (int j=0;j<=m;j++) poss[i][j]=c[m%2][j]*pow((double)p[i]/100,j)*pow(1-(double)p[i]/100,m-j);

		sum[i][m]=poss[i][m];

		for (int j=m-1;j>=0;j--) sum[i][j]=sum[i][j+1]+poss[i][j];

        }

	for (int i=0;i<n;i++){

		ans=0;

		for (int j=0;j<=m;j++){

			double cur=1,cur_t=time[i][j];

			for (int k=0;k<n;k++) if (i!=k){

				int l=0,r=m,mid,res;

				while (l<=r){

					mid=l+r>>1;

					if (time[k][mid]>cur_t){

						res=mid;

						r=mid-1;

					}	

					else l=mid+1; 

				}

				if (time[k][res]>cur_t) cur*=sum[k][res];

				else cur=0;

			}

			ans+=cur*poss[i][j];

		}

		printf("%f\n",ans);

	}

	return 0;

}