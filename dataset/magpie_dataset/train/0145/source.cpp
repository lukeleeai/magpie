#include <stdio.h>

//#include <windows.h>



int masu[100][100],mx,ice[100][100],n,m;



/**

void print()

{

	system("cls");

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++){

			printf("%d ",masu[i][j]);

		}

		puts("");

	}

}

/**/



void func(int x,int y,int now)

{

//	printf("%d",now);

//	print();

	

	if(masu[x+1][y]==1){

		masu[x][y]=0;

		func(x+1,y,now+1);

		masu[x][y]=1;

	}

	if(masu[x-1][y]==1){

		masu[x][y]=0;

		func(x-1,y,now+1);

		masu[x][y]=1;

	}

	if(masu[x][y+1]==1){

		masu[x][y]=0;

		func(x,y+1,now+1);

		masu[x][y]=1;

	}

	if(masu[x][y-1]==1){

		masu[x][y]=0;

		func(x,y-1,now+1);

		masu[x][y]=1;

	}

	else {

		if(mx<now){

			mx=now;

		}

	}

}



void func2()

{

	int i,j;

	for(i=1;i<=n;i++){

		for(j=1;j<=m;j++){

			masu[i][j]=ice[i][j];

		}

	}

}



int main(void)

{

	int i,j;

	

	while(scanf("%d%d",&m,&n),n,m){

		for(i=1;i<=n;i++){

			for(j=1;j<=m;j++){

				scanf("%d",&ice[i][j]);

			}

		}

		for(i=1;i<=n;i++){

			for(j=1;j<=m;j++){

				func2();

				if(masu[i][j]==1){

					func(i,j,1);

				}

			}

		}

		for(i=0;i<100;i++){

			for(j=0;j<100;j++){

				ice[i][j]=0;

				masu[i][j]=0;

			}

		}

		printf("%d\n",mx);

		n=0;

		m=0;

		mx=0;

	}

	

	return 0;

}