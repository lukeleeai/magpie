#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>



using namespace std;



int n;

int fie[101][101][101];

int high[101][101];

int t[101],f[101];

int cnt[7];

int b[6];



void dicemake(){

	if(b[0]==1 && b[2]==2)b[4]=3;

	if(b[0]==1 && b[2]==3)b[4]=5;

	if(b[0]==1 && b[2]==4)b[4]=2;

	if(b[0]==1 && b[2]==5)b[4]=4;

	if(b[0]==2 && b[2]==1)b[4]=4;

	if(b[0]==2 && b[2]==3)b[4]=1;

	if(b[0]==2 && b[2]==4)b[4]=6;

	if(b[0]==2 && b[2]==6)b[4]=3;

	if(b[0]==3 && b[2]==1)b[4]=2;

	if(b[0]==3 && b[2]==2)b[4]=6;

	if(b[0]==3 && b[2]==5)b[4]=1;

	if(b[0]==3 && b[2]==6)b[4]=5;

	if(b[0]==4 && b[2]==1)b[4]=5;

	if(b[0]==4 && b[2]==2)b[4]=1;

	if(b[0]==4 && b[2]==5)b[4]=6;

	if(b[0]==4 && b[2]==6)b[4]=2;

	if(b[0]==5 && b[2]==1)b[4]=3;

	if(b[0]==5 && b[2]==3)b[4]=6;

	if(b[0]==5 && b[2]==4)b[4]=1;

	if(b[0]==5 && b[2]==6)b[4]=4;

	if(b[0]==6 && b[2]==2)b[4]=4;

	if(b[0]==6 && b[2]==3)b[4]=2;

	if(b[0]==6 && b[2]==4)b[4]=5;

	if(b[0]==6 && b[2]==5)b[4]=3;

	b[5]=7-b[4];

}



void drop(int c){

	int x=50,y=50;

	b[0]=t[c];

	b[1]=(7-t[c]);

	b[2]=f[c];

	b[3]=(7-f[c]);

	dicemake();

	bool done=false;

	while(1){

		done=false;

		if(high[x][y]==0){

			fie[x][y][high[x][y]]=b[0];

			high[x][y]++;

			//printf("%d %d %d %d\n",c,x,y,high[x][y]);

			return;

		}

		if(b[2]==6){

			if(high[x][y]>high[x][y+1] && !done){

				y++;

				int lll=b[0];

				b[0]=b[3];

				b[3]=b[1];

				b[1]=b[2];

				b[2]=lll;

				done=true;

			}

		}

		if(b[4]==6){

			if(high[x][y]>high[x+1][y] && !done){

				x++;

				int lll=b[0];

				b[0]=b[5];

				b[5]=b[1];

				b[1]=b[4];

				b[4]=lll;

				done=true;

			}

		}

		if(b[3]==6){

			if(high[x][y]>high[x][y-1] && !done){

				y--;

				int lll=b[0];

				b[0]=b[2];

				b[2]=b[1];

				b[1]=b[3];

				b[3]=lll;

				done=true;

			}

		}

		if(b[5]==6){

			if(high[x][y]>high[x-1][y] && !done){

				x--;

				int lll=b[0];

				b[0]=b[4];

				b[4]=b[1];

				b[1]=b[5];

				b[5]=lll;

				done=true;

			}

		}

		if(b[2]==5){

			if(high[x][y]>high[x][y+1] && !done){

				y++;

				int lll=b[0];

				b[0]=b[3];

				b[3]=b[1];

				b[1]=b[2];

				b[2]=lll;

				done=true;

			}

		}

		if(b[4]==5){

			if(high[x][y]>high[x+1][y] && !done){

				x++;

				int lll=b[0];

				b[0]=b[5];

				b[5]=b[1];

				b[1]=b[4];

				b[4]=lll;

				done=true;

			}

		}

		if(b[3]==5){

			if(high[x][y]>high[x][y-1] && !done){

				y--;

				int lll=b[0];

				b[0]=b[2];

				b[2]=b[1];

				b[1]=b[3];

				b[3]=lll;

				done=true;

			}

		}

		if(b[5]==5){

			if(high[x][y]>high[x-1][y] && !done){

				x--;

				int lll=b[0];

				b[0]=b[4];

				b[4]=b[1];

				b[1]=b[5];

				b[5]=lll;

				done=true;

			}

		}

		if(b[2]==4){

			if(high[x][y]>high[x][y+1] && !done){

				y++;

				int lll=b[0];

				b[0]=b[3];

				b[3]=b[1];

				b[1]=b[2];

				b[2]=lll;

				done=true;

			}

		}

		if(b[4]==4){

			if(high[x][y]>high[x+1][y] && !done){

				x++;

				int lll=b[0];

				b[0]=b[5];

				b[5]=b[1];

				b[1]=b[4];

				b[4]=lll;

				done=true;

			}

		}

		if(b[3]==4){

			if(high[x][y]>high[x][y-1] && !done){

				y--;

				int lll=b[0];

				b[0]=b[2];

				b[2]=b[1];

				b[1]=b[3];

				b[3]=lll;

				done=true;

			}

		}

		if(b[5]==4){

			if(high[x][y]>high[x-1][y] && !done){

				x--;

				int lll=b[0];

				b[0]=b[4];

				b[4]=b[1];

				b[1]=b[5];

				b[5]=lll;

				done=true;

			}

		}

		if(!done){

			fie[x][y][high[x][y]]=b[0];

			high[x][y]++;

			//printf("%d %d %d %d\n",c,x,y,high[x][y]);

			return;

		}

	}

}



int main(void){

	while(1){

		scanf("%d",&n);

		if(n==0)break;

		for(int i=0;i<n;i++)scanf("%d%d",&t[i],&f[i]);

		memset(fie,0,sizeof(fie));

		memset(high,0,sizeof(high));

		memset(cnt,0,sizeof(cnt));

		for(int i=0;i<n;i++)drop(i);

		for(int i=0;i<=100;i++){

			for(int j=0;j<=100;j++){

				if(high[i][j]>0)cnt[fie[i][j][high[i][j]-1]]++;

			}

		}

		for(int i=1;i<=6;i++)printf("%d%c",cnt[i],i==6?'\n':' ');

	}

	return 0;

}