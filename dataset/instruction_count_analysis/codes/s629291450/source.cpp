#include<cstdio>

#include<algorithm>

using namespace std;



int main(){

  double pb[100][5001];

  int x,y,z,n,m,l,ub,i,j,k;

  int v[4],e[51],a[51];



  while(scanf("%d %d %d",&x,&y,&z) && (x||y||z)){



    for(i=0;i<x;i++)scanf("%d",&v[i]);

    for(i=0;i<=y;i++)e[i] = a[i] = 0;

    ub = 0;

    for(i=0;i<z;i++){

      scanf("%d %d %d",&n,&m,&l);

      e[n] = m; a[n] = l;

      if(m==2)ub += a[n];

    }



    for(i=0;i<=y;i++)

      for(j=0;j<=ub;j++)pb[i][j] = 0.0;

    pb[0][0] = 1.0;



    for(i=0;i<y;i++)

      for(j=0;j<=ub;j++){

	if(pb[i][j] == 0.0)continue;

	for(k=0;k<x;k++){

	  n = min(y,i+v[k]),m = j;

	  if(e[n] == 1)n = min(y,n+a[n]);

	  else if(e[n] == 2)m = j + a[n];

	  else if(e[n] == 3)m = max(0,j-a[n]);

	  pb[n][m] += pb[i][j]/x;

	}

      }

    



    double ans = 0.0;

    for(i=0;i<=ub;i++)ans += pb[y][i] * i;

    printf("%d\n",(int)ans);

  }

}