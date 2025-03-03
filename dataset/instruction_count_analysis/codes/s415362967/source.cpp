#include<cstdio>

#define IN 150

using namespace std;



int n,u,f,y,x;

int h[300][300],d[300][300],res[7];

int dice[6],tmp[6];

int dy[] = {0,1,-1,0}, dx[] = {-1,0,0,1}; //w,s,n,e

 

int rot[4][6] = { {4,0,2,3,5,1},

		  {3,1,0,5,4,2},

		  {2,1,5,0,4,3},

		  {1,5,2,3,0,4} };



int die[6][6] = { {0,2,4,1,3,0},

		 {3,0,0,5,0,2},

		 {1,5,0,0,0,4},

		 {4,0,0,0,5,1},

		 {2,0,5,0,0,3},

		 {0,3,1,4,2,0} };



int main(){

  while(scanf("%d",&n),n){

    for(int i=0;i<300;i++)

      for(int j=0;j<300;j++)h[i][j] = d[i][j] = -1;



    while(n--){

      scanf("%d %d",&u,&f);

      u--; f--;

      dice[0] = u; dice[5] = 5-u;

      dice[1] = f; dice[4] = 5-f;

      dice[2] = die[u][f]; dice[3] = 5 - die[u][f];

      

      f = true;

      y = x = IN;

      while(f){

	f = false;

	for(int i=5;i>=3;i--){

	  for(int j=0;j<4;j++){

	    if(dice[j+1] == i){

	      if(h[y][x] > h[y+dy[j]][x+dx[j]]){

		y = y+dy[j]; x = x+dx[j];

		for(int k=0;k<6;k++)tmp[k] = dice[rot[j][k]];

		for(int k=0;k<6;k++)dice[k] = tmp[k];

		f = true;

		break;

	      }

	    }

	  }

	  if(f)break;

	}

      } 

      h[y][x]++; d[y][x] = dice[0];

    }

    

    for(int i=0;i<7;i++)res[i] = 0;

    for(int i=0;i<300;i++)

      for(int j=0;j<300;j++)res[d[i][j]+1]++;

    for(int i=1;i<6;i++)printf("%d ",res[i]);

    printf("%d\n",res[6]);

  }

}