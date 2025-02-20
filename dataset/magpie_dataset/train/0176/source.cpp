#include<iostream>

using namespace std;

int a[1001][1001],b[1001][1001],c[1001][1001];

int main(){

  int i,j;

  int m,n;

  cin>>m>>n;

  int k;

  cin>>k;

  for(i=0;i<m;++i){

    a[i][0]=b[i][0]=c[i][0]=0;

    for(j=0;j<n;++j){

      char p;

      cin>>p;

      if(false){

      }else if(p=='J'){

	a[i][j+1]=a[i][j]+1;

	b[i][j+1]=b[i][j];

	c[i][j+1]=c[i][j];

      }else if(p=='O'){

	a[i][j+1]=a[i][j];

	b[i][j+1]=b[i][j]+1;

	c[i][j+1]=c[i][j];

      }else if(p=='I'){

	a[i][j+1]=a[i][j];

	b[i][j+1]=b[i][j];

	c[i][j+1]=c[i][j]+1;

      }

    }

  }

  for(i=0;i<k;++i){

    int p,q,r,s;

    cin>>p>>q>>r>>s;

    --p;

    --q;

    int d=0,e=0,f=0;

    for(j=p;j<r;++j){

      d+=a[j][s]-a[j][q];

      e+=b[j][s]-b[j][q];

      f+=c[j][s]-c[j][q];

    }

    cout<<d<<' '<<e<<' '<<f<<endl;

  }

  return 0;

}