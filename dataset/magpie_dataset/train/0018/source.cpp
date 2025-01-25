#include<cstdio>

#include<iostream>

#include<vector>

#include<string>

#include<deque>

#include<map>

#include<algorithm>



using namespace std;



int masu[14][14];

int cont;



void saiki(int x,int y){

	masu[x][y]=0;

	if(masu[x+1][y]==1)

	saiki(x+1,y);

	if(masu[x][y+1]==1)

	saiki(x,y+1);

	if(masu[x-1][y]==1)

	saiki(x,y-1);

	if(masu[x][y-1]==1)

	saiki(x,y-1);

}



int main(){

	while(1){

		for(int i=0;i<14;i++){

			for(int j=0;j<14;j++){

				masu[i][j]=0;

			}

		}

		for(int i=1;i<=12;i++){

			char st[13];

			if(scanf("%s",st)==EOF){

				goto A;

			}

			for(int j=0;j<12;j++){

				if(st[j]=='0'){

					masu[i][j+1]=0;

				}else{

					masu[i][j+1]=1;

				}

			}

		}

		cont=0;

		for(int i=1;i<=12;i++){

			for(int j=1;j<=12;j++){

				if(masu[i][j]==1){

					cont++;

					saiki(i,j);

				}

			}

		}

		printf("%d\n",cont);

	}

	A:;

}