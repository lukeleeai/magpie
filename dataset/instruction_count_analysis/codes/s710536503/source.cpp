#include<cstdio>

using namespace std;

int a[1001][1001],b[1001][1001],c[1001][1001];

int main(){

  int i,j;

  int m,n,k;

  scanf("%d%d%d",&m,&n,&k);

  for(i=0;i<m;++i){

    a[i][0]=b[i][0]=c[i][0]=0;

    char p[1001];

    scanf("%s",p);

    for(j=0;p[j];++j){

      if(false){

      }else if(p[j]=='J'){

	a[i][j+1]=a[i][j]+1;

	b[i][j+1]=b[i][j];

	c[i][j+1]=c[i][j];

      }else if(p[j]=='O'){

	a[i][j+1]=a[i][j];

	b[i][j+1]=b[i][j]+1;

	c[i][j+1]=c[i][j];

      }else if(p[j]=='I'){

	a[i][j+1]=a[i][j];

	b[i][j+1]=b[i][j];

	c[i][j+1]=c[i][j]+1;

      }

    }

  }

  for(i=0;i<k;++i){

    int p,q,r,s;

    scanf("%d%d%d%d",&p,&q,&r,&s);

    --p;

    --q;

    int d=0,e=0,f=0;

    for(j=p;j<r;++j){

      d+=a[j][s]-a[j][q];

      e+=b[j][s]-b[j][q];

      f+=c[j][s]-c[j][q];

    }

    printf("%d %d %d\n",d,e,f);

  }

  return 0;

}