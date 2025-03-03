#include<cstdio>

#include<algorithm>

using namespace std;



int main(){

  int n,m,a,b,cost,time,k,p,q,r;

  int t[100][100],c[100][100];



  for(;;){

    scanf("%d %d",&n,&m);

    if(!n && !m)break;



    for(int i=0;i<m;i++){

      for(int j=0;j<m;j++){

	if(i==j){

	  t[i][j] = 0;

	  c[i][j] = 0;

	}else{

	  t[i][j] = 1000000;

	  c[i][j] = 1000000;

	}

      }

    }



    for(int i=0;i<n;i++){

      scanf("%d %d %d %d",&a,&b,&cost,&time);

      t[a-1][b-1] = time;

      t[b-1][a-1] = time;

      c[a-1][b-1] = cost;

      c[b-1][a-1] = cost;

    }



    for(int x=0;x<m;x++){

      for(int i=0;i<m;i++){

	for(int j=0;j<m;j++){

	  t[i][j] = min(t[i][j],t[i][x] + t[x][j]);

	  c[i][j] = min(c[i][j],c[i][x] + c[x][j]);

	}

      }

    }



    scanf("%d",&k);

    for(int i=0;i<k;i++){

      scanf("%d %d %d",&p,&q,&r);

      if(r)printf("%d\n",t[p-1][q-1]);

      else printf("%d\n",c[p-1][q-1]);

    }

  }

}