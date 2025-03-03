#include<cstdio>

#include<iostream>



#define INF 2100000000



using namespace std;



int minix(int a,int b,int c){

	if(b>=a && c>=a){

		return a;

	}

	if(a>=b && c>=b){

		return b;

	}

	if(b>=c && a>=c){

		return c;

	}

}



int main(){

	int n;

	int masu[1002][1002];

	int ura[1002][1002];

	char str[1002];

	while(1){

		scanf("%d",&n);

		if(n==0){

			break;

		}

		for(int i=1;i<=n;i++){

			scanf("%s",str);

			for(int j=1;j<=n;j++){

				if(str[j-1]=='.'){

					ura[i][j]=0;

				}else{

					ura[i][j]=1;

				}

			}

		}

		for(int i=0;i<=n;i++){

			masu[i][0]=masu[0][i]=0;

		}

		int maxi=0;

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++){

				if(ura[i][j]==0){

					masu[i][j]=minix(masu[i-1][j],masu[i][j-1],masu[i-1][j-1])+1;

					maxi=max(masu[i][j],maxi);

				}else{

					masu[i][j]=0;

				}

			}

		}

		

		printf("%d\n",maxi);

	}

}